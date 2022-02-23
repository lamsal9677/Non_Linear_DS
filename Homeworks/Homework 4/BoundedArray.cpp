#include "BoundedArray.h"


BoundedArray::BoundedArray() {
	
}

BoundedArray::BoundedArray(int numElements) {
	maxNumElements = 100;
	resize(numElements);

	elements = new double[maxNumElements];
	for (int i = 0; i < maxNumElements; i++)
		elements[i] = 0;
}

BoundedArray::BoundedArray(int numElements, int maxNumElements) {
	setMaxSize(maxNumElements);
	resize(numElements);
}

BoundedArray::BoundedArray(BoundedArray& b) {
	//copy
}

BoundedArray::~BoundedArray() {
	delete elements;
}



int BoundedArray::size() {
	return numElements;
}
int BoundedArray::capacity() {
	return maxNumElements;
}

double& BoundedArray::operator[](int index) {
	return elements[index];
}
double& BoundedArray::at(int index) {
	if (index >= numElements)
		throw std::out_of_range("Invalid index " + std::to_string(index));
	return operator[](index);
}
double* BoundedArray::data() {
	return elements;
}


BoundedArray& BoundedArray::operator=(BoundedArray& b) {
	numElements = b.size();
	setMaxSize(b.capacity());

	for (int i = 0; i < numElements; i++)
		elements[i] = b[i];
	for (int i = numElements; i < maxNumElements; i++)
		elements[i] = 0;
	
	return *this;
}


void BoundedArray::resize(int newSize) {
	if (newSize < 0) {
		throw std::out_of_range("Invalid size " + std::to_string(newSize));
	}

	if (newSize > maxNumElements) {
		increaseMaxSize(newSize);
	}
	for (int i = numElements; i < maxNumElements; i++)
		elements[i] = 0;
	this->numElements = newSize;
}
void BoundedArray::push_back(double value) {
	if (numElements >= maxNumElements)
		increaseMaxSize(0);
	elements[numElements] = value;
	numElements++;
}
void BoundedArray::pop_back() {
	if (numElements == 0)
		throw std::out_of_range("Array has no elements");

	numElements--;
	elements[numElements] = 0;
}



void BoundedArray::insert(int index, double value) {
	if (index < 0)
		throw std::out_of_range("Invalid index " + std::to_string(index));
		
	if (numElements >= maxNumElements)
		increaseMaxSize(numElements + 1);

	for (int i = numElements; i > index; i--)
		elements[i] = elements[i - 1];
	elements[index] = value;
	numElements++;
}



void BoundedArray::erase(int index) {
	if (index >= numElements || index < 0)
		throw std::out_of_range("Invalid index " + std::to_string(index));

	elements[index] = 0;
	for (int i = index; i < numElements - 1; i++)
		elements[i] = elements[i + 1];
	numElements--;
}
void BoundedArray::clear() {
	for (int i = 0; i < numElements; i++) {
		elements[i] = 0;
	}
	numElements = 0;
}

void BoundedArray::setMaxSize(int maxNumElements) {
	this->maxNumElements = maxNumElements;//set maxsize
	double* elements_new = new double[maxNumElements];//declare new 
	for (int i = 0; i < numElements && i < maxNumElements; i++) {//copy all data
		elements_new[i] = elements[i];
	}
	delete elements;//remove old one
	elements = elements_new;//assign new to old
}


void BoundedArray::increaseMaxSize(int newSize) {
	//loop and increase maxNumElements unless it is bigger	
	do
		maxNumElements *= 2;
	while (newSize > maxNumElements);

	double* elements_new = new double[maxNumElements];//declare new 
	for (int i = 0; i < numElements && i < maxNumElements; i++) {//copy all data
		elements_new[i] = elements[i];
	}
	delete elements;//remove old one
	elements = elements_new;//assign new to old
}