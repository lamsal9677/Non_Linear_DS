#include <string>
#include <stdexcept>
#include "BoundedArray.h"
#include <iostream>


BoundedArray::BoundedArray() {
	this->max_num_elements = 100;
	this->numElements = 0;

	this->elements = new double[max_num_elements];
	for (int i = 0; i < max_num_elements; i++)
		elements[i] = 0;
}

BoundedArray::BoundedArray(int numElements) {
	this->max_num_elements = 100;
	resize(numElements);

	this->elements = new double[max_num_elements];
	for (int i = 0; i < max_num_elements; i++)
		elements[i] = 0;
}

BoundedArray::BoundedArray(int numElements, int maxNumElements) {
	this->max_num_elements = maxNumElements;
	resize(numElements);
	
	this->elements = new double[max_num_elements];
	for (int i = 0; i < max_num_elements; i++)
		elements[i] = 0;
}

void BoundedArray::resize(int newSize) {
	if (newSize > this->max_num_elements || newSize < 0) {
		throw std::out_of_range("Invalid size " + std::to_string(newSize));
	}
	this->numElements = newSize;
}






void BoundedArray::push_back(double value) {}
void BoundedArray::pop_back() {}
void BoundedArray::insert(int index, double value) {}
void BoundedArray::erase(int index) {}
void BoundedArray::clear() {}