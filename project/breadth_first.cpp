#include "queue.h"
#include "adjacency_color.h"

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define QUEUE_SIZE 50
AdjacencyColor breadthFirst(std::vector<std::vector<std::pair<int, int>>> adjacencyList, int startVerticy){
  AdjacencyColor adjacencyColor(adjacencyList);
  adjacencyColor.colorGray(startVerticy);
  Queue queue(QUEUE_SIZE);
  queue.enqueue(startVerticy);
  int currentVerticy = startVerticy;  // bruh
  std::vector<std::pair<int, int>> currentVerticyAdj = adjacencyList[currentVerticy];
  while(queue.size() != 0){
    currentVerticy = queue.dequeue();
    currentVerticyAdj = adjacencyList[currentVerticy];
    for (int i = 0; i < currentVerticyAdj.size(); i++){
      int adjVerticy = currentVerticyAdj[i].first;
      if(adjacencyColor.color[adjVerticy] == WHITE){
        adjacencyColor.color[adjVerticy] = GRAY;
        adjacencyColor.distance[adjVerticy]++;
        adjacencyColor.previousVerticy[adjVerticy] = currentVerticy;
        queue.enqueue(i);
      }
    }
    adjacencyColor.color[currentVerticy] = BLACK;
  }
  return adjacencyColor;
}
