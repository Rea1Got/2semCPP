#include <iostream>

struct Node
{
    Node* prev = nullptr;
    Node* next = nullptr;
    int key = 0;
};

struct List
{
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;    
};

List* create_empty_list()
{
    Node* initNil = new Node;
    List* new_list = new List;
    new_list->NIL = initNil;
    new_list->HEAD = initNil;
    new_list->TAIL = initNil;
    new_list->size = 0;

    return new_list;
}

int main() {
  List* list = create_empty_list();
  if ((list->HEAD == list->NIL) and (list->TAIL == list->NIL) and (list->NIL != nullptr)) {
    std::cout << "OK" << std::endl;
  }
  delete list->NIL;
  delete list;
  return 0;
}
