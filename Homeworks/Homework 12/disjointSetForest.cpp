#include <vector>
#include <iostream>
#include <string>

class Node {
public:
	int value = 0;
	int rank = 0;
	Node* parent = nullptr;
	Node(int value) { this->value = value; }
};

void makeSet(Node* element);
Node* findSet(Node* element, bool pathCompression);
void unionSet(Node* element1, Node* element2, bool unionByRank,bool pathCompression);
void Link(Node* element1, Node* element2);
void printAllElements(std::vector<Node*> elements);


void makeSet(Node* element){
	element->parent = element;
	element->rank = 0;
}

//implemented path compression
Node* findSet(Node* element, bool pathCompression) {
	if (element != element->parent) {
		if (pathCompression) {
		element->parent = findSet(element->parent, pathCompression);
		return element->parent;
		}
		else {
			findSet(element->parent, pathCompression);
			element = element->parent;
			//return element->parent;
		}
	}
	element = element->parent;
	return element->parent;
}


void unionSet(Node* element1, Node* element2, bool unionByRank, bool pathCompression) {
	
	Link(findSet(element1, pathCompression), findSet(element2, pathCompression));
	//if (!unionByRank) {
	//	findSet(element1, pathCompression)->parent = findSet(element2, pathCompression)->parent;
	//}
	//else {
	//	Link(findSet(element1, pathCompression), findSet(element2, pathCompression));
	//}
}

void Link(Node* element1, Node* element2) {
	if (element1->rank > element2->rank) {
		element2->parent = element1;
	}
	else {
		element1->parent = element2;
		if (element1->rank == element2->rank) {
			element2->rank = element2->rank + 1;
		}
	}
}


void printAllElements(std::vector<Node*> elements) {
	std::cout << "Element  Parent  Set Representative" << std::endl;
	for (int i = 0; i < elements.size(); i++) {
		std::cout << elements.at(i)->value << "  "
			<< elements.at(i)->parent->value << "  "
			<< findSet(elements.at(i), false)->value << std::endl;
	}
}

int main() {

	bool unionByRank = true, pathCompression = true;
	int numElements = 5;
	std::vector<Node*> elements(numElements);
	for (int i = 0; i < numElements; i++)
		elements.at(i) = new Node(i);

	for (int i = 0; i < numElements; i++) {
		makeSet(elements.at(i));
	}
	printAllElements(elements);

	
	unionSet(elements.at(0), elements.at(1), unionByRank, pathCompression);
	printAllElements(elements);
	unionSet(elements.at(0), elements.at(2), unionByRank, pathCompression);
	printAllElements(elements);
	unionSet(elements.at(3), elements.at(4), unionByRank, pathCompression);
	printAllElements(elements);
	unionSet(elements.at(0), elements.at(4), unionByRank, pathCompression);
	printAllElements(elements);
	
	return 0;
}