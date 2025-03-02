#ifndef ADJACENCY_COLOR_H 
#define ADJACENCY_COLOR_H 

#include <vector>

struct AdjacencyColor{
    std::vector<std::vector<std::pair<int, int>>> adjacencyList;
    std::vector<int> color;              
    std::vector<int> previousVerticy;  
    std::vector<int> distance;

    AdjacencyColor(std::vector<std::vector<std::pair<int ,int>>> adjacencyList);

    void colorGray(int&);
    void paintItBlack(int&);
};


#endif 
