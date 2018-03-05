
#include <iostream>
#include <vector>
#include <iomanip>
#include "BSTree.h"

using namespace std;
using namespace BSTree;

void check_numbers(vector<int> &numbers_array, int argc, char *argv[]) {
  bool test = false;
  for (int i = 1; i < argc; i++) {
    test = false;
    for (int j = 0; j < numbers_array.size(); j++) {
      if (atoi(argv[i]) == numbers_array[j]) {
        test = true;
      }
    }
    if (test == false) {
      numbers_array.insert(numbers_array.end(), atoi(argv[i]));
    }
  }
}

int main(int argc, char *argv[]) {
  vector<int> numbers_array;
  Tree *tree = new Tree;

  check_numbers(numbers_array, argc, argv);
  if (numbers_array.size() > 0) {
    tree->fill_tree(numbers_array);
  }
  tree->menu();

  return 0;
}
