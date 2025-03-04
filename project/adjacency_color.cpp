#include <iostream>
#include "adjacency_color.h"

AdjacencyColor::AdjacencyColor(std::vector<std::vector<std::pair<int, int>>> adjacencyList) : color(std::vector<int>()), previousVerticy(std::vector<int>()){
    color.assign(adjacencyList.size(), 0);  // all white color (= 0)
                                            // gray = 1
                                            // black = 2
    previousVerticy.assign(adjacencyList.size(), -1);  // none of the verticies has previousVerticy
    distance.assign(adjacencyList.size(), 0);  //like prev comment
}

void AdjacencyColor::colorGray(int &verticy){
    verticy = 1;
}

void AdjacencyColor::paintItBlack(int &verticy){  // i see a red door and i want it painted black
    verticy = 2;
}

void AdjacencyColor::print(){
  std::cout << "color: ";
  for (int i = 0; i < color.size(); i++){
      std::cout << color[i] << " ";
  }
  std::cout << std::endl;
  
  std::cout << "previousVerticy: ";
  for (int i = 0; i < previousVerticy.size(); i++){
      std::cout << i << ": " << previousVerticy[i] << "; ";
  }
  std::cout << std::endl;

  std::cout << "distance: ";
  for (int i = 0; i < distance.size(); i++){
      std::cout << i << ": " << distance[i] << "; ";
  }
  std::cout << std::endl;
}


