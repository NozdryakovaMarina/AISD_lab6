#pragma once

#include <iostream>
#include <stdexcept>
#include <random>
#include <functional>

using namespace std;

namespace graph {
	template<typename Vertex, typename Distance = double>
	struct Edge {
		Vertex from;
		Vertex to;
		Distance data;

		Edge() : from(Vertex()), to(Vertex()), data(0) {}
		Edge(Vertex f, Vertex t) : from(f), to(t), data(0) {}
		Edge(Vertex f, Vertex t, Distance d) : from(f), to(t), data(d) {}

		void print() {
			cout << "From the vertex: " << from << " | To the vertex: " << to << " | Distance: " << data << endl;
		}
	};
	template<typename Vertex, typename Distance = double>
	class Graph {
	private:
	};
}