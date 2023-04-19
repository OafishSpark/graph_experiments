#pragma once


#include <vector>
#include <array>
#include <cassert>
#include <iostream>

#define OUT	0
#define WEIGHT	1


const int INF = 20000000;


class Graph{
	/*
		adjacency list should cosnsist of V vectors which consists of pairs:
		(int end_point, int weight)
	*/
	std::vector<std::vector<std::array<int, 2>>> adjlist;
	/*
		adjacency matrix is a square matrix (E, E)
		element of matrix is a weight edge
		if there is no edge, weight should be equal to INF
	*/
	std::vector<std::vector<int>> adjmatrix;
public:
	Graph(std::vector<std::vector<std::array<int, 2>>> adjl) : adjlist{adjl} {} 

	Graph(const std::vector<std::vector<int>>& adjl, char mode = 'l');

	const std::vector<std::vector<std::array<int, 2>>>& get_adjlist() const;
	
	void print(char mode = 'l') const;
	
	void make_adjlist(); // 
	
	void make_adjmatrix(); // 
};


#undef OUT
#undef WEIGHT
