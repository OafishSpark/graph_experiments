#include "graphs.h"

#include <iostream>
#include <vector>
#include <exception>
#include <cassert>
#include <array>

#define IN	0
#define OUT	1
#define WEIGHT	2


int max(int a, int b){
	return a > b ? a : b;
}


Graph::Graph(std::vector<std::vector<int>> adjm) : adjmatrix{adjm} {
	assert(!adjm.empty() && "Adjacency matrix is empty!");
	for (const auto& raw : adjm) {
		assert(raw.size() == adjm.size() && "Adjacency matrix is not a square matrix!");
	}
}


	
Graph::Graph(const std::vector<std::array<int, 2>>& adjl) {
	for (const auto& edge : adjl) {
		std::array<int, 3> temp_elem{ edge[IN], edge[OUT], 1};
		adjlist.push_back(temp_elem);
	}
}


const std::vector<std::array<int, 3>>& Graph::get_adjlist() const {
	return adjlist;
}


/*
	Prints graph. Graph representation depends on mode:
		'l' --- adjacency list
		'm' --- adjacency matrix
*/
void Graph::print(char mode) const {
	switch (mode) {
	case 'l':
		for (const auto& edge : adjlist) {
			for (const auto& elem : edge) {
				if (elem == INF) {
					std::cout << "INF" << "\t";
				} else {
					std::cout << elem << "\t";
				}
			}
			std::cout << "\n";
		}
		break;
	case 'm':
		for (const auto& raw: adjmatrix){
			for (const auto& elem : raw) {
				if (elem == INF) {
					std::cout << "INF" << "\t";
				} else {
					std::cout << elem << "\t";
				}
			}
			std::cout << "\n";
		}
		break;
	default:
		std::cout << "Wrong mode!\n";
	}
	return;
}


void Graph::make_adjlist(const char mode) {
	assert(!adjmatrix.empty() && "Adjacency matrix is empty!");
	size_t n{ adjmatrix.size() };	
	for (size_t i = 0; i != n; i++) {
		size_t k{ i };
		if (mode == 'o') {
			k = 0;
		} 
		for (size_t j = k; j != n; j++) {
			if (adjmatrix[i][j] < INF) { 
				std::array<int, 3> temp{static_cast<int>(i), static_cast<int>(j), adjmatrix[i][j]};
				adjlist.push_back(temp);
			}
		}
	}
	return;
}


void Graph::make_adjmatrix(char mode) {
	assert(!adjlist.empty() && "Adjacency list is empty!");
	size_t size{ 0 };
	for (const auto& edge : adjlist) {
		
		int in = edge[IN];
		int out = edge[OUT];
		int new_size = max(in, out) + 1;
		std::cout << in << out << new_size << std::endl;
		if (size < new_size) {
			for (size_t i = 0; i != new_size; i++) {
				if (i < size) {
					adjmatrix[i].resize(new_size, INF);
				} else {
					std::vector<int> temp(new_size, INF);
					adjmatrix.push_back(temp);
				}
			}
			size = new_size;
		}
		
		switch (mode) {
		case 'u':
			adjmatrix[in][out] = edge[WEIGHT];
			adjmatrix[out][in] = edge[WEIGHT];
			break;
		case 'o':
			adjmatrix[in][out] = edge[WEIGHT];
			break;
		default:
			throw std::exception(); // Wrong mode!
		}
	}
	
	return;
}


#undef IN
#undef OUT
#undef WEIGHT
