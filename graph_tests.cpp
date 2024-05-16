#include <gtest/gtest.h>
#include "graph_list.cpp"
#include <stdexcept>
#include <iostream>

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