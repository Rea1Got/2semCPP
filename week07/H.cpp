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

void remove_key(Node*& head_ptr, int key){
  if (head_ptr == nullptr) {
    return;
  }

  if (head_ptr->key == key){
    Node* tmp = head_ptr;
    head_ptr = head_ptr->next;
    delete tmp;
  } else {
    Node* current = head_ptr;
    while (current->next != nullptr and current->next->key != key){
      current = current->next;
    }
    if (current->next != nullptr){
      Node* tmp = current->next;
      current->next = current->next->next;
      delete tmp;
    }
  }
}

int main() {
  Node* HEAD = nullptr;
  push_back(HEAD, 0);
  push_back(HEAD, 1);
  push_back(HEAD, 2);
  remove_key(HEAD, 0);
  remove_key(HEAD, 1);
  remove_key(HEAD, 2);
  remove_key(HEAD, 3);
  if (HEAD == nullptr) {
    std::cout << "OK" << std::endl;
  }
  return 0;
}
