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

using std::cout;
using std::endl;

int main() {
  List* list = new List;
  if ((list->HEAD == nullptr) and (list->TAIL == nullptr) and (list->NIL == nullptr)) {
    cout << "OK" << endl;
  }
  list->HEAD = new Node;
  if ((list->HEAD->key == 0) and (list->HEAD->next == nullptr) and (list->HEAD->prev == nullptr)) {
    cout << "OK" << endl;
  }
  delete list->HEAD;
  delete list;
  return 0;
}
