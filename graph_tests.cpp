#include <gtest/gtest.h>
#include "graph_list.cpp"
#include <stdexcept>

using namespace graph;
using namespace std;

TEST(GraphTest, VerticesTest) {
	Graph<int> g;
	g.add_vertices(6);
	g.add_vertices(100);
	g.add_vertices(57);

	EXPECT_TRUE(g.has_vertices(6));
	EXPECT_TRUE(g.has_vertices(100));
	EXPECT_TRUE(g.has_vertices(57)); 
}

TEST(GraphTest, VerticesTest2) {
	Graph<int> g;
	g.add_vertices(6);
	g.add_vertices(100);
	g.add_vertices(57); 

	EXPECT_FALSE(g.has_vertices(-24));
	EXPECT_FALSE(g.has_vertices(0));
	EXPECT_FALSE(g.has_vertices(465));
}

TEST(GraphTest, VerticesTest3) {
	Graph<int> g;
	g.add_vertices(6);
	g.add_vertices(100);
	g.add_vertices(57);

	g.remove_vertex(100);
	g.remove_vertex(6);

	EXPECT_FALSE(g.has_vertices(6));
	EXPECT_FALSE(g.has_vertices(100));
	EXPECT_TRUE(g.has_vertices(57));
}

TEST(GraphTest, EdgesTest) {
	Graph<int> g; 

	g.add_vertices(6);
	g.add_vertices(100);
	g.add_vertices(14);
	g.add_vertices(57);

	g.add_edge(6, 14, 5);
	g.add_edge(14, 57, 9);
	g.add_edge(100, 6, 8);
	g.add_edge(57, 100, 1);
	 
	EXPECT_TRUE(g.has_edge(6, 14));
	EXPECT_TRUE(g.has_edge(14, 57));
	EXPECT_TRUE(g.has_edge(100, 6));
	EXPECT_TRUE(g.has_edge(57, 100));

	EXPECT_FALSE(g.has_edge(14, 100));
	EXPECT_FALSE(g.has_edge(100, 1));
	EXPECT_FALSE(g.has_edge(7, 0));
}

TEST(GraphTest, EdgesTest2) {
	Graph<int> g;

	g.add_vertices(6);
	g.add_vertices(100);
	g.add_vertices(14);
	g.add_vertices(57);

	g.add_edge(6, 14, 5);
	g.add_edge(14, 57, 9);
	g.add_edge(100, 6, 8);
	g.add_edge(57, 100, 1);

	g.remove_edge(6, 14);
	g.remove_edge(14, 57);
	g.remove_edge(100, 6);

	EXPECT_FALSE(g.has_edge(6, 14));
	EXPECT_FALSE(g.has_edge(100, 6));

	EXPECT_TRUE(g.has_edge(57, 100));
	EXPECT_FALSE(g.has_edge(14, 57));
}

TEST(GraphTest, EdgesTest3) {
	Graph<int> g;

	g.add_vertices(6);
	g.add_vertices(100);
	g.add_vertices(14);
	g.add_vertices(57);

	g.add_edge(6, 14, 5);
	g.add_edge(14, 57, 9);
	g.add_edge(100, 6, 8);
	g.add_edge(57, 100, 1);

	g.remove_vertex(57);

	EXPECT_FALSE(g.has_edge(14, 57));  
	EXPECT_FALSE(g.has_edge(57, 100));

	EXPECT_TRUE(g.has_edge(6, 14));
	EXPECT_TRUE(g.has_edge(100, 6));
}

