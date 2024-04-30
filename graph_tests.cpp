#include <gtest/gtest.h>
#include "graph_list.cpp"
#include <stdexcept>
#include <iostream>

using namespace graph;
using namespace std;

TEST(EdgeTests, Constructor) {
	Edge<int> a(1, 2);
	EXPECT_EQ(a.from, 1);
	EXPECT_EQ(a.to, 2);
	EXPECT_EQ(a.data, 0);
}

TEST(EdgeTests, Constructor2) {
	Edge<int, int> a(1, 2, 7);
	EXPECT_EQ(a.from, 1);
	EXPECT_EQ(a.to, 2);
	EXPECT_EQ(a.data, 7);
}

TEST(EdgeTests, Print) {
	Edge<int, int> a(6, 2, 12);
	a.print();
}

TEST(EdgeTests, Print2) {
	Edge<int, int> a(6, 2);
	a.print();
}
