#ifndef BOUNDEDARRAY_H
#define BOUNDEDARRAY_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;


class BoundedArray {
public:
	BoundedArray();
	BoundedArray(int numElements);
	BoundedArray(int numElements, int maxNumElements);


	void resize(int newSize);
	//void resize_maxnumElements(int newSize);


	void push_back(double value);
	void pop_back();
	void insert(int index, double value);
	void erase(int index);
	void clear();
private:
	int max_num_elements;
	int numElements;
	double *elements;
};

#endif // !BOUNDEDARRAY_H