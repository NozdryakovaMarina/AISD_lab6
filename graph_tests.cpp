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
