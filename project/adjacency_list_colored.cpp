#include <iostream>
#include "adjacency_list_colored.h"

AdjacencyListColored::AdjacencyListColored(std::vector<std::vector<std::pair<int, int>>> adjacencyListGraph) : color(std::vector<int>()), previousVertex(std::vector<int>()){
    color.assign(adjacencyListGraph.size(), 0);  // all white color (= 0)
                                            // gray = 1
                                            // black = 2
    previousVertex.assign(adjacencyListGraph.size(), -1);  // none of the verticies has previousvertex
    distance.assign(adjacencyListGraph.size(), 0);  //like prev comment
}

void AdjacencyListColored::print(){
  std::cout << "Breadth first algorithm is finished!" << std::endl;

  std::cout << "Parential vertex: ";
  for (int i = 0; i < previousVertex.size(); i++){
      std::cout << i << ": " << previousVertex[i] << "; ";
  }
  std::cout << std::endl;

  std::cout << "Distance from the starting vertex: ";
  for (int i = 0; i < distance.size(); i++){
      std::cout << i << ": " << distance[i] << "; ";
  }
  std::cout << std::endl;
}


