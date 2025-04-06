#ifndef adjacency_list_colored_H 
#define adjacency_list_colored_H 

#include "dynamic_array.h"
#include <vector>

struct AdjacencyListColored{
    DynamicArray color;              
    DynamicArray previousVertex;  
    DynamicArray distance;

    AdjacencyListColored(int number_vertices);
    
    void free();
    void colorGray(int&);
    void paintItBlack(int&);
    void print();
};


#endif 
