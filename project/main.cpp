// TODO visualisation of simple graph
//      breadth-first/depth-first search
//      shortest path search
//      minimum spanning tree search
//      shortest paths between all vetices

#include <vector>


#include "functions.h"


#define SEED 10
#define NUMBER_OF_EDGES 5
#define WEIGHT_MAX 10


int main() {
  int numberOfEdges = NUMBER_OF_EDGES;
  int weightMax = WEIGHT_MAX;
  std::vector<std::vector<int>> graph = generateGraph(numberOfEdges, weightMax, SEED);
  printGraph(graph);
  return 0;
}
