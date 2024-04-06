#include <iostream>

using std::cout;
using std::endl;
using std::cin;

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

List* push_front(List* list_ptr, int new_key) {
  if (list_ptr == nullptr) {
    return nullptr;
  }

  List* new_list = list_ptr;
  if (list_ptr->size != 0) {
    Node* node = new Node;
    node->key = new_key;
    node->next = new_list->HEAD;
    node->prev = new_list->NIL;
    new_list->HEAD->prev = node;
    new_list->HEAD = node;
    new_list->size++;
    return new_list;
  }

  new_list->TAIL = new Node;
  new_list->TAIL->key = new_key;
  new_list->TAIL->prev = new_list->NIL;
  new_list->TAIL->next = new_list->NIL;
  new_list->HEAD = new_list->TAIL;
  new_list-> size++;
  return new_list;
}

List* push_back(List* list_ptr, int new_key) {
  if (list_ptr == nullptr) {
    return nullptr;
  }
  List *new_list = list_ptr;
  if (list_ptr->size != 0) {
    Node *node = new Node;
    node->key = new_key;
    node->prev = new_list->TAIL;
    node->next = new_list->NIL;
    new_list->TAIL->next = node;
    new_list->TAIL = node;
    new_list->size++;
    return new_list;
  }
  new_list->HEAD = new Node;
  new_list->HEAD->key = new_key;
  new_list->HEAD->next = new_list->NIL;
  new_list->HEAD->prev = new_list->NIL;
  new_list->TAIL = new_list->HEAD;
  new_list->size++;
  return new_list;
}

int main() {
  List* list = create_empty_list();
  list = push_back(list, 0);
  if ((list->HEAD->key == 0) and (list->TAIL->key == 0)) {
    cout << "OK" << endl;
  }
  delete list->HEAD;
  delete list->NIL;
  delete list;
  return 0;
}