#pragma once

#include <iostream>
#include <stdexcept> 
#include <vector>
#include <functional>
#include <unordered_map>
#include <stack>

using namespace std;

constexpr int INFIN = numeric_limits<int>::max();

namespace graph {

	template<typename Vertex, typename Distance = double>
	class Graph {
	public:

		struct Edge {
			Vertex _from;
			Vertex _to;
			Distance _data;

			Edge(Vertex f, Vertex t) : _from(f), _to(t), _data(0) {}
			Edge(Vertex f, Vertex t, Distance d) : _from(f), _to(t), _data(d) {}

			void print() {
				cout << "From the vertex: " << _from << " | To the vertex: " << _to << " | Distance: " << _data << endl;
			}

			bool operator==(const Edge& other) const {
				return _from == other._from && _to == other._to && _data == other._data;
			}
		};

		Graph() : _vertices(vector<Vertex>()), _edges(vector<Edge>()) {}

		void print_edges() const { 
			for (auto& e : _edges) {
				e.print();
			}
		}

		bool has_vertices(const Vertex& v) const {
			return find(_vertices.begin(), _vertices.end(), v) != _vertices.end();
		}

		void add_vertices(const Vertex& v) {
			if (has_vertices(v)) 
				throw std::invalid_argument("The vertex already exists");
			_vertices.push_back(v);
		}

		bool remove_edge(const Edge& e) {
			if (!has_edge(e)) return false;
			for (int i = 0; i < _edges.size(); i++) {
				if (_edges[i]._from == e._from && _edges[i]._to == e._to && _edges[i]._data == e._data)
					_edges.erase(_edges.begin() + i);
				return true;
			}
			return false;
		}

		bool remove_vertex(const Vertex& v) {
			if (!has_vertices(v)) return false;

			auto ind = find(_vertices.begin(), _vertices.end(), v);
			if (ind != _vertices.end()) {
				_vertices.erase(ind);
				for (auto& vertex : _vertices) {
					auto& edges = _edges;
					edges.erase(remove_if(edges.begin(), edges.end(), [v](const Edge& e) {return e._to == v || e._from == v; }), edges.end());
				}
				return true;
			}
			return false;
		}

		std::vector<Vertex> vertices() const {
			return _vertices;
		}

		bool has_edge(const Vertex& from, const Vertex& to) const {
			for (const auto& e: _edges) {
				if (e._from == from && e._to == to) return true;
			}
			return false;
		}

		bool has_edge(const Edge& e) const {
			for (const auto& edge : _edges) {
				if (edge._from == e._from && edge._to == e._to && edge._data == e._data) return true;
			}
			return false;
		}

		void add_edge(const Vertex& from, const Vertex& to, const Distance& d) {
			if (!has_vertices(from) || !has_vertices(to)) return;

			Edge e(from, to, d);
			if (!has_edge(e)) _edges.push_back(e);
		}

		bool remove_edge(const Vertex& from, const Vertex& to) {
			if (!has_edge(from, to)) return false;
	
			_edges.erase(remove_if(_edges.begin(), _edges.end(), [&](Edge& e) { return (e._from == from) && (e._to == to); }), _edges.end());

            return false;
		}

		std::vector<Edge> edges(const Vertex& vertex) {
			vector<Edge> result;
			for (auto& edge : _edges) {
				if (edge._from == vertex) {
					result.push_back(edge);
				}
			}
			return result;
		}

		size_t order() const {
			return _vertices.size();
		}

		size_t degree(const Vertex& v) const {
			size_t deg = 0;
			for (auto& edge : _edges) {
				if (edge._from == v) {
					deg++;
				}
			}
			return deg;
		}

		void walk(const Vertex& start_vertex, std::function<void(const Vertex&)> action) const {
			if (!has_vertices(start_vertex))
				throw std::invalid_argument("The vertex was not found");
			unordered_map<Vertex, bool> visited;
			unordered_map<Vertex, size_t> dist;
			stack<Vertex> stack;
			dist[start_vertex] = 0;
			stack.push(start_vertex);
			visited[start_vertex] = true;
			action(start_vertex);
			while (!stack.empty()) {
				Vertex tmp = stack.top();
				stack.pop();
				for (const auto& edge : _edges) {
					if (!visited[edge._to]) {
						stack.push(edge._to);
						visited[edge._to] = true;
						dist[edge._to] = dist[tmp] + 1;
						action(edge._to);
					}
				}
			}
		}

		std::vector<Edge> shortest_path(const Vertex& from, const Vertex& to) const {
			if (!has_vertices(from) || !has_vertices(to)) return {};

			unordered_map<Vertex, Distance> distances;
			unordered_map<Vertex, Vertex> prev;

			for (const auto& vertex : _vertices) distances[vertex] = INFIN;
			distances[from] = 0;
			 
			for (size_t i = 0; i < _vertices.size() - 1; ++i) {
				for (const auto& edge : _edges) {
					if (distances[edge._from] + edge._data < distances[edge._to]) {
						distances[edge._to] = distances[edge._from] + edge._data;
						prev[edge._to] = edge._from;
					}
				}
			}

			for (const auto& edge : _edges) {
				if (distances[edge._from] + edge._data < distances[edge._to]) {
					throw runtime_error("A negative cycle has been detected. It is impossible to find the shortest path(");
				}
			}

			vector<Edge> path;
			Vertex tmp = to;
			while (tmp != from) {
				for (const auto& edge : _edges) {
					if (edge._to == tmp && prev[tmp] == edge._from) {
						path.push_back(edge);
						prev[tmp] = edge._from;
						break;
					}
				}
				tmp = prev[tmp];
			}
			reverse(path.begin(), path.end());

			return path;
		}

	private:
		vector<Vertex> _vertices;
		vector<Edge> _edges;
	};

}