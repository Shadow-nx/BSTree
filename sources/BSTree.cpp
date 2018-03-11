#include <iostream>
#include "BSTree.hpp"

using namespace BSTree;
using namespace std;

Tree::Tree() {
	root = nullptr;
}
auto Tree::insert(int mass) -> void {
	Node *curr;
	curr = root;
	Node *node = new Node{mass, nullptr, nullptr, nullptr};
	if (root == nullptr) {
		root = node;
		return;
	}
	while (true) {
		if ((curr->data) < (node->data) && curr->right != nullptr) {
			curr = curr->right;
		} else if ((curr->data) < (node->data) && curr->right == nullptr) {
			curr->right = node;
			node->parent = curr;
			break;
		}

		if ((curr->data) > (node->data) && curr->left != nullptr) {
			curr = curr->left;
		} else if ((curr->data) > (node->data) && curr->left == nullptr) {
			curr->left = node;
			node->parent = curr;
			break;
		}
	}
}
auto Tree::delete_tree(Node *&node) -> void {
	if(node!=nullptr) {
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
		node=nullptr;
	}
}
Tree::~Tree() {
	delete_tree(root);
}
