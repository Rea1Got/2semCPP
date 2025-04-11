#include <iostream>
#include "dynamic_array.h"

DynamicArray* symmetricalGraphGenerate(int number_of_vertices, int weight_max, int seed){
  std::srand(seed); // init random 
  DynamicArray* symmetrical_graph = new DynamicArray[number_of_vertices];
  for (int i = 0; i < number_of_vertices; i++){
    symmetrical_graph[i] = DynamicArray(number_of_vertices, 0);
  }

  for (int i = 0; i < number_of_vertices; ++i) {
    for (int j = i; j < number_of_vertices; ++j) {
        if (i != j){
          int randValue = std::rand() % weight_max; // generate weight of the edges(0; upToNumber)
          symmetrical_graph[i].array[j] = randValue; 
          symmetrical_graph[j].array[i] = randValue;
        } 
        else {
          symmetrical_graph[i].array[i] = 0;
        }
    }
  }

  return symmetrical_graph;
}

void printGraph(DynamicArray* arr, int number_of_vertices){
  for (int i = 0; i < number_of_vertices; i++) { 
    for (int j = 0; j < arr[i].size; j++) { 
      std::cout << arr[i].get(j) << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "Graph generated!" << std::endl;
}

DynamicArray* symmetricalGraphWrite(int number_of_vertices){
  DynamicArray* symmetricalGraph = new DynamicArray[number_of_vertices];
  
  for (int i = 0; i < number_of_vertices; i++){
    symmetricalGraph[i] = DynamicArray(number_of_vertices, 0);
    for (int j = 0; j < number_of_vertices; j++){
      std::cin >> symmetricalGraph[i].array[j];
    }
  }
  return symmetricalGraph;
}

void freeSymmetricalGraph(DynamicArray*& symmetrical_graph, int number_of_vertices) {
  if (symmetrical_graph == nullptr) {
    return;
  }

  for (int i = 0; i < number_of_vertices; ++i) {
    symmetrical_graph[i].delete_array(); 
  }

  delete[] symmetrical_graph;
  symmetrical_graph = nullptr;
}
