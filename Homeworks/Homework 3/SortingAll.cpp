#include <vector>
#include <iostream>
#include <chrono>

int MaxNumberinVector(std::vector<int> numbers);
int LengthofMaxInteger(std::vector<int> numbers);
void insertionSort(std::vector<int>& numbers);
void bucketSort(std::vector<int>& numbers, int numBuckets);
void radixSort(std::vector<int>& numbers);

void printInsertionAverage();
void printBucketAverage();
void printRadixAverage();
void randVector(std::vector<int>& numbers, int size);
double Sort(std::vector<int>& numbers, int choice);

void Sorting() {
	printInsertionAverage();
	printBucketAverage();
	printRadixAverage();
}

void printInsertionAverage() {
	for (int i = 10; i <= 10000; i = i * 10) {
		std::vector<int> numbers(i);
		double Sum{};
		for (int j = 1; j <= 10; j++) {
			randVector(numbers, i);
			Sum = (double)Sum + (double)Sort(numbers, 1);
		}
		std::cout << "Average time for Insertion Sort of length " << i << " is " << (double)((double)Sum / (double)10) << " milliseconds" << std::endl;
	}
	std::cout << std::endl;
}
void printBucketAverage() {
	for (int i = 10; i <= 10000; i = i * 10) {
		std::vector<int> numbers(i);
		double Sum{};
		for (int j = 1; j <= 10; j++) {
			randVector(numbers, i);
			Sum = (double)Sum + (double)Sort(numbers, 2);
		}
		std::cout << "Average time for Bucket Sort of length " << i << " is " << (double)((double)Sum / (double)10) << " milliseconds" << std::endl;
	}
	std::cout << std::endl;
}
void printRadixAverage() {
	for (int i = 10; i <= 10000; i = i * 10) {
		std::vector<int> numbers(i);
		double Sum{};
		for (int j = 1; j <= 10; j++) {
			randVector(numbers, i);
			Sum = (double)Sum + (double)Sort(numbers, 3);
		}
		std::cout << "Average time for Radix Sort of length " << i << " is " << (double)((double)Sum / (double)10) << " milliseconds" << std::endl;
	}
	std::cout << std::endl;
}


void randVector(std::vector<int>& numbers, int size) {
	for (int k = 0; k < size; k++) {
		numbers.at(k) = rand() % 1000;
	}
}
double Sort(std::vector<int>& numbers, int choice) {
	if (choice == 1) {
		auto startRadix = std::chrono::high_resolution_clock::now();
		insertionSort(numbers);
		auto stopRadix = std::chrono::high_resolution_clock::now();
		auto durationRadix = duration_cast<std::chrono::microseconds>(stopRadix - startRadix);
		double difference = (double)((double)durationRadix.count() / (double)1000);
		return difference;
	}

	if (choice == 2) {
		auto startRadix = std::chrono::high_resolution_clock::now();
		bucketSort(numbers, 10);
		auto stopRadix = std::chrono::high_resolution_clock::now();
		auto durationRadix = duration_cast<std::chrono::microseconds>(stopRadix - startRadix);
		double difference = (double)((double)durationRadix.count() / (double)1000);
		return difference;
	}

	if (choice == 3) {
		auto startRadix = std::chrono::high_resolution_clock::now();
		radixSort(numbers);
		auto stopRadix = std::chrono::high_resolution_clock::now();
		auto durationRadix = duration_cast<std::chrono::microseconds>(stopRadix - startRadix);
		double difference = (double)((double)durationRadix.count() / (double)1000);
		return difference;
	}
	return 0;
}