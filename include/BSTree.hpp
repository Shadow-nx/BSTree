#include <fstream>
#include <iostream>
#include <vector>

namespace BSTree {
	enum order {direct, symmetric, back};
	struct Node {
		int data;
		Node *left;
		Node *right;
		Node *parent;
	};
	class Tree {
		private:
			Node* root;
			auto insert(Node*& root, Node*& parent, int value) -> Node*;
			auto insert(Node*& root, Node*& parent, Node*& value) -> Node*;
			auto show(Node* root, int stage) const -> void;
			auto show(Node* root, std::ostream& os, int stage) const -> void;
			auto delete_tree(Node *&node) -> void;
			auto direct_bypass(Node* root, std::vector<int>& numbers_array) const -> void;
			auto direct_bypass(Node* root, std::ofstream &fout) const -> void;
			auto symmetric_bypass(Node* root, std::vector<int>& numbers_array) const -> void;
			auto back_bypass(Node* root, std::vector<int>& numbers_array) const -> void;
			auto delete_node(Node *&root, int value) -> bool;
		public:
			Tree();
			Tree(std::initializer_list<int> list);
			Tree(const Tree& tree);
			auto exists(int value) ->bool;
			auto insert(int value) -> bool;
			auto delete_node(int value) -> bool;
			auto save_to_file(const std::string& path) -> bool;
			auto load_from_file(const std::string& path)-> bool;
			auto version_bypass(order) const -> void;
			auto friend operator<<(std::ostream& os, const Tree& tr) -> std::ostream&;
			auto operator=(const Tree&) -> Tree&;
			~Tree();
	};
}
