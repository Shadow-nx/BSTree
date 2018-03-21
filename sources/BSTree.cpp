#include <iostream>
#include "BSTree.hpp"

using namespace BSTree;
using namespace std;

Tree::Tree(): root(nullptr){};

auto Tree::get_root() -> Node*{
	return root;
}

auto Tree::show_tree(Node* root,int stage) -> void {
	if (root->left != nullptr)
		show_tree(root->left, stage + 1);
	if (root != this->root) {
		cout.width(stage * 4);
		cout << "--";
	}
	cout << "(" << root->data << ")" << endl;
	if (root->right != nullptr)
		show_tree(root->right, stage + 1);
}

auto Tree::empty() -> bool {
	if (root == nullptr)
		return true;
	show_tree(root, 1);
}

auto Tree::insert(Node*& root,Node*& parent,int value) -> Node* {
	if (root == nullptr) {
	root = new Node{value,nullptr,nullptr,nullptr};
	if(root != this->root)
		root->parent = parent;
	}
	else {
		if (root->data < value){
			root->left = insert(root->left, root, value);
		}
		else if (root->data > value){
			root->right = insert(root->right, root, value);
		}
	}
	return root;
}

auto Tree::add_to_tree(int value) -> bool {
	insert(root, root, value);
}

auto Tree::direct_bypass(Node* root) -> void {
	if (root != nullptr) {
		cout << root->data << " ";
		direct_bypass(root->right);
		direct_bypass(root->left);
	}
}

auto Tree::symmetric_bypass(Node* root) -> void {
	if (root != nullptr){
		symmetric_bypass(root->right);
		cout << root->data << "   ";
		symmetric_bypass(root->left);
	}
}

auto Tree::back_bypass(Node* root) -> void {
	if (root != nullptr){
		back_bypass(root->left);
		back_bypass(root->right);
		cout << root->data << "   ";
	}
}

auto Tree::delete_tree(Node *&node) -> void {
	if(node != nullptr) {
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
		node = nullptr;
	}
}

Tree::~Tree() {
	delete_tree(root);
}
