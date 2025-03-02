#include "adjacency_color.h"

AdjacencyColor::AdjacencyColor(std::vector<std::vector<std::pair<int, int>>> adjacencyList) : color(std::vector<int>()), previousVerticy(std::vector<int>()){
    color.assign(adjacencyList.size(), 0);  // all white color (= 0)
                                            // gray = 1
                                            // black = 2
    previousVerticy.assign(adjacencyList.size(), -1);  // none of the verticies has previousVerticy
    distance.assign(adjacencyList.size(), -1);  //like prev comment
}

void AdjacencyColor::colorGray(int &verticy){
    verticy = 1;
}

void AdjacencyColor::paintItBlack(int &verticy){  // i see a red door and i want it painted black
    verticy = 2;
}


