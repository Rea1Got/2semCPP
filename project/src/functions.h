#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "adjacency_list_colored.h"
#include "dynamic_array.h"
#include "depth_first.h"

DynamicArray* symmetricalGraphGenerate(int, int, int);
DynamicArray* symmetricalGraphWrite(int);
void printGraph(DynamicArray*, int);
void freeSymmetricalGraph(DynamicArray*&, int);

DynamicArray** adjacencyListGraph(DynamicArray* graph_matrix);
void printAdjacencyList(DynamicArray** adjacency_list_graph, int number_vertices);
void freeAdjacencyList(DynamicArray** adjacency_list_graph, int number_vertices);

AdjacencyListColored breadthFirst(DynamicArray** adjacencyListGraph, int number_vertices, int startVerticy);

void depthFirstVisit (DynamicArray**& adjacency_list, DFS result, \
                      int number_vertices, int current_vertex, int& time_current);
DFS depthFirst (DynamicArray** adjacency_list, int number_vertices);
void DFSprint(DFS dfs_result, int number_of_vertices);

DynamicArray disconnected_sets(const DFS& dfs_result, int number_vertices);

#endif 

