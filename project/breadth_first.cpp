#include "queue.h"
#include "adjacency_list_colored.h"

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define QUEUE_SIZE 50

AdjacencyListColored breadthFirst(std::vector<std::vector<std::pair<int, int>>> adjacencyListGraph, int start_vertex){
  AdjacencyListColored adjacencyColor(adjacencyListGraph);
  adjacencyColor.color[start_vertex] = GRAY;
  Queue queue(QUEUE_SIZE);
  queue.enqueue(start_vertex);
  int current_vertex = start_vertex;  // bruh
  std::vector<std::pair<int, int>> currentVertexAdj = adjacencyListGraph[current_vertex];
  while(queue.size() != 0){
    current_vertex = queue.dequeue();
    currentVertexAdj = adjacencyListGraph[current_vertex];
    for (int i = 0; i < currentVertexAdj.size(); i++){
      int adj_vertex = currentVertexAdj[i].first;
      if(adjacencyColor.color[adj_vertex] == WHITE){
        adjacencyColor.color[adj_vertex] = GRAY;
        adjacencyColor.distance[adj_vertex] = adjacencyColor.distance[current_vertex] + 1;
        adjacencyColor.previousVertex[adj_vertex] = current_vertex;
        queue.enqueue(adj_vertex);
      }
    }
    adjacencyColor.color[current_vertex] = BLACK;
  }
  return adjacencyColor;
}
