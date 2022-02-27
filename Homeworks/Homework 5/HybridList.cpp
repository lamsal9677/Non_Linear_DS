#include <iostream>
#include <string>
#include <stdexcept>
#include "HybridList.h"
using namespace std;

HybridList::HybridList() {}

HybridList::HybridList(int blockSize) {
	if (blockSize <= 0)
		throw out_of_range("Invalid block size " + to_string(blockSize));
	this->blockSize = blockSize;
}

HybridList::~HybridList() {
	clear();
}

int HybridList::size() const {
	return numElements;
}

int HybridList::capacity() const {
	return numBlocks * blockSize;
}

int HybridList::block_size() const {
	return blockSize;
}

HybridListNode* HybridList::front() const {
	return head;
}

HybridListNode* HybridList::back() const {
	return tail;
}

double& HybridList::at(int index) const {
	HybridListNode* curNode = head;
	int elementsSearched = 0;

	if (index < 0 || index >= numElements)
		throw out_of_range("Invalid index " + to_string(index));

	// Iterate through all blocks to identify block containing the index
	while (curNode != nullptr) {
		if (index < elementsSearched + curNode->size()) {
			// Element is in this block so just return the correct element from
			// this block
			return curNode->at(index - elementsSearched);
		}
		// Element is not in this block so add the number of elements in the
		// block to the number of elements searched
		elementsSearched += curNode->size();
		curNode = curNode->next;
	}

	// Iterator went beyond last block so something went horribly wrong
	abort();
}

void HybridList::push_back(double value) {
	if (numBlocks == 0) {
		// Hybrid list is empty so creating a new node that will be both the head
		// and tail and append the element to it
		HybridListNode* newTail = new HybridListNode(blockSize);
		newTail->push_back(value);
		tail = newTail;
		head = newTail;
		numBlocks = 1;
	}
	else if (tail->size() == blockSize) {
		// Tail node is full so create a new tail node and copy the back half of
		// the old tail node to the new tail node
		HybridListNode* newTail = new HybridListNode(blockSize);

		// Copy just under half of elements from old tail to new tail
		for (int i = blockSize / 2 + 1; i < blockSize; i++)
			newTail->push_back(tail->at(i));
		tail->resize(blockSize / 2 + 1);
		//cout << tail->size() << endl;
		// Append new item to new tail
		newTail->push_back(value);
		tail->next = newTail;
		//cout << newTail->size() << endl;
		//cout << "Tail: " << tail << endl;
		//cout << "New tail: " << newTail << endl;
		tail = newTail;
		numBlocks++;
	}
	else
		tail->push_back(value);	// Tail isn't full so just append to tail

	numElements++;
}

void HybridList::pop_back() {
	
	//if no element in the list then throw an exception
	if (head == nullptr) {
		throw std::out_of_range("List has no elements");
		return;
	}


	//if there is 1 element in our Node
	if (tail->size() - 1 == 0) {
		HybridListNode* curr = head->next;
		//if there is only 1 Node
		if (curr == nullptr) {
			head = nullptr;
			tail = nullptr;
			numBlocks = 0;
			return;
		}
		
		//if there is 2 Nodes
		if (curr == tail) {
			tail = nullptr;
			head->next = tail;
			numBlocks--;
			return;
		}

		//if there is 3 or more Node
		while (curr != nullptr) {
			if (curr->next == tail) {
				tail = nullptr;
				tail = curr;
				tail->next = nullptr;
				numBlocks--;
				return;
			}
			curr = curr->next;
		}
	}

	//if number of elements is 2,3,4
	if (tail->size() - 2 >= 0) {
		HybridListNode* newNode = new HybridListNode(blockSize);
		//push n-1 items into new node
		for (int i = 0; i < tail->size() - 1; i++) {
			newNode->push_back(tail->at(i));
		}
		
		HybridListNode* curr = head->next;
		
		//case when there is only 1 node
		if (curr == nullptr) {
			head = nullptr;
			tail = nullptr;
			head = newNode;
			tail = newNode;
			head->next = nullptr;
			tail->next = nullptr;
			return;
		}
		
		//case when there is 2 nodes
		if (curr == tail) {
			tail = nullptr;
			tail = newNode;
			head->next = tail;
			return;

		}

		//case when there is 3 or more nodes
		while (curr != nullptr){
			if (curr->next == tail) {
				tail = nullptr;
				tail = newNode;
				curr->next = tail;
				return;
			}
			curr = curr->next;
		}	
	}
}


void HybridList::erase(int index) {
	

	HybridListNode* tempPointer = nullptr;
	HybridListNode* currPrev = head;
	HybridListNode* curr = head->next;
	
	int currInd = 0;
	bool found = false;

	tempPointer = new HybridListNode(blockSize);
	for (int i = 0; i < head->size(); i++) {
			
		if (index == currInd) {
			std::cout << "Removed Head :" << head->at(i);
			found = true;
		}
		else {
			tempPointer->push_back(head->at(i));
		}
		currInd++;
	}

	if (found) {
		tempPointer->next = head->next;
		head = nullptr;
		head = tempPointer;

		if (tempPointer->size() == 0) {
			std::cout << "NULLLLLLLLLLLLLLLLL";
		}
		return;
	}


	while (curr != nullptr) {
		tempPointer = nullptr;
		tempPointer = new HybridListNode(blockSize);
		for (int i = 0; i < curr->size(); i++) {
			if (index == currInd) {
				std::cout << "Removed :" << curr->at(i);
				found = true;
			}
			else {
				tempPointer->push_back(curr->at(i));
			}
			currInd++;
		}

		if (found) {
			currPrev->next = tempPointer;
			tempPointer->next = curr->next;
			curr = nullptr;
			return;
		}
		currPrev = currPrev->next;
		curr = curr->next;
	}		
}

void HybridList::clear() {
	HybridListNode* curNode = head, * nextNode = nullptr;
	// Iterate through each node starting from the head and delete it
	while (curNode != nullptr) {
		nextNode = curNode->next;
		delete curNode;
		curNode = nextNode;
	}
	head = tail = nullptr;
	numElements = numBlocks = 0;
}