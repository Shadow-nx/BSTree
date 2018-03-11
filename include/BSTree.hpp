namespace BSTree {
struct Node {
  int data;
  Node *left;
  Node *right;
  Node *prev;
};
class Tree {
 public:
  Node *head;
  Tree();
  auto fill_tree(int mass) -> void;
  auto delete_tree(Node *&node) -> void;
  ~Tree();
};
}
