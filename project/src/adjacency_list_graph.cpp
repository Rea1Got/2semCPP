#include <iostream>
#include "dynamic_array.h"

DynamicArray** adjacencyListGraph(DynamicArray* graph_matrix){
  int number_vertices = graph_matrix->size;
  DynamicArray** adjacency_list_graph = new DynamicArray*[number_vertices];
  for (int i = 0; i < number_vertices; i++){
    adjacency_list_graph[i] = new DynamicArray();
  }
  for (int i = 0; i < number_vertices; i++){
    for (int j = 0; j < number_vertices; j++){
      if (graph_matrix[i].get(j) != 0){
        adjacency_list_graph[i]->append(j);
        adjacency_list_graph[i]->append(graph_matrix[i].get(j)); // pair of number of vertex and weight of edge
      }
    }
  }

  return adjacency_list_graph;
}

void printAdjacencyList(DynamicArray** adjacency_list_graph, int number_vertices) {
  for (int i = 0; i < number_vertices; i++) {
    std::cout << "Vertex " << i << ": ";
    for (int j = 0; j < adjacency_list_graph[i]->size; j += 2) {
      std::cout << "(" << adjacency_list_graph[i]->get(j) << ", weight: " << adjacency_list_graph[i]->get(j + 1) << ") ";
    }
    std::cout << std::endl;
  }
}

void freeAdjacencyList(DynamicArray** adjacency_list_graph, int number_vertices) {
  if (adjacency_list_graph == nullptr) {
    return;
  }

  for (int i = 0; i < number_vertices; i++) {
    if (adjacency_list_graph[i] != nullptr) {
      adjacency_list_graph[i]->delete_array();  
      delete adjacency_list_graph[i];
    }
  adjacency_list_graph[i] = nullptr;
  }

  delete[] adjacency_list_graph;
  adjacency_list_graph = nullptr; 
}
