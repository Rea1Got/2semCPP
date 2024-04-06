#include <iostream>

// TODO: место для реализации структур Node и List
// функции List* create_empty_list()
// функции List* push_back(List* list_ptr, int new_key)
// и функции List* insert_after(List* list_ptr, Node* prev_ptr, int new_key)

using std::cout;
using std::endl;

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

List* insert_after(List* list_ptr, Node* prev_ptr, int new_key){
    void print(const List* list_ptr)

}

int main() {
  List* list = create_empty_list();
  list = push_back(list, 0);
  list = insert_after(list, list->HEAD, 1);
  if ((list->HEAD->key == 0) and (list->TAIL->key == 1)) {
    cout << "OK" << endl;
  }
  delete list->HEAD;
  delete list->TAIL;
  delete list->NIL;
  delete list;
  return 0;
}