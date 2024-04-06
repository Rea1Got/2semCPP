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

void destroy_list(Node*& head_ref){
    if (head_ref != nullptr){
        destroy_list(*&head_ref -> next);
    }
    delete head_ref;
    head_ref = nullptr;
}

void print_list(Node* head_ref) {
    if(head_ref != nullptr) {;
        Node* current = head_ref;
        while(current -> next != nullptr) {
            std::cout << current -> key << ' ';
            current = current -> next;
        }
    }

    std::cout << std::endl;
}

using std::cout;
using std::endl;

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  destroy_list(HEAD);
  if (HEAD == nullptr) {
    cout << "OK" << endl;
  }
  return 0;
}
