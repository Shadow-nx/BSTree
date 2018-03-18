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
			auto delete_tree(Node *&node) ->void;
		public:
			Tree();
		   	auto empty()->bool;
			auto show_tree(Node* root,int stage)->void;
			auto insert(Node*& root,Node*& parent,int value)->Node*;
			auto add_to_tree(int value)->bool;
			~Tree();
	};
}
