// TODO -visualisation of simple graph- DONE
//      breadth-first/depth-first search
//      shortest path search
//      minimum spanning tree search
//      shortest paths between all vetices

#include <vector>
#include "functions.h"
#include "adjacency_color.h"

#define SEED 1
#define NUMBER_OF_EDGES 5
#define WEIGHT_MAX 2 


int main() {
  int numberOfEdges = NUMBER_OF_EDGES;
  int weightMax = WEIGHT_MAX;
  std::vector<std::vector<int>> graph = generateGraph(numberOfEdges, weightMax, SEED);
  printGraph(graph);
  std::vector<std::vector<std::pair<int, int>>> adjacency_list = adjacencyList(graph);
  printAdjacencyList(adjacency_list);
  AdjacencyColor adjacency_result = breadthFirst(adjacency_list, 0);
  adjacency_result.print();
  return 0;
}
