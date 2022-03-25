#include "AVLTree.h"
#include <iostream>


void heightCompare();
double fRand(double fMin, double fMax);


int main() {

/*
	//double numbers[] = { 9, 4, 11, 2, 6, 15, 1, 3, 5, 8 };
	double numbers[] = {1,2,3,4};


	AVLTree* tree = new AVLTree();
	AVLTree* tree2 = new AVLTree();

	for (double number : numbers) {
		tree->insert(new Node(number));
		tree2->insertWithoutRebalance(new Node(number));
	}
	//std::cout << tree->getTotalHeight()<<std::endl;
	std::cout << tree2->getTotalHeight() << std::endl;   //no restrucutre
	std::cout << tree->getTotalHeight();					//restructure
*/

	AVLTree* tree = new AVLTree();
	double numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
		11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 
		39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74 };
	for (double number : numbers) {
		tree->insert(new Node(number));
	}
	std::cout << tree->getTotalHeight()<<std::endl;



	//heightCompare();

	return 0;
}
double fRand(double fMin, double fMax)
{
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

void heightCompare() {
	for (int i = 100; i <= 100000; i = i * 10) {
		AVLTree* tree = new AVLTree();
		AVLTree* tree2 = new AVLTree();
		for (int j = 1; j <= i; j++) {
			tree->insert(new Node(fRand(1000, 2000)));
			tree2->insertWithoutRebalance(new Node(fRand(1000, 2000)));
		}
		std::cout << "Height of Restructured AVL when size: " << i << " is: " << tree->getTotalHeight()<< std::endl;
		std::cout << "Height of Non Structured AVL when size: " << i << " is: " << tree2->getTotalHeight() << std::endl;
		
	}
}