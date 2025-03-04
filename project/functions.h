#include <vector>
#include "adjacency_list_colored.h"

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// list of functions
std::vector<std::vector<int>> symmetricalGraphGenerate(int, int, int);
void printGraph(const std::vector<std::vector<int>>&);
std::vector<std::vector<std::pair<int, int>>> adjacencyListGraph(std::vector<std::vector<int>> graph_matrix);
void printAdjacencyList(std::vector<std::vector<std::pair<int, int>>> adjacency_list_graph);
AdjacencyListColored breadthFirst(std::vector<std::vector<std::pair<int, int>>> adjacencyListGraph, int startVerticy);


#endif 