TEST(GraphTest, WalkTest) {
	Graph<int> g;

	g.add_vertices(6);
	g.add_vertices(100);
	g.add_vertices(14);
	g.add_vertices(57);
	g.add_vertices(3);
	g.add_vertices(222);
	g.add_vertices(1);

	g.add_edge(6, 14, 5);
	g.add_edge(6, 100, 8);
	g.add_edge(14, 3, 48);
	g.add_edge(14, 57, 9);
	g.add_edge(57, 1, 45);
	g.add_edge(100, 222, 7);

	auto action = [](int vertex) {
		std::cout << "Visited vertex: " << vertex << std::endl;
	};

	try {
		g.walk(6, action);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

TEST(GraphTest, WalkTest2) {
	Graph<int, int> g;
	g.add_vertices(1);
	g.add_vertices(2);
	g.add_vertices(3);
	g.add_vertices(4);
	g.add_vertices(5);

	g.add_edge(1, 2, 5);
	g.add_edge(2, 4, 15);
	g.add_edge(2, 5, 1);
	g.add_edge(1, 3, 20);

	auto action = [](int vertex) {
		std::cout << "Visited vertex: " << vertex << std::endl;
	};

	try {
		g.walk(1, action);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

TEST(GraphTest, OrderTest) {
	Graph<int, int> g;
	g.add_vertices(1);
	g.add_vertices(2);
	g.add_vertices(3);
	g.add_vertices(4);
	g.add_vertices(5);

	g.add_edge(1, 2, 5);
	g.add_edge(2, 4, 15);
	g.add_edge(2, 5, 1);
	g.add_edge(1, 3, 20);

	cout << g.order() << endl;
}

TEST(GraphTest, DegreeTest) {
	Graph<int, int> g;
	g.add_vertices(1);
	g.add_vertices(2);
	g.add_vertices(3);
	g.add_vertices(4);
	g.add_vertices(5);

	g.add_edge(1, 2, 5);
	g.add_edge(2, 4, 15);
	g.add_edge(2, 5, 1);
	g.add_edge(1, 3, 20);

	cout << g.degree(2) << endl;
}

TEST(GraphTest, DijkstraTest) {
	Graph<int> g;

	g.add_vertices(6);
	g.add_vertices(100);
	g.add_vertices(14);
	g.add_vertices(57);
	g.add_vertices(3);
	g.add_vertices(222);
	g.add_vertices(1);

	g.add_edge(6, 14, 5);
	g.add_edge(14, 3, 48);
	g.add_edge(14, 57, 9);
	g.add_edge(57, 1, 45);
	g.add_edge(6, 100, 8);
	g.add_edge(100, 222, 7);
	g.add_edge(100, 3, 2);
	g.add_edge(222, 57, 1);
	 
	auto path = g.shortest_path(6, 3);
	cout << "Shortest path: " << endl;
	for (const auto& edge : path) {
		cout << edge._from << " -> " << edge._to << "-> |" << edge._data << "| " << endl;
	}
}

TEST(GraphTest, DijkstraTest2) {
	Graph<int, int> g;
	g.add_vertices(1);
	g.add_vertices(2);
	g.add_vertices(3);
	g.add_vertices(4);
	g.add_vertices(5);

	g.add_edge(1, 2, 5);
	g.add_edge(2, 4, -15);
	g.add_edge(2, 5, 1);
	g.add_edge(1, 3, -20);
	g.add_edge(5, 4, 2);

	EXPECT_ANY_THROW(g.shortest_path(1, 4));
}

TEST(GraphTest, DistanceTest) {
	Graph<int, int> g;

	g.add_vertices(1);
	g.add_vertices(2);
	g.add_vertices(3);
	g.add_vertices(4);
	g.add_vertices(5);

	g.add_edge(1, 2, 5);
	g.add_edge(2, 4, 15);
	g.add_edge(2, 5, 31);
	g.add_edge(2, 1, 5);
	g.add_edge(2, 3, 21);
	g.add_edge(1, 3, 10);
	g.add_edge(1, 4, 8);
	g.add_edge(1, 5, 11);
	g.add_edge(3, 1, 10);
	g.add_edge(3, 2, 21);
	g.add_edge(3, 4, 29);
	g.add_edge(3, 5, 30);
	g.add_edge(4, 1, 8);
	g.add_edge(4, 2, 15);
	g.add_edge(4, 3, 29);
	g.add_edge(4, 5, 2);
	g.add_edge(5, 1, 11);
	g.add_edge(5, 2, 31);
	g.add_edge(5, 3, 30);
	g.add_edge(5, 4, 2);

	auto path = g.shortest_path(4, 5);
	cout << "Shortest path: " << endl;
	for (const auto& edge : path) {
		cout << edge._from << " -> " << edge._to << "-> |" << edge._data << "| " << endl;
	}
}

TEST(GraphTest, NegativeTest) {

	Graph<int, int> g;

	g.add_vertices(1);
	g.add_vertices(2);
	g.add_vertices(3);

	g.add_edge(1, 2, 5);
	g.add_edge(2, 1, -5);
	g.add_edge(2, 3, 21);
	g.add_edge(1, 3, -10);
	g.add_edge(3, 1, 10);
	g.add_edge(3, 2, 21);

	EXPECT_ANY_THROW(g.shortest_path(2, 3));
}

TEST(GraphTest, StringTest) {
	Graph<string, int> g;

	g.add_vertices("Dallas");
	g.add_vertices("Washington");
	g.add_vertices("New York");
	g.add_vertices("Los Angeles");

	g.add_edge("Dallas", "New York", 260);
	g.add_edge("Dallas", "Los Angeles", 370);
	g.add_edge("New York", "Washington", 40);
	g.add_edge("Los Angeles", "New York", 1500);
	g.add_edge("Los Angeles", "Washington", 10);
	g.add_edge("Washington", "Dallas", 700);
	g.add_edge("Washington", "Los Angeles", 100);

	auto path = g.shortest_path("Dallas", "Washington");
	cout << "Shortest path: " << endl;
	for (const auto& edge : path) {
		cout << edge._from << " -> " << edge._to << "-> |" << edge._data << "| " << endl;
	}
}

TEST(GraphTest, CenterTest) {
	Graph<int> g;

	g.add_vertices(1);
	g.add_vertices(2);
	g.add_vertices(3);

	g.add_edge(1, 2, 5);
	g.add_edge(2, 1, 12);
	g.add_edge(2, 3, 21);
	g.add_edge(1, 3, 4);
	g.add_edge(3, 1, 10);
	g.add_edge(3, 2, 25);

	EXPECT_EQ(g.find_center(), 1);
}
