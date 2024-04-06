#include <iostream>

struct Node{
    int key = 0;
    Node* next = nullptr;
};


void insert_after(Node*& prev_ref, int new_key) {
    Node* new_element = new Node;
    new_element -> key = new_key;
    new_element -> next = prev_ref -> next;
    prev_ref -> next = new_element;
}

using std::cout;
using std::endl;

int main() {
  Node* HEAD = new Node;
  insert_after(HEAD, 0);
  insert_after(HEAD, 1);
  insert_after(HEAD, 2);
  Node* ptr = HEAD;
  while (ptr->next != nullptr) {
    cout << ptr->key << ' ';
    ptr = ptr->next;
  }
  cout << ptr->key << endl;
  ptr = HEAD;
  while (ptr->next != nullptr) {
    ptr = HEAD->next;
    delete HEAD;
    HEAD = ptr;
  }
  delete HEAD;
  return 0;
}