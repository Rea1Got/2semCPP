#include <iostream>
#include "functions.h"
#include "dynamic_array.h"
#include <algorithm>


DynamicArray* MST_Kruskal(DynamicArray**& adjacency_list, int number_vertices){  // template
  DynamicArray* edges = new DynamicArray();
  DynamicArray* mst = new DynamicArray();
  DynamicArray* new_set = new DynamicArray();
  std::cerr << "Started" << std::endl;

  for (int i = 0; i < number_vertices; i++){  // for every vertex add in new tree this vertex
    new_set[i] = DynamicArray();
    new_set[i].append(i); 
  }

  std::cerr << "Passed init" << std::endl; 
  bool init = false;
  for (int i = 0; i < number_vertices; i++){  // edge = [{source}, {destination}, {weight}]
    init = false;                       
    for (int j = 0; j < adjacency_list[i]->size; j += 2){
      if (!init){
        edges[i] = DynamicArray();
        init = true;
      }
      if (i < adjacency_list[i]->get(j)){  // source < destination
        edges[i].append(i);
        edges[i].append(adjacency_list[i]->get(j));
        edges[i].append(adjacency_list[i]->get(j + 1));
      }
    }
  }


  std::cerr << edges->size << std::endl; 
  for (int i = 0; i < edges->size - 1; i++){  // sort OPTIMIZE ME
    for (int j = i + 1; j < edges->size; j++){
      if (edges[i].get(3) < edges[j].get(3)){
        std::swap(edges[i], edges[j]);
      }
    }
  }

  return mst;
}
