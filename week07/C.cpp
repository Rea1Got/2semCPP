#include <iostream>

struct Node{
    int key = 0;
    Node* next = nullptr;
};


void push_back(Node*& head_ref, int new_key) {
    Node* new_element = new Node;
    new_element -> key = new_key;
    if(head_ref != nullptr) {
        Node* current = head_ref;
        while(current -> next != nullptr) {
            current = current -> next;
        }
        new_element -> next = nullptr;
        current -> next = new_element;
    }
    else {
        head_ref = new_element;
        new_element -> next = nullptr;
    }
}

using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
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