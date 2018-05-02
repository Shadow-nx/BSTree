#include <iostream>
#include <string>
#include <fstream>
#include <initializer_list>
#include <vector>
#include "bstree.hpp"

using namespace BSTree;
using namespace std;

Tree::Tree(): root(nullptr) {};

Tree::Tree(std::initializer_list<int> list) {
	root=nullptr;
	for(auto i : list)
		insert(root,root,i);
}
Tree::Tree(const Tree& tree) {
	root=nullptr;
	vector<int> numbers_array;
	direct_bypass(tree.root,numbers_array);
	for(int i=0; i<numbers_array.size(); i++)
		insert(numbers_array[i]);
}
/*
auto Tree::empty() const -> bool {
	if (root == nullptr)
		return true;
	else
		return false;
}

auto Tree::show(Node* root,int stage) const -> void {
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
*/
auto Tree::show(Node* root,ostream& os,int stage) const -> void {
	if (root->left != nullptr)
		show(root->left,os, stage + 1);
	if (root != this->root) {
		os.width(stage * 4);
		os << "--";
	}
	os << "(" << root->data << ")" << endl;
	if (root->right != nullptr)
		show(root->right,os, stage + 1);
}
/*
auto Tree::show() const -> void {
	show(root, 1);
}
*/
auto Tree::exists(int value) -> bool {
	if(!root) {
		cout<<"tree is empty"<<endl;
		return false;
	} else if(root) {
		Node *current=root;
		while(current!=nullptr) {
			if(value < current->data) {
				current=current->right;
			} else if(value > current->data) {
				current=current->left;
			} else if(current->data==value) {
				break;
			}
		}
		if(current==nullptr){
			cout<<"item not found"<<endl;
			return false;
		}else{
			cout<<"item found"<<endl;
			return true;
		}
	}
}
auto Tree::insert(Node*& root,Node*& parent,int value) -> Node* {
	if (root == nullptr) {
		root = new Node {value,nullptr,nullptr,nullptr};
		if(root != this->root)
			root->parent = parent;
	} else {
		if (root->data < value) {
			root->left = insert(root->left, root, value);
		} else if (root->data > value) {
			root->right = insert(root->right, root, value);
		} else if(root -> data == value) {
			cout<<"tree is have this node"<<endl;
			return root;
		}
	}
	return root;
}
auto Tree::insert(Node*& root,Node*& parent,Node*& value) -> Node* {
	if (root == nullptr) {
		root = value;
		if(root != this->root)
			root->parent = parent;
	} else {
		if (root->data < value->data) {
			root->left = insert(root->left, root, value);
		} else if (root->data > value->data) {
			root->right = insert(root->right, root, value);
		}
	}
	return root;
}

auto Tree::insert(int value) -> bool {
	insert(root, root, value);
}

auto Tree::direct_bypass(Node* root,vector<int>& numbers_array) const -> void {
	if (root != nullptr) {
		numbers_array.push_back(root->data);
		direct_bypass(root->right,numbers_array);
		direct_bypass(root->left,numbers_array);
	}
}
auto Tree::direct_bypass(Node* root, ofstream &fout) const -> void {
	if (root != nullptr) {
		fout << root->data << " ";
		direct_bypass(root->right,fout);
		direct_bypass(root->left,fout);
	}
}
auto Tree::symmetric_bypass(Node* root,vector<int>& numbers_array) const -> void {
	if (root != nullptr) {
		symmetric_bypass(root->right,numbers_array);
		numbers_array.push_back(root->data);
		symmetric_bypass(root->left,numbers_array);
	}
	return;
}

auto Tree::back_bypass(Node* root,vector<int>& numbers_array) const -> void {
	if (root != nullptr) {
		back_bypass(root->left,numbers_array);
		back_bypass(root->right,numbers_array);
		numbers_array.push_back(root->data);
	}
}

auto Tree::version_bypass(order ch) const -> void {
	vector<int> numbers_array;
	switch (ch) {
		case direct:
			direct_bypass(root,numbers_array);
			break;
		case symmetric:
			symmetric_bypass(root,numbers_array);
			break;
		case back:
			back_bypass(root,numbers_array);
			break;
	}
	for(int i=0; i<numbers_array.size(); i++)
		cout<<numbers_array[i]<<" ";
}
auto Tree::delete_tree(Node *&node) -> void {
	if(node != nullptr) {
		delete_tree(node->left);
		delete_tree(node->right);
		delete node;
		node = nullptr;
	}
}
auto Tree::delete_node(Node *&root,int value) ->bool {
	if(!root) {
		cout<<"tree is empty"<<endl;
		return false;
	} else if(root) {
		Node *current=root;
		while(current!=nullptr) {
			if(value < current->data) {
				current=current->right;
			} else if(value > current->data) {
				current=current->left;
			} else if(current->data==value)
				break;
		}
		if(current==nullptr) {
			cout<<"item not found"<<endl;
			return false;
		}
		Node* left=nullptr;
		Node* right=nullptr;
		if(current==root) {
			root=current->right;
			insert(root,root,current->left);
			delete current;
			cout<<"deleted successfully"<<endl;
			return true;
		} else {
			if(current->right!=nullptr && current->left==nullptr) {
				if(current==current->parent->left)
					current->parent->left=nullptr;
				else
					current->parent->right=nullptr;
				right=current->right;
				insert(root,root,right);
			} else if(current->left!=nullptr && current->right==nullptr) {
				if(current==current->parent->left)
					current->parent->left=nullptr;
				else
					current->parent->right=nullptr;
				left=current->left;
				insert(root,root,left);
			} else if(current->right != nullptr && current->left!=nullptr) {
				left=current->left;
				right=current->right;
				if(current==current->parent->left)
					current->parent->left=nullptr;
				else
					current->parent->right=nullptr;
				insert(root,root,left);
				insert(root,root,right);
			} else {
				if(current==current->parent->left)
					current->parent->left=nullptr;
				if(current==current->parent->right)
					current->parent->right=nullptr;
			}
			delete current;
			cout<<"deleted successfully"<<endl;
			return true;
		}
	}
}
auto Tree::save_to_file(const string& path) -> bool {
	ofstream fout(path.c_str());
	if(!fout.is_open() || root==nullptr) {
		cout<<"ERROR:file cant open or tree is empty"<<endl;
		return false;
	}
	direct_bypass(root,fout);
	return true;

}
auto Tree::load_from_file(const string& path)-> bool {
	ifstream fin(path.c_str());
	if (!fin.is_open()) {
		cout << "file cant open";
		return false;
	}
	if(root) {
		delete_tree(root);
	}
	int value;
	while(fin>>value) {
		insert(value);
	}
	return true;
}
namespace BSTree {
	auto operator<<(std::ostream& os,const Tree& tr) -> std::ostream& {
		if(tr.root) {
			tr.show(tr.root,os,1);
			return os;
		} else{
			os<<"tree is empty"<<endl;
			return os;
		}
	}
}
auto Tree::operator=(const Tree& tree) -> Tree& {
	if(root!=nullptr)
		delete_tree(root);
	vector<int> numbers_array;
	direct_bypass(tree.root,numbers_array);
	for(int i=0; i<numbers_array.size(); i++)
		insert(numbers_array[i]);

}
auto Tree::delete_node(int value) -> bool {
	delete_node(root,value);
}
Tree::~Tree() {
	delete_tree(root);
}
