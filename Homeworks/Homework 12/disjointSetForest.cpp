#include <vector>
#include <iostream>
#include <string>
#include <sstream>


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

Node* findSet(Node* element, bool pathCompression) {
	if (pathCompression) {
		if (element != element->parent) {
			element->parent = findSet(element->parent, pathCompression);
		}
	}
	else {
		findSet(element->parent, pathCompression);
	}
	return element->parent;
}

void unionSet(Node* element1, Node* element2, bool unionByRank, bool pathCompression) {
	Link(findSet(element1, false), findSet(element2, false));
}

void Link(Node* element1, Node* element2) {
	if (element1->rank > element2->rank) {
		element2->parent = element1;
	}
	else {
		element1->parent = element2;
		if (element1->rank = element2->rank) {
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

	bool unionByRank = true, pathCompression = false;
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




void avc() {
	bool unionByRank = false;
	bool pathCompression = false;

	//getting user input
	/*
	std::cout << "Union By Rank?";
	std::cin >> unionByRank;
	std::cout << std::endl;
	std::cout << "Union By Rank?";
	std::cin >> unionByRank;
	std::cout << std::endl;
	*/

	std::string userInput = "1 1 1";
	//std::cout << "Element Parent Set_Representative" << std::endl;
	//std::cin >> userInput;

	std::istringstream iss(userInput);
	std::string a, b, c;
	iss >> a >> b >> c;
	int num1 = stoi(a);
	int num2 = stoi(b);
	int num3 = stoi(c);
}