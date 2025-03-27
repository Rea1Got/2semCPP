#include <iostream>
#include <vector>


std::vector<std::vector<int>> symmetricalGraphGenerate(int number_of_vertices, int weight_max, int seed){
  std::srand(seed); // init random 
  std::vector<std::vector<int>> symmetrical_graph(number_of_vertices, std::vector<int>(number_of_vertices));

  for (int i = 0; i < number_of_vertices; ++i) {
    for (int j = i; j < number_of_vertices; ++j) {
        if (i != j){
          int randValue = std::rand() % weight_max; // generate weight of the edges(0; upToNumber)
          symmetrical_graph[i][j] = randValue; 
          symmetrical_graph[j][i] = randValue;
        } 
        else {
          symmetrical_graph[i][j] = 0;
        }
    }
  }

  return symmetrical_graph;
}

void printGraph(const std::vector<std::vector<int>>& arr){
  for (size_t i = 0; i < arr.size(); i++) { 
    for (size_t j = 0; j < arr[i].size(); j++) { 
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "Graph generated!" << std::endl;
}

std::vector<std::vector<int>> symmetricalGraphWrite(int number_of_vertices){
  std::vector<std::vector<int>> symmetricalGraph (number_of_vertices, std::vector<int>(number_of_vertices));
  for (int i = 0; i < number_of_vertices; i++){
    for (int j = 0; j < number_of_vertices; j++){
      std::cin >> symmetricalGraph[i][j];
    }
  }
  return symmetricalGraph;
}
