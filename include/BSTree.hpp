namespace BSTree {
#include <vector>  
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
  Node *prev;
};
class Tree {
  Node *head;
 public:
  Tree();
  auto fill_tree(vector<int> mass)-> void;
  ~Tree();
};
}
