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
        while(current != nullptr) {
            std::cout << current -> key << ' ';
            current = current -> next;
        }
    }

    std::cout << std::endl;
}

Node* find(Node*& head_ref, int key) {
    Node* current = head_ref;
    while ((current != nullptr) and (current->key != key)){
        current = current->next;
    }
    return current;
}

int main() {
  Node* HEAD = nullptr, *current = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  current = find(HEAD, 2);
  if (current->key == 2) {
      std::cout << "OK" << std::endl;
  }
  destroy_list(HEAD);
  return 0;
}
