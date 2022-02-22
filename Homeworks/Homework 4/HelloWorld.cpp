#include <iostream>

#include "BoundedArrayConst.h"
#include "BoundedArray.h"



int main() {
	

	BoundedArray arr3(50,500);
	
	cout << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;
	
	arr3.clear();
	cout << "CLEAR - " << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;
	
	arr3.resize(20);
	cout << "RESIZE - " << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;
	
	arr3.push_back(1.0);
	cout << "PUSH BACK - " << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;
	
	arr3.pop_back();
	cout << "POP BACK - " << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;
	
	arr3.insert(1,2.99);
	cout << "INSERT - " << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;
	
	cout << "overload [] - " << "Value: " << arr3[1] << endl;
	
	cout << "At - " << "Value: " << arr3.at(1) << endl;

	arr3.erase(1);
	cout <<"ERASE - " << "Size: " << arr3.size() << " Capacity: " << arr3.capacity() << endl;

	


	return 0;
}