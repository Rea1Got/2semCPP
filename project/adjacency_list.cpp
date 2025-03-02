#include <iostream>
#include <vector>
#include <utility>

std::vector<std::vector<std::pair<int, int>>> adjacencyList(std::vector<std::vector<int>> graph_matrix){
  std::vector<std::vector<std::pair<int, int>>> adjacency_list(graph_matrix.size(), std::vector<std::pair<int, int>>());
  for (int i = 0; i < graph_matrix.size(); i++){
    for (int j = 0; j < graph_matrix.size(); j++){
      if (graph_matrix[i][j] != 0){
        adjacency_list[i].push_back(std::pair(j, graph_matrix[i][j])); // pair of number of verticy and weight of edge
      }
    }
  }
  return adjacency_list;
}

void printAdjacencyList(const std::vector<std::vector<std::pair<int, int>>> adjacency_list) {
    for (int i = 0; i < adjacency_list.size(); i++) {
        std::cout << "Vertex " << i << ": ";
        for (int j = 0; j < adjacency_list[i].size(); j++) {
            std::cout << "(" << adjacency_list[i][j].first << ", weight: " << adjacency_list[i][j].second << ") ";
        }
        std::cout << std::endl;
    }
}
