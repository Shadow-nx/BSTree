#include <iostream>
#include <vector>
#include "BSTree.hpp"

using namespace std;
using namespace BSTree;

  Tree::Tree() { head = nullptr; }
  auto Tree::fill_tree(vector<int> mass)-> void {
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

  Tree::~Tree() { ; }
