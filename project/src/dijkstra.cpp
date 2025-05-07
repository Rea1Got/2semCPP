#include "dynamic_array.h"
#include "priority_queue.h"

#define INF 1000000


struct PairVertexDistance {
  int vertex;
  int distance;
  int parent;
  PairVertexDistance() {}
  PairVertexDistance(int vertex, int distance, int parent) : vertex(vertex), distance(distance), parent(parent){}  
};

void relax(PairVertexDistance first, PairVertexDistance& second, int edge){
  if (second.distance > first.distance + edge){
    second.distance = first.distance + edge;
    second.parent = first.vertex;
  }
}

void dijkstra(DynamicArray** adjacency_list, int number_vertices, int start_vertex){
  PairVertexDistance first;
  PairVertexDistance second;

  DynamicArray distances = DynamicArray();
  DynamicArray parents = DynamicArray();
  BinaryHeap priority_queue = BinaryHeap();
  for (int i = 0; i < number_vertices; i++){
    distances.append(INF);
    parents.append(-1);
    priority_queue.insert(i, distances.get(i));
  }
  
  DynamicArray set_of_vertices = DynamicArray();
  DynamicArray u;

  while (!priority_queue.isEmpty()){
    u = priority_queue.extractRoot();
    int current_vertex = u.get(0);
    
    set_of_vertices.append(current_vertex);  
    for (int i = 0; i < adjacency_list[current_vertex]->size; i++){
      int second_vector = adjacency_list[current_vertex]->get(i);

      first = PairVertexDistance(current_vertex, parents.get(current_vertex), distances.get(current_vertex));
      second = PairVertexDistance(second_vector, parents.get(second_vector), distances.get(second_vector));

      relax(first, second, adjacency_list[current_vertex]->get(i));  // fix edge
      distances.array[second_vector] = second.distance;
      parents.array[second_vector] = second.parent;
    }
  }
}

