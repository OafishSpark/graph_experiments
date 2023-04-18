#pragma onces


#include <vector>
#include <array>
#include <cassert>
#include <iostream>

#define IN	0
#define OUT	1
#define WEIGHT	2


const int INF = 20000000;


class Graph{
	/*
		adjacency list should cosnsist of 3 elements:
		(int start_point, int end_point, int weight)
	*/
	std::vector<std::array<int, 3>> adjlist;
	/*
		adjacency matrix is a square matrix (E, E)
		element of matrix is a weight edge
		if there is no edge, weight should be equal to INF
	*/
	std::vector<std::vector<int>> adjmatrix;
public:
	Graph(std::vector<std::array<int, 3>> adjl) : adjlist{adjl} {}
	
	Graph(std::vector<std::vector<int>> adjm);
	
	Graph(const std::vector<std::array<int, 2>>& adjl);
	
	const std::vector<std::array<int, 3>>& get_adjlist() const;
	
	void print(char mode = 'l') const;
	
	void make_adjlist(const char mode = 'u');
	
	void make_adjmatrix(const char mode = 'u');
};


#undef IN
#undef OUT
#undef WEIGHT
