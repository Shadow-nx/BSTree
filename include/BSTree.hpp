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
			auto insert(Node*& root,Node*& parent,int value) -> Node*;
			auto insert(Node*& root,Node*& parent,Node*& value) -> Node*;
			auto show(Node* root,int stage) const -> void;
			auto delete_tree(Node *&node) -> void;
			auto direct_bypass(Node* root) const -> void;
			auto symmetric_bypass(Node* root) const -> void;
			auto back_bypass(Node* root) const -> void;
			auto delete_node(Node *&root,int value) -> void;
		public:
			enum order{direct, symmetric, back};
			Tree();
		   	auto empty() const -> bool;
			auto show() const -> void;
			auto insert(int value) -> bool;
			auto version_bypass(order) const -> void;
			auto delete_node(int value) -> void;
			~Tree();
	};
}
