#include <iostream>
#include "BSTree.hpp"

using namespace BSTree;
using namespace std;

Tree::Tree() {
	root = nullptr;
}
Node* Tree::getRoot() {
	return root;
}
auto Tree::show_tree(Node* root,int stage)->void {
	if(root->left != nullptr)
		show_tree(root->left,stage+1);
	if(root!=this->root) {
		cout.width(stage*4);
		cout<<"--";
	}
	cout<<"("<< root->data <<")"<< endl;
	if(root->right!=nullptr)
		show_tree(root->right,stage+1);
}
auto Tree::insert(int value) -> bool {
	if (root == nullptr) {
		root = new Node{value, nullptr, nullptr};
	}

	Node* current = root;
	Node* previous = root;
	while (current != nullptr) {
		if (current->data > value) {
			current = current->left;
		}
		else if (current->data < value){
			current = current->right;
		}
		else {
			return false;
		}
		if (current != nullptr) {
			previous = current;	
		}
	}

	if (previous->data > value) {
		previous->left = new Node{value, nullptr, nullptr};
	}
	else {
		previous->right = new Node{value, nullptr, nullptr};
	}
	return true;
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
