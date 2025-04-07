#ifndef DEPTH_FIRST_H 
#define DEPTH_FIRST_H

#include "dynamic_array.h"
#include "adjacency_list_colored.h"

struct DFS {
  DFS(AdjacencyListColored adjacencyColor, DynamicArray* time);
  AdjacencyListColored adjacencyColor;
  DynamicArray* time;

  void freeDFS(int number_vertices);
};



#endif 
