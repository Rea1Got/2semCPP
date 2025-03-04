#ifndef adjacency_list_colored_H 
#define adjacency_list_colored_H 

#include <vector>

struct AdjacencyListColored{
    std::vector<int> color;              
    std::vector<int> previousVertex;  
    std::vector<int> distance;

    AdjacencyListColored(std::vector<std::vector<std::pair<int ,int>>> adjacencyListGraph);
   
    void colorGray(int&);
    void paintItBlack(int&);
    void print();
};


#endif 
