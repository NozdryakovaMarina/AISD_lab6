#pragma once

#include <iostream>
#include <stdexcept> 
#include <vector>

using namespace std;

namespace graph {

	template<typename Vertex, typename Distance = double>
	class Graph {
	private:
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
	
		vector<Vertex> _vertices;
		vector<Edge> _edge;
	public:
		Graph(): _vertices(vector<Vertex>()), _edge(vector<Edge>()){}

		void print_edges() const { 
			for (auto& e : _edge) {
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
			auto ind = find(_edge.begin(), _edge.end(), e);
			if (ind != _edge.end()) {
				_edge.erase(ind);
				return true;
			}
			return false;
		}

		bool remove_vertex(const Vertex& v) {
			if (!has_vertices(v)) return false;

			auto ind = find(_vertices.begin(), _vertices.end(), v);
			if (ind != _vertices.end()) {
				_vertices.erase(ind);
				for (int i = 0; i < _edge.size(); i++) {
					if (_edge[i]._from || _edge[i]._to)
						remove_edge(_edge[i]);
					i--;
				}
				return true;
			}
			return false;
		}

		std::vector<Vertex> vertices() const {
			return _vertices;
		}

	};

}