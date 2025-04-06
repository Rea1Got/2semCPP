#include "adjacency_list_colored.h"
#include "dynamic_array.h"
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// list of functions
DynamicArray* symmetricalGraphGenerate(int, int, int);
DynamicArray* symmetricalGraphWrite(int);
void printGraph(DynamicArray*);

DynamicArray** adjacencyListGraph(DynamicArray* graph_matrix);
void printAdjacencyList(DynamicArray** adjacency_list_graph, int number_vertices);
void freeAdjacencyList(DynamicArray** adjacency_list_graph, int number_vertices);

AdjacencyListColored breadthFirst(DynamicArray** adjacencyListGraph, int number_vertices, int startVerticy);


#endif 

