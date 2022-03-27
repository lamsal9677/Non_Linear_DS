// Homework8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "RedBlackTree.h"
#include "AVLTree.h"
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std::chrono;

std::vector<double> generateRandomVector(int listSize);

void printVector(const std::vector<double>& numbers);

int main()
{
	int aSum = 0;
	int bSum = 0;
	int cSum = 0;
	int dSum = 0;
	int eSum = 0;
	int fSum = 0;

	for (int i = 100; i <= 100000; i = i * 10) {
		for (int j = 1; j <= 10; j++) {
			std::vector<double> vec = generateRandomVector(i);
			
			{
				//RBT Unsorted
				{
					RedBlackTree a;
					RBTNode* aRoot = new RBTNode(vec.front());
					auto startRBT = high_resolution_clock::now();
					a.insert(aRoot);
					for (int j = 1; j < vec.size(); j++) {
						a.insert(new RBTNode(vec.at(j)));
					}
					auto stopRBT = high_resolution_clock::now();
					auto durationRBT = duration_cast<microseconds>(stopRBT - startRBT);
					//std::cout << "RBT Insert with size : " << i << " took us : " << durationRBT.count() << " Microseconds" << std::endl;
					//std::cout << durationRBT.count() << std::endl;
				}

				//AVL Unsorted
				{
					AVLTree b;
					Node* bRoot = new Node(vec.front());
					auto startAVL = high_resolution_clock::now();
					b.insert(bRoot);
					for (int j = 1; j < vec.size(); j++) {
						b.insert(new Node(j));
					}
					auto stopAVL = high_resolution_clock::now();
					auto durationAVL = duration_cast<microseconds>(stopAVL - startAVL);
					//std::cout << "AVL Insert with size : " << i << " took us : " << durationAVL.count() << " Microseconds" << std::endl;
					//std::cout << durationAVL.count() << std::endl;
					bSum = bSum + b.get_root()->height;
				}
			}
			
			std::sort(vec.begin() + i/4, vec.end() - i/4);

			{
				//RBT Half sorted
				{
					RedBlackTree c;
					RBTNode* cRoot = new RBTNode(vec.front());
					auto startRBT = high_resolution_clock::now();
					c.insert(cRoot);
					for (int j = 1; j < vec.size(); j++) {
						c.insert(new RBTNode(vec.at(j)));
					}
					auto stopRBT = high_resolution_clock::now();
					auto durationRBT = duration_cast<microseconds>(stopRBT - startRBT);
					//std::cout << "Half Sorted RBT Insert with size : " << i << " took us : " << durationRBT.count() << " Microseconds" << std::endl;
					//std::cout << durationRBT.count() << std::endl;
				}

				//AVL Half sorted
				{
					AVLTree d;
					Node* dRoot = new Node(vec.front());
					auto startAVL = high_resolution_clock::now();
					d.insert(dRoot);
					for (int j = 1; j < vec.size(); j++) {
						d.insert(new Node(j));
					}
					auto stopAVL = high_resolution_clock::now();
					auto durationAVL = duration_cast<microseconds>(stopAVL - startAVL);
					//std::cout << "Half AVL Insert with size : " << i << " took us : " << durationAVL.count() << " Microseconds" << std::endl;
					//std::cout << durationAVL.count() << std::endl;
					dSum = dSum + d.get_root()->height;
				}
			}

			std::sort(vec.begin(), vec.end());

			{
				//RBT Full sorted
				{
					RedBlackTree e;
					RBTNode* eRoot = new RBTNode(vec.front());
					auto startRBT = high_resolution_clock::now();
					e.insert(eRoot);
					for (int j = 1; j < vec.size(); j++) {
						e.insert(new RBTNode(vec.at(j)));
					}
					auto stopRBT = high_resolution_clock::now();
					auto durationRBT = duration_cast<microseconds>(stopRBT - startRBT);
					//std::cout << "Fully Sorted RBT Insert with size : " << i << " took us : " << durationRBT.count() << " Microseconds" << std::endl;
					//std::cout << durationRBT.count() <<std::endl;
				}

				//AVL Full sorted
				{
					AVLTree f;
					Node* fRoot = new Node(vec.front());
					auto startAVL = high_resolution_clock::now();
					f.insert(fRoot);
					for (int j = 1; j < vec.size(); j++) {
						f.insert(new Node(j));
					}
					auto stopAVL = high_resolution_clock::now();
					auto durationAVL = duration_cast<microseconds>(stopAVL - startAVL);
					//std::cout << "Fully Sorted AVL Insert with size : " << i << " took us : " << durationAVL.count() << " Microseconds" << std::endl;
					//std::cout << durationAVL.count() << std::endl;
					fSum = fSum+ f.get_root()->height;
				}
			}

		}
		std::cout << aSum / 10 << std::endl;
		std::cout << bSum / 10 << std::endl;
		std::cout << cSum / 10 << std::endl;
		std::cout << dSum / 10 << std::endl;
		std::cout << eSum / 10 << std::endl;
		std::cout << fSum / 10 << std::endl;
		aSum = 0;
		bSum = 0;
		cSum = 0;
		dSum = 0;
		eSum = 0;
		fSum = 0;
	}
}

std::vector<double> generateRandomVector(int listSize) {
	std::vector<double> randomList(listSize);

	for (int i = 0; i < listSize; i++) {
		// Divide by RAND_MAX to get back a random double between 0 and 1
		randomList.at(i) = (double)rand() / RAND_MAX;
	}
	return randomList;
}
void printVector(const std::vector<double>& numbers) {
	for (unsigned int j = 0; j < numbers.size(); j++)
		std::cout << numbers.at(j) << " ";
	std::cout << std::endl;
}