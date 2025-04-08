#include "dynamic_array.h"
#include "adjacency_list_colored.h"
#include "depth_first.h"
#include <iostream>

#define WHITE 0
#define GRAY 1
#define BLACK 2

DFS::DFS(AdjacencyListColored adjacencyColor, DynamicArray* time): adjacencyColor(adjacencyColor), time(time) {}

void DFS::freeDFS(int number_vertices){
  adjacencyColor.free(); 

  for (int i = 0; i < number_vertices; i++){
    time[i].delete_array();
  }
  delete[] time;
  time = nullptr;
}

void depthFirstVisit (DynamicArray**& adjacency_list, DFS& result, \
                      int number_vertices, int current_vertex, int& time_current){
  result.adjacencyColor.color.array[current_vertex] = GRAY;
  time_current++;
  result.time[current_vertex].append(time_current);
  //std::cerr << "current_vertex: " << current_vertex << " ";
  //std::cerr << adjacency_list[current_vertex]->size << " previousVertex: " << result.adjacencyColor.previousVertex.array[adjacency_list[current_vertex]->size] << std::endl;
  for (int i = 0; i < adjacency_list[current_vertex]->size; i++){
    int adjacent_vertex = adjacency_list[current_vertex]->get(i);
    if (result.adjacencyColor.color.array[adjacent_vertex] == WHITE){
      result.adjacencyColor.previousVertex.array[adjacent_vertex] = current_vertex;
      depthFirstVisit(adjacency_list, result, number_vertices, adjacent_vertex, time_current);
    }
  }
  result.adjacencyColor.color.array[current_vertex] = BLACK;
  time_current++;
  result.time[current_vertex].append(time_current);
  //std::cerr << "current_vertex: " << current_vertex << "previousVertex_2: " << result.adjacencyColor.previousVertex.array[adjacency_list[current_vertex]->size] << std::endl;
}

DFS depthFirst (DynamicArray** adjacency_list, int number_vertices){
  AdjacencyListColored adjacencyColor(number_vertices);
  DynamicArray* time = new DynamicArray[number_vertices];
  DFS result(adjacencyColor, time);
  for (int i = 0; i < number_vertices; i++){
    time[i] = DynamicArray();
  }
  int time_current = 0;

  for (int current_vertex = 0; current_vertex < number_vertices; current_vertex++) {
    if (adjacencyColor.color.get(current_vertex) == WHITE){
      depthFirstVisit(adjacency_list, result, number_vertices, current_vertex, time_current); 
    }
  }
  return result;
}

void DFSprint(DFS dfs_result, int number_of_vertices){
  std::cout << "Depth-first algotithm is finished!" << std::endl;
  for (int i = 0; i < number_of_vertices; i++) {
      std::cout << "Vertex " << i << ": " << " Previous = " << dfs_result.adjacencyColor.previousVertex.array[i] << " ";
      std::cout << "  Times: ";
      for (int j = 0; j < dfs_result.time[i].size; ++j) {
          std::cout << dfs_result.time[i].get(j) << " ";
      }
      std::cout << std::endl;
  }
}
