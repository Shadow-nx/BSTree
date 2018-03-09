#include <iostream>
#include <vector>
#include "BSTree.h"

using namespace std;
using namespace BSTree;

Tree::Tree() { head = nullptr; }
auto Tree::fill_tree(vector<int> mass) -> void {
  Node *curr;
  for (int i = 0; i < mass.size(); i++) {
    curr = head;
    Node *node = new Node{mass[i], nullptr, nullptr, nullptr};
    if (head == nullptr) {
      head = node;
      continue;
    }
    while (true) {
      if ((curr->data) < (node->data) && curr->right != nullptr) {
        curr = curr->right;
      } else if ((curr->data) < (node->data) && curr->right == nullptr) {
        curr->right = node;
        node->prev = curr;
        break;
      }

      if ((curr->data) > (node->data) && curr->left != nullptr) {
        curr = curr->left;
      } else if ((curr->data) > (node->data) && curr->left == nullptr) {
        curr->left = node;
        node->prev = curr;
        break;
      }
    }
  }
}
Tree::~Tree() {
  Node *current;
  while (head != nullptr) {
    current = head;
    while (current->right != nullptr && current->left != nullptr) {
      if (current->right != nullptr) {
        current = current->right;
      } else if (current->left != nullptr) {
        current = current->left;
      }
    }
    if (current != head) {
      if ((current->data) > (current->prev->data)) {
        current->prev->right = nullptr;
      }
      if ((current->data) < (current->prev->data)) {
        current->prev->left = nullptr;
      }
      delete current;
    } else if (current == head) {
      delete head;
      head = nullptr;
    }
  }
}
