#include <iostream>
#include <vector>
#include "bstree.hpp"

using namespace std;
using namespace BSTree;


void check_numbers(vector<int>& numbers_array, int argc, char* argv[]) {
	bool test = false;
	for (unsigned int i = 1; i < argc; i++) {
		test = false;
		for (unsigned int j = 0; j < numbers_array.size(); j++) {
			if (atoi(argv[i]) == numbers_array[j]) {
				test = true;
			}
		}
		if (test == false) {
			numbers_array.push_back(atoi(argv[i]));
		}
	}
}
void print_menu() {
	cout << endl;
	cout << "1: show tree" << endl;
	cout << "2: show list of tree" << endl;
	cout << "3: add node in tree" << endl;
	cout << "4: delete node of tree" << endl;
	cout << "5: save tree in file" << endl;
	cout << "6: load tree from file" << endl;
	cout << "7: search" << endl;
	cout << "8: finish programm" << endl;
	cout << endl;
}

void show_list_of_tree(Tree& tree){
	cout << "a.direct bypass" << endl;
	cout << "b.symmetric bypass" << endl;
	cout << "c.back bypass" << endl;
	char ch;
	while (true) {
		cin >> ch;
		cout << "1" << endl;
			switch (ch) {
				case 'a':
					tree.version_bypass(Tree::direct);
					cout << endl;
					return;
				case 'b':
					tree.version_bypass(Tree::symmetric);
					cout << endl;
					return;
				case 'c':
					tree.version_bypass(Tree::back);
					cout << endl;
					return;
			}
	}
}

bool finish_program() {
	string choice;
	while (true) {
		cout << "Do you want to leave program? ( yes, no )" << endl;
		cin >> choice;
		if ((choice == "y") || (choice == "yes") || (choice == "Y") || (choice == "Yes") || (choice == "YES"))
			return true;
		else if ((choice == "n") || (choice == "no") || (choice == "N") || (choice == "No") || (choice == "NO"))
			return false;
	}
}


int main(int argc, char* argv[]) {
	vector<int> numbers_array;
	Tree tree;

	check_numbers(numbers_array, argc, argv);
	if (numbers_array.size() > 0) {
		for(unsigned int i = 0; i < numbers_array.size(); i++)
			tree.insert(numbers_array[i]);
	}

	int choice = 0;
	while (true) {
		print_menu();
		cin >> choice;
		int value;
		switch (choice) {
			case 1:
				if (! tree.empty())
					tree.show();
				else
					cout << "Tree is empty" << endl;
				break;
			case 2:
				show_list_of_tree(tree);
				break;
			case 3:
				cout << "input value for insert"<<endl;
				cin >> value;
				tree.insert(value);
				break;
			case 4:
				cout << "input delete value" << endl;
				cin >> value;
				tree.delete_node(value);
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				if (finish_program()){
					tree.~Tree();
					return 0;
				}
				else
					continue;
		}
	}

	return 0;
}
