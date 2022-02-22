#ifndef BOUNDEDARRAY_H
#define BOUNDEDARRAY_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;


class BoundedArray {
public:
	BoundedArray(); //complete
	BoundedArray(int numElements); //complete
	BoundedArray(int numElements, int maxNumElements); //complete

	int size(); //complete
	int capacity(); //complete


	double& operator[](int index);//complete
	double& at(int index);//complete
	double* data();//complete


	void resize(int newSize);//done
	void push_back(double value);//done
	void pop_back();//done
	void insert(int index, double value);//done
	void erase(int index);//done
	void clear();//done
private:
	int maxNumElements;
	int numElements;
	double *elements;
};

#endif // !BOUNDEDARRAY_H