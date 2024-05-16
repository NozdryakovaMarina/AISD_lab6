#pragma once

#include <iostream>
#include <stdexcept> 
#include <vector>

using namespace std;

namespace graph {

	template<typename Vertex, typename Distance = double>
	class Graph {
	public:

		struct Edge {
			Vertex _from;
			Vertex _to;
			Distance _data;

			Edge() : _from(Vertex()), _to(Vertex()), _data(0) {}
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
			auto ind = find(_edges.begin(), _edges.end(), e);
			if (ind != _edges.end()) {
				_edges.erase(ind);
				return true;
			}
			return false;
		}

		bool remove_vertex(const Vertex& v) {
			if (!has_vertices(v)) return false;

			auto ind = find(_vertices.begin(), _vertices.end(), v);
			if (ind != _vertices.end()) {
				_vertices.erase(ind);
				for (int i = 0; i < _edges.size(); i++) {
					if (_edges[i]._from || _edges[i]._to)
						remove_edge(_edges[i]);
					i--;
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
	private:
		vector<Vertex> _vertices;
		vector<Edge> _edges;
	};

}