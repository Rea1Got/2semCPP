#include <iostream>
#include <string>
#include <map>

enum TraverseType { INORDER, PREORDER, POSTORDER };

struct Node {
  int key = 0;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
};

void insert_node (Node*& tree, int new_key){
  if (tree == nullptr){
    tree = new Node;
    tree->key = new_key;
    return;
  }
  if (new_key > tree->key){
    if (tree->right == nullptr){
      Node* new_node = new Node;
      new_node->key = new_key;
      new_node->parent = tree;
      tree->right = new_node;
    } else {
      insert_node(tree->right, new_key);
    }
  } else {
    if (tree->left == nullptr){
      Node* new_node = new Node;
      new_node->key = new_key;
      new_node->parent = tree;
      tree->left = new_node;
    } else {
      insert_node(tree->left, new_key);
    }
  }
}

Node* min(Node*& tree){
  if (tree == nullptr){
    return tree;
  }
  Node* current_tree = tree;
  while (current_tree->left != nullptr){
    current_tree = current_tree->left;
  }
  return current_tree;
}

Node* max(Node*& tree){
  if (tree == nullptr){
    return tree;
  }
  Node* current_tree = tree;
  while (current_tree->right != nullptr){
    current_tree = current_tree->right;
  }
  return current_tree;
}

Node* find(Node*& tree, int key){
  Node* current_tree = tree;
  while (current_tree != nullptr){
    if (current_tree->key == key){
      return current_tree;
    } else if (key > current_tree->key){
      current_tree = current_tree->right;
    } else {
      current_tree = current_tree->left;
    }
  }
    
  return nullptr;
}

Node* next(Node*& tree, int key){
  if (tree == nullptr){
    return nullptr;
  }
  if (find(tree, key) == nullptr){
    return nullptr;
  }

  Node* result = nullptr;
  Node* current = tree;

  while (current != nullptr) {
    if (current->key > key) {
      result = current;  
      current = current->left;  
    } else {
      current = current->right;  
    }
  }

  return result;
}

void print_inorder(Node* tree) {
    if (tree == nullptr) {
      return;
    }

    print_inorder(tree->left);
    std::cout << tree->key << " ";
    print_inorder(tree->right);
}

void print_preorder(Node* tree) {
    if (tree == nullptr) {
      return;
    } 

    std::cout << tree->key << " ";

    print_preorder(tree->left);
    print_preorder(tree->right);
}

void print_postorder(Node* tree) {
    if (tree == nullptr) {
      return;
    }

    print_postorder(tree->left);
    print_postorder(tree->right);

    std::cout << tree->key << " ";
}

void print(Node*& tree, const TraverseType type) {
    if (tree == nullptr) {
        std::cout << std::endl;
        return;
    }

    switch(type) {
        case INORDER: 
          print_inorder(tree); 
          break;
        case PREORDER: 
          print_preorder(tree); 
          break;
        case POSTORDER: 
          print_postorder(tree); 
          break;
    }

    std::cout << std::endl;
}

void delete_node(Node*& tree, int key) {
    if (tree == nullptr) {
        return;
    }

    if (key < tree->key) {
        delete_node(tree->left, key);
    } else if (key > tree->key) {
        delete_node(tree->right, key);
    } else {  // found node staged for deletion
        if (tree->left == nullptr && tree->right == nullptr) {
            delete tree;
            tree = nullptr;
        } else if (tree->left == nullptr) {
            Node* temp = tree;

            tree = tree->right;
            tree->parent = temp->parent;

            delete temp;
        } else if (tree->right == nullptr) {
            Node* temp = tree;

            tree = tree->left;
            tree->parent = temp->parent;

            delete temp;
        } else {
            Node* min_right = tree->right;

            while (min_right->left != nullptr) {
                min_right = min_right->left;
            }
            tree->key = min_right->key;

            delete_node(tree->right, min_right->key);
        }
    }
}

void destroy_tree(Node*& tree) {
  if (tree) {
    destroy_tree(tree->left);  
    destroy_tree(tree->right); 
    delete tree;             
    tree = nullptr; 
  }
}


int main() {
    enum Command { FINISH, INSERT, MIN, MAX, FIND, NEXT, PRINT, DELETE, DESTROY, STAR };
    Node* tree = nullptr;
    std::map<std::string, Command> command_map = {
        {"finish", FINISH},
        {"insert", INSERT},
        {"min", MIN},
        {"max", MAX},
        {"find", FIND},
        {"next", NEXT},
        {"print", PRINT},
        {"delete", DELETE},
        {"destroy", DESTROY}
    };

    std::string command;
    while (std::cin >> command) {
        switch (command_map[command]) {
            case INSERT: {
                int x;
                std::cin >> x;
                insert_node(tree, x);
                break;
            }
            case MIN: {
                Node* result = min(tree);
                if (result != nullptr){ 
                  std::cout << result->key << std::endl;
                } else {
                  std::cout << std::endl;
                }
                break;
            }
            case MAX: {
                Node* result = max(tree);
                if (result != nullptr) {
                  std::cout << result->key << std::endl;
                } else { 
                  std::cout << std::endl;
                }
                break;
            }
            case FIND: {
                int x;
                std::cin >> x;
                Node* result = find(tree, x);
                if (result != nullptr) {
                  std::cout << result->key << std::endl;
                } 
                break;
            }
            case NEXT: {
                int x;
                std::cin >> x;
                Node* result = next(tree, x);
                if (result != nullptr) {
                  std::cout << result->key << std::endl;
                } else {
                  std::cout << std::endl;
                }
                break;
            }
            case PRINT: {
                int x;
                std::cin >> x;
                if (x == 0){
                  print(tree, INORDER);
                } else if (x == 1){
                  print(tree, PREORDER);
                } else if (x == 2){
                  print(tree, POSTORDER);
                }
                break;
            }
            case DELETE: {
                int x;
                std::cin >> x;
                delete_node(tree, x);
                break;
            }
            case DESTROY: {
                destroy_tree(tree);
                break;
            }
            case FINISH: {
                destroy_tree(tree);
                return 0;
            }
            default: {
                std::cout << "Unknown command" << std::endl;
                break;
            }
        }
    }

    return 0;
}

