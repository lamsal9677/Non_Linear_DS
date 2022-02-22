#include <string>
#include <stdexcept>
#include "BoundedArray.h"
#include <iostream>


BoundedArray::BoundedArray() {
	maxNumElements = 100;
	this->numElements = 0;

	elements = new double[maxNumElements];
	for (int i = 0; i < maxNumElements; i++)
		elements[i] = 0;
}
BoundedArray::BoundedArray(int numElements) {
	maxNumElements = 100;
	resize(numElements);

	elements = new double[maxNumElements];
	for (int i = 0; i < maxNumElements; i++)
		elements[i] = 0;
}
BoundedArray::BoundedArray(int numElements, int maxNumElements) {
	this->maxNumElements = maxNumElements;
	resize(numElements);
	
	elements = new double[maxNumElements];
	for (int i = 0; i < maxNumElements; i++)
		elements[i] = 0;
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


void BoundedArray::resize(int newSize) {
	if (newSize > maxNumElements || newSize < 0) {
		throw std::out_of_range("Invalid size " + std::to_string(newSize));
	}
	this->numElements = newSize;
}





void BoundedArray::push_back(double value) {
	if (numElements >= maxNumElements)
		throw std::out_of_range("Array has reached its maximum capacity");

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
	if (index >= numElements || index < 0)
		throw std::out_of_range("Invalid index " + std::to_string(index));
	if (numElements >= maxNumElements)
		throw std::out_of_range("Array has reached its maximum capacity");

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