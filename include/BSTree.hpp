namespace BSTree {
	struct Node {
		int data;
		Node *left;
		Node *right;
		Node *parent;
	};
	class Tree {
		private:
			Node *root;
			auto delete_tree(Node *&node) ->void;
		public:
			Tree();
			auto insert(int mass)-> void;
			~Tree();
	};
}
