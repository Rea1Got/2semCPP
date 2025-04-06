#include "queue.h"
#include "adjacency_list_colored.h"

#define WHITE 0
#define GRAY 1
#define BLACK 2

AdjacencyListColored breadthFirst(DynamicArray** adjacencyListGraph, int number_vertices, int start_vertex){
  AdjacencyListColored adjacencyColor(number_vertices);
  adjacencyColor.color.array[start_vertex] = GRAY;
  adjacencyColor.distance.array[start_vertex] = 0;
  Queue queue(number_vertices);
  queue.enqueue(start_vertex);
  int current_vertex = start_vertex;  // bruh
  DynamicArray* currentVertexAdj = adjacencyListGraph[current_vertex];
  while(queue.size() != 0){
    current_vertex = queue.dequeue();
    currentVertexAdj = adjacencyListGraph[current_vertex];
    for (int i = 0; i < currentVertexAdj->size; i++){
      int adj_vertex = currentVertexAdj->get(i);
      if(adjacencyColor.color.array[adj_vertex] == WHITE){
        adjacencyColor.color.array[adj_vertex] = GRAY;
        adjacencyColor.distance.array[adj_vertex] = adjacencyColor.distance.array[current_vertex] + 1;
        adjacencyColor.previousVertex.array[adj_vertex] = current_vertex;
        queue.enqueue(adj_vertex);
      }
    }
    adjacencyColor.color.array[current_vertex] = BLACK;
  }
  return adjacencyColor;
}
