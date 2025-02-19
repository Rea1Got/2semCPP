#include <iostream>
#include <vector>


std::vector<std::vector<int>> generateGraph(int numberOfVerticies, int weightMax, int seedValue){
  std::srand(seedValue); // init random 
  std::vector<std::vector<int>> graph(numberOfVerticies, std::vector<int>(numberOfVerticies));

  for (int i = 0; i < numberOfVerticies; ++i) {
    for (int j = i; j < numberOfVerticies; ++j) {
        if (i != j)
        {
          int randValue = std::rand() % weightMax; // generate weight of the edges(0; upToNumber)
          graph[i][j] = randValue; 
          graph[j][i] = randValue;
        } 
        else {
          graph[i][j] = 0;
        }
    }
  }

  return graph;
}

void printGraph(const std::vector<std::vector<int>>& arr) {
  for (const auto& row : arr) {
    for (int value : row) {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "Graph generated!" << std::endl;
}
