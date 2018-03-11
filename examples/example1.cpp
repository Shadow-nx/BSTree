#include <iostream>
#include <vector>
#include "BSTree.hpp"

using namespace std;
using namespace BSTree;


void check_numbers(vector<int>& numbers_array, int argc, char* argv[]) {
	bool test = false;
	for (int i = 1; i < argc; i++) {
		test = false;
		for (int j = 0; j < numbers_array.size(); j++) {
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
	cout << "1: show tree" << endl;
	cout << "2: show list of tree" << endl;
	cout << "3: add node in tree" << endl;
	cout << "4: delete node of tree" << endl;
	cout << "5: save tree in file" << endl;
	cout << "6: load tree from file" << endl;
	cout << "7: search" << endl;
	cout << "8: finish programm" << endl;
}


int main(int argc, char* argv[]) {
	vector<int> numbers_array;
	Tree* tree;

	check_numbers(numbers_array, argc, argv);
	if (numbers_array.size() > 0) {
		for(int i=0; i<numbers_array.size(); i++)
			tree->insert(numbers_array[i]);
	}

	int choice = 0;
	while (true) {
		print_menu();
		cin >> choice;
		switch (choice) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			case 7:
				break;
			case 8:
				return 0;
		}
	}

	return 0;
}
