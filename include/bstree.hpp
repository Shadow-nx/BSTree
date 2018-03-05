
namespace BSTree {
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node *prev;
};

class Tree {
 public:
  Node *head;
  Tree() { head = nullptr; }
  void fill_tree(vector<int> mass) {
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
  void print_menu() {
    cout << "1: show tree" << endl;
    cout << "2: show list of tree" << endl;
    cout << "3: add node in tree" << endl;
    cout << "4: delete node of tree" << endl;
    cout << "5: save tree in file" << endl;
    cout << "6: load tree from file" << endl;
    cout << "7: search" << endl;
    cout << "8: finish programm" << endl;
  }
  int menu(){
    int choice = 0;
    while (true) {
      print_menu();
      cin >> choice;
      switch (choice) {
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
        case 5:
          break;
        case 6:
          break;
        case 7:
          break;
        case 8:
          return 0;
      }
    }
  }
  ~Tree() { ; }
};
}
