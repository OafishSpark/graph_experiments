#include "graphs.h"

#include <iostream>
#include <vector>
#include <array>
#include <string>


void print(int number) {
	std::cout << number << std::endl;
}


void print(std::string words) {
	std::cout << words << std::endl;
}


int main() {
	// graph from adjlist
	std::vector<std::vector<std::array<int, 2>>> adjl1{
		{{1, 25}, {2, 10}},
		{{2, 30}, {3, 20}},
		{{3, 10}},
		{{0, 15}},
	};
	Graph graph1(adjl1);
	// graph from adjmatrix
	print("Adjacency list for graph 1");
	graph1.print();
	graph1.make_adjmatrix();
	print("Adjacency matrix for graph 1");
	graph1.print('m');
	std::vector<std::vector<int>> adjm1{
		{INF,	25,	INF,	15},
		{25,	INF,	30,	INF},
		{INF,	INF,	INF,	INF},
		{15,	INF,	10,	INF},
	};
	Graph graph2(adjm1, 'm');
	print("Adjacency matrix for graph 2");
	graph2.print('m');
	graph2.make_adjlist();
	print("Adjacency list for graph 2");
	graph2.print();
	// graph from adjlist without weights
	std::vector<std::vector<int>> adjl2{
		{1, 2},
		{2, 3},
		{3, 4},
		{4, 1},
	};
	Graph graph3(adjl2);
	print("Adjacency list for graph 3");
	graph3.print();
	// outro message
	std::cout << "Everything seems to be correct!\n";
	return 0;
}
