#include "AVLTree.h"
#include <iostream>
int main() {


	//double numbers[] = { 9, 4, 11, 2, 6, 15, 1, 3, 5, 8 };
	double numbers[] = { 4, 9, 11};


	AVLTree* tree = new AVLTree();
	for (double number : numbers) {
		tree->insert(new Node(number));
	}
	std::cout << "DONE";
	return 0;
}