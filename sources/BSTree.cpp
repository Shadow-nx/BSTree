#include <iostream>
#include <string>
#include "bstree.hpp"

using namespace BSTree;
using namespace std;

Tree::Tree(): root(nullptr){};

auto Tree::empty() const -> bool {
	if (root == nullptr)
		return true;
	else
		return false;
}

auto Tree::show(Node* root, int stage) const -> void {
	if (root->left != nullptr)
		show(root->left, stage + 1);
	if (root != this->root) {
		cout.width(stage * 4);
		cout << "--";
	}
	cout << "(" << root->data << ")" << endl;
	if (root->right != nullptr)
		show(root->right, stage + 1);
}

auto Tree::show() const -> void {
	show(root, 1);
}

auto Tree::insert(Node*& root, Node*& parent, int value) -> Node* {
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
		} else if(root -> data == value){
			cout<<"tree is have this node"<<endl;
			return root;
		}
	}
	return root;
}
auto Tree::insert(Node*& root, Node*& parent, Node*& value) -> Node* {
	if (root == nullptr) {
	root = value;
	if(root != this->root)
		root->parent = parent;
	}
	else {
		if (root->data < value->data){
			root->left = insert(root->left, root, value);
		}
		else if (root->data > value->data){
			root->right = insert(root->right, root, value);
		}
	}
	return root;
}

auto Tree::insert(int value) -> bool {
	insert(root, root, value);
}

auto Tree::direct_bypass(Node* root) const -> void {
	if (root != nullptr) {
		cout << root->data << " ";
		direct_bypass(root->right);
		direct_bypass(root->left);
	}
}

auto Tree::symmetric_bypass(Node* root) const -> void {
	if (root != nullptr){
		symmetric_bypass(root->right);
		cout << root->data << " ";
		symmetric_bypass(root->left);
	}
	return;
}

auto Tree::back_bypass(Node* root) const -> void {
	if (root != nullptr){
		back_bypass(root->left);
		back_bypass(root->right);
		cout << root->data << " ";
	}
}

auto Tree::version_bypass(order ch) const -> void {
	switch (ch) {
			case direct:
				direct_bypass(root);
				break;
			case symmetric:
				symmetric_bypass(root);
				break;
			case back:
				back_bypass(root);
				break;
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
void Tree::delete_node(Node *&root, int value)
{
	if(!root)
	{
		cout << "Tree is empty" << endl;
		return;
	}else if(root){
		Node *current = root;	
		while(current->data != value){
	 		if ((value < current->data) && (current->right != nullptr)){
	 			current=current->right;
	 		}else if((value > current->data) && (current->left != nullptr)){
	 			current = current->left;
	 		}else if(current->data == value)
	 			break;
	 	}
		Node* left = nullptr;
		Node* right = nullptr;
	 	if(current == root){
	 		root = current->right;
	 		insert(root, root, current->left);
	 		delete current;
	 	}else{
	 		if((current->right != nullptr) && (current->left==nullptr)){
	 			if(current == current->parent->left)
	 		   		current->parent->left = nullptr;
	 		  	else
	 		   		current->parent->right = nullptr;
	 			right = current->right;
	 			insert(root, root, right);
	 		}
	 		else if((current->left != nullptr) && (current->right == nullptr)){
	 			if(current == current->parent->left)
	 				current->parent->left = nullptr;
	 		  	else
	 		   		current->parent->right = nullptr;
	 			left = current->left;
	 			insert(root, root, left);
	 		}
	 	    else if((current->right != nullptr) && (current->left != nullptr)){
	 	    	left = current->left;
	 	    	right = current->right;
	 	    	if(current == current->parent->left)
	 	    		current->parent->left = nullptr;
	 	    	else
	 	    		current->parent->right = nullptr;
                insert(root, root, left);
                insert(root, root, right);
	 	    }else{
	 	    	if(current == current->parent->left)
	 	    		current->parent->left = nullptr;
	 	    	if(current == current->parent->right)
	 	    		current->parent->right = nullptr;
	 	    }
	 	    delete current;
	 	}
	}
}
void Tree::delete_node(int value){
	delete_node(root, value);
}
Tree::~Tree() {
	delete_tree(root);
}
