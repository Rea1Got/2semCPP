#include <iostream>
#include "adjacency_list_colored.h"
#include "dynamic_array.h"
#include "functions.h"

AdjacencyListColored::AdjacencyListColored(int number_vertices) \
                                              : color(), previousVertex(){
    color = DynamicArray(number_vertices, 0);  // all white color (= 0), gray = 1, black = 2
    previousVertex = DynamicArray(number_vertices, -1);  // none of the verticies has previousvertex
    distance = DynamicArray(number_vertices, -1);  //like prev comment
}

void AdjacencyListColored::print(){
  std::cout << "Breadth first algorithm is finished!" << std::endl;

  std::cout << "Parential vertex: ";
  for (int i = 0; i < previousVertex.size; i++){
      std::cout << i << ": " << previousVertex.get(i) << "; ";
  }
  std::cout << std::endl;

  std::cout << "Distance from the starting vertex: ";
  for (int i = 0; i < distance.size; i++){
      std::cout << i << ": " << distance.get(i) << "; ";
  }
  std::cout << std::endl;
}

void AdjacencyListColored::free(){
  color.delete_array();
  previousVertex.delete_array();
  distance.delete_array();
}


