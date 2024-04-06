#include <iostream>

// TODO: вставьте код вашего определения структуры

using std::cout;
using std::endl;

struct Node{
    int key = 0;
    Node* next = nullptr;
};

int main() {
  Node* HEAD = nullptr;
  HEAD = new Node;
  if ((HEAD->key == 0) and (HEAD->next == nullptr)) {
    cout << "OK" << endl;
  } else {
    cout << endl;
  }
  delete HEAD;
  return 0;
}