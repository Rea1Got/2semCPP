#include <vector>
#include "adjacency_color.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// list of functions
std::vector<std::vector<int>> generateGraph(int, int, int);
void printGraph(const std::vector<std::vector<int>>&);
std::vector<std::vector<std::pair<int, int>>> adjacencyList(std::vector<std::vector<int>> graph_matrix);
void printAdjacencyList(std::vector<std::vector<std::pair<int, int>>> adjacency_list);
AdjacencyColor breadthFirst(std::vector<std::vector<std::pair<int, int>>> adjacencyList, int startVerticy);


#endif 

