namespace BSTree {
	struct Node {
		int data;
		Node *left;
		Node *right;
		Node *parent;
	};
	class Tree {
		private:
			Node* root;
			auto delete_tree(Node *&node) -> void;
		public:
			Tree();
			auto get_root() -> Node*;
		   	auto empty() -> bool;
			auto show_tree(Node* root,int stage) -> void;
			auto insert(Node*& root,Node*& parent,int value) -> Node*;
			auto add_to_tree(int value) -> bool;
			auto direct_bypass(Node* root) -> void;
			auto symmetric_bypass(Node* root) -> void;
			auto back_bypass(Node* root) -> void;
			~Tree();
	};
}
