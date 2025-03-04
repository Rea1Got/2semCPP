// TODO -visualisation of simple graph- DONE
//      breadth-first/depth-first search
//      shortest path search
//      minimum spanning tree search
//      shortest paths between all vetices

#include <iostream>
#include <vector>
#include "functions.h"
#include "adjacency_list_colored.h"

// #define SEED 1
// #define NUMBER_OF_VERTICES 50
// #define WEIGHT_MAX 2 


int main() {
  int number_of_vertices, user_answer = 0;
  std::vector<std::vector<int>> symmetrical_graph(0, std::vector<int>(0));

  std::cout << "Do you want to generate symmetrical graph (0) or write it by yourself (1)? " << std::endl;
  std::cin >> user_answer;
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

  // std::vector<std::vector<int>> symmetrical_graph = symmetricalGraphGenerate(NUMBER_OF_VERTICES, WEIGHT_MAX, SEED);
  // printGraph(symmetrical_graph);
  std::vector<std::vector<std::pair<int, int>>> adjacency_list_graph = adjacencyListGraph(symmetrical_graph);
  //printAdjacencyList(adjacency_list_graph);

  int user_vertex = 0;
  std::cout << "Which vertex do you want to explore (starting from 0)? " << std::endl;
  std::cin >> user_vertex;
  AdjacencyListColored adjacency_result = breadthFirst(adjacency_list_graph, user_vertex);
  adjacency_result.print();
  return 0;
}
