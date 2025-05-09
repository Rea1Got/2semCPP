// TODO -visualisation of simple graph- DONE
//      -breadth-first/depth-first search- DONE
//      shortest path search
//      minimum spanning tree search
//      shortest paths between all vertices

#include <iostream>
#include "src/functions.h"
#include "src/adjacency_list_colored.h"
#include "src/dynamic_array.h"
#include "src/depth_first.h"
// #include "tests/tests.h"

int main() {
  int number_of_vertices, user_answer = 0;

  std::cout << "Do you want to generate symmetrical graph (0) or write it by yourself (1)? " << std::endl;
  std::cin >> user_answer;
  DynamicArray* symmetrical_graph;
  if(!user_answer){
    int weight_max, seed = 0;
    std::cout << "Write number of vertices, maximum weight of edges, seed: ";
    std::cin >> number_of_vertices >> weight_max >> seed;
    symmetrical_graph = symmetricalGraphGenerate(number_of_vertices, weight_max, seed);
    printGraph(symmetrical_graph, number_of_vertices);
  } else {
    std::cout << "Write number of vertices: ";
    std::cin >> number_of_vertices;
    symmetrical_graph = symmetricalGraphWrite(number_of_vertices);
  }

  DynamicArray** adjacency_list_graph = adjacencyListGraph(symmetrical_graph);
  printAdjacencyList(adjacency_list_graph, number_of_vertices);

  int user_vertex = 0;
  std::cout << "Which vertex do you want to explore (starting from 0 to "<< number_of_vertices - 1 <<")? " << std::endl;
  std::cin >> user_vertex;
  if (user_vertex < 0 or user_vertex > number_of_vertices){
    throw std::invalid_argument("Error! Invalid number of vertex.");
  }

  AdjacencyListColored adjacency_result = AdjacencyListColored(number_of_vertices); 
  adjacency_result = breadthFirst(adjacency_list_graph, number_of_vertices, user_vertex);
  adjacency_result.print();

  std::cout << std::endl;

  DFS dfs_result = depthFirst(adjacency_list_graph, number_of_vertices);
  DFSprint(dfs_result, number_of_vertices);
  
  std::cout << "Connected subgraphs: " << std::endl;
  DynamicArray subgraphs = disconnected_sets(dfs_result, number_of_vertices); 
  for (int i = 0; i < number_of_vertices; i++){
    std::cout << "Vertex " << i << " represented by: " << subgraphs.get(i) << std::endl;
  }

  // MST_Kruskal(adjacency_list_graph, number_of_vertices); 

  subgraphs.delete_array();
  freeAdjacencyList(adjacency_list_graph, number_of_vertices);
  freeSymmetricalGraph(symmetrical_graph, number_of_vertices);
  adjacency_result.free();
  dfs_result.freeDFS(number_of_vertices);

  return 0;
}
