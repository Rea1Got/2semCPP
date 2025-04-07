// TODO -visualisation of simple graph- DONE
//      breadth-first/depth-first search
//      shortest path search
//      minimum spanning tree search
//      shortest paths between all vetices

#include <iostream>
#include "functions.h"
#include "adjacency_list_colored.h"
#include "dynamic_array.h"
#include "depth_first.h"

int main() {
  int number_of_vertices, user_answer = 0;

  std::cout << "Do you want to generate symmetrical graph (0) or write it by yourself (1)? " << std::endl;
  std::cin >> user_answer;
  DynamicArray* symmetrical_graph = new DynamicArray[number_of_vertices];
  if(!user_answer){
    int weight_max, seed = 0;
    std::cout << "Write number of vertices, maximum weight of edges, seed: ";
    std::cin >> number_of_vertices >> weight_max >> seed;
    symmetrical_graph = symmetricalGraphGenerate(number_of_vertices, weight_max, seed);
    printGraph(symmetrical_graph);
  } else {
    std::cout << "Write number of vertices: ";
    std::cin >> number_of_vertices;
    symmetrical_graph = symmetricalGraphWrite(number_of_vertices);
  }

  DynamicArray** adjacency_list_graph = new DynamicArray*[number_of_vertices];
  adjacency_list_graph = adjacencyListGraph(symmetrical_graph);
  printAdjacencyList(adjacency_list_graph, number_of_vertices);

  int user_vertex = 0;
  std::cout << "Which vertex do you want to explore (starting from 0)? " << std::endl;
  std::cin >> user_vertex;
  AdjacencyListColored adjacency_result = AdjacencyListColored(number_of_vertices); 
  adjacency_result = breadthFirst(adjacency_list_graph, number_of_vertices, user_vertex);
  adjacency_result.print();

  DFS dfs_result = depthFirst(adjacency_list_graph, number_of_vertices);
  DFSprint(dfs_result, number_of_vertices);


  freeSymmetricalGraph(symmetrical_graph, number_of_vertices);
  freeAdjacencyList(adjacency_list_graph, number_of_vertices);
  adjacency_result.free();
  dfs_result.freeDFS(number_of_vertices);
  
  return 0;
}
