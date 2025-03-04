// TODO -visualisation of simple graph- DONE
//      breadth-first/depth-first search
//      shortest path search
//      minimum spanning tree search
//      shortest paths between all vetices

#include <vector>
#include "functions.h"
#include "adjacency_list_colored.h"

#define SEED 3
#define NUMBER_OF_VERTICES 25
#define WEIGHT_MAX 2 


int main() {
  int numberOfEdges = NUMBER_OF_VERTICES;
  int weightMax = WEIGHT_MAX;
  std::vector<std::vector<int>> graph = symmetricalGraphGenerate(numberOfEdges, weightMax, SEED);
  printGraph(graph);
  std::vector<std::vector<std::pair<int, int>>> adjacency_list_graph = adjacencyListGraph(graph);
  printAdjacencyList(adjacency_list_graph);
  AdjacencyListColored adjacency_result = breadthFirst(adjacency_list_graph, 1);
  adjacency_result.print();
  return 0;
}
