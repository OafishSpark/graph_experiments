#include "graphs.h"

#include <iostream>
#include <vector>
#include <exception>
#include <cassert>
#include <array>
#include <string>

#define OUT	0
#define WEIGHT	1


inline int max(int a, int b){
	return a > b ? a : b;
}


inline std::string infprint(int num){
	return num == INF ? "INF" : std::to_string(num);
}


Graph::Graph(const std::vector<std::vector<int>>& adjl, char mode) {
	switch (mode) {
	case 'm':
		assert(!adjl.empty() && "Adjacency matrix is empty!");
		for (const auto& raw : adjl) {
			assert(raw.size() == adjl.size() && "Adjacency matrix is not a square matrix!");
		}
		adjmatrix = adjl;
		break;
	case 'l':
		for (const auto& vertice : adjl) {
			std::vector<std::array<int, 2>> temp(vertice.size());
			for (int i = 0; i != vertice.size(); i++) {
				temp[i][OUT] = vertice[i];
				temp[i][WEIGHT] = 1;
			}
			adjlist.push_back(temp);
		}
		break;
	default:
		assert(false); // wrong mode
	}
}


const std::vector<std::vector<std::array<int, 2>>>& Graph::get_adjlist() const {
	return adjlist;
}


/*
	Prints graph. Graph representation depends on mode:
		'l' --- adjacency list
		'm' --- adjacency matrix
*/
void Graph::print(char mode) const {
	int vertice_num = 0;
	switch (mode) {
	case 'l':
		for (const auto& vertice : adjlist) {
			std::cout << vertice_num++ << ": ";
			for (const auto& edge : vertice) {
				std::cout << "(" << infprint(edge[OUT]) << ", ";
				std::cout << infprint(edge[WEIGHT]) << ")  ";
			}
			std::cout << "\n";
		}
		break;
	case 'm':
		for (const auto& raw: adjmatrix){
			for (const auto& elem : raw) {
				std::cout << infprint(elem) << "\t";
			}
			std::cout << "\n";
		}
		break;
	default:
		std::cout << "Wrong mode!\n";
	}
	return;
}


void Graph::make_adjlist() {
	assert(!adjmatrix.empty() && "Adjacency matrix is empty!");
	if (!adjlist.empty()) {
		adjlist.clear();
	}
	int n = adjmatrix.size();
	for (int in = 0; in != n; in++) {
		std::vector<std::array<int, 2>> temp_v;
		adjlist.push_back(temp_v);
		for (int out = 0; out != n; out++) {
			int elem = adjmatrix[in][out];
			if (elem < INF) {
				std::array<int, 2> temp_a{out, elem};
				adjlist[in].push_back(temp_a);	
			}
		}
	}
	return;
}


void Graph::make_adjmatrix() {
	assert(!adjlist.empty() && "Adjacency list is empty!");
	if (!adjmatrix.empty()) {
		adjmatrix.clear();
	}
	int n = adjlist.size();
	adjmatrix.resize(n);
	for (int in = 0; in != n; in++) {
		adjmatrix[in].resize(n, INF);
	}
	for (int in = 0; in != n; in++) {
		for (const auto& edge : adjlist[in]) {
			int out = edge[OUT], weight = edge[WEIGHT];
			adjmatrix[in][out] = weight;
		}
	}
	return;
}


#undef OUT
#undef WEIGHT
