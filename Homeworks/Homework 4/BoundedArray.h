#ifndef BOUNDEDARRAY_H
#define BOUNDEDARRAY_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;


class BoundedArray {
public:
	// Create bounded array with no elements
	BoundedArray();
	// Create bounded array with specified number of elements (all zeros). Throw
	// out of range exception for invalid size.
	BoundedArray(int numElements); 
	// Create bounded array with specified number of elements and maxsize (all zeros). Throw
	// out of range exception for invalid size.
	BoundedArray(int numElements, int maxNumElements); 
	// Create bounded array with array elements (not just pointer) copied from b
	BoundedArray(BoundedArray& b);
	~BoundedArray();//done
	

	// Return the number of elements in the bounded array
	int size();
	// Return the maximum number of elements in the bounded array
	int capacity();

	// Return element  at specified index with no error checking
	double& operator[](int index);
	// Return element at specified index. Throw out of range exception for invalid
	// index.
	double& at(int index);
	// Return pointer to array
	double* data();

	// Copy array elements from b into current array
	BoundedArray& operator=(BoundedArray& b);

	// Change number of elements in the bounded array
	void resize(int newSize);
	// Insert a new element with specified value at the end of the bounded array.
	// Throw out of range exception if the bounded array is full.
	void push_back(double value);
	// Delete last element in the bounded array. Throw out of range exception if
	// array is empty.
	void pop_back();
	// Insert a new element with specified value at the specified index, moving all
	// other elements back by 1. Throw out of range exception if index is invalid or 
	// the bounded array is full.
	void insert(int index, double value);
	// Delete element at specified index. Throw out of range exception if index is
	// invalid.
	void erase(int index);
	// Delete all elements and reset the bounded array to size 0.
	void clear();
private:
	int maxNumElements = 100;
	int numElements = 0;
	double *elements = new double[maxNumElements];

	//sets tha maxSize of the elements array
	void setMaxSize(int maxNumElements);
	//modifies the maxSize of the elements array
	void increaseMaxSize(int newSize);
};

#endif // !BOUNDEDARRAY_H