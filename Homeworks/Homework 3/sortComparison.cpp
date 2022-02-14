#include <iostream>
#include <vector>

int MaxNumberinVector(std::vector<int> numbers);
int LengthofMaxInteger(std::vector<int> numbers);
void insertionSort(std::vector<int>& numbers);
void bucketSort(std::vector<int>& numbers, int numBuckets);
void radixSort(std::vector<int>& numbers);

void Sorting();

int main() {
	std::vector<int>  numbers{ 32, 6, 15, 3, 20, 100 };
	//insertionSort(numbers);
	//bucketSort(numbers, 10);
	//radixSort(numbers);
	//for (int i = 0; i < numbers.size(); i++) {
	//	std::cout << numbers[i] << " ";
	//}
	Sorting();

	return 0;
}

int MaxNumberinVector(std::vector<int> numbers) {
	int maxNumber{};
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] > maxNumber)
			maxNumber = numbers[i];
	}
	return maxNumber;
}
int LengthofMaxInteger(std::vector<int> numbers) {

	int maxValue{ MaxNumberinVector(numbers) };

	if (maxValue == 0) {
		return 1;
	}

	if (maxValue > 0) {
		int length{ 0 };
		//find the length of the number
		while (maxValue > 0) {
			length++;
			maxValue = maxValue / 10;
		}
		return length;
	}
}
void insertionSort(std::vector<int>& numbers) {

	if (numbers.size() == 0 || numbers.size() == 1) {
		return;
	}

	int i = 1;//Starting at i = 1 beause we dont need to check the first one
	int j = i;
	int tempValue{};
	for (; i < numbers.size(); i++) {
		j = i;
		while (j > 0) {
			if (numbers[j] < numbers[j - 1]) {
				tempValue = numbers[j - 1];
				numbers[j - 1] = numbers[j];
				numbers[j] = tempValue;
			}
			j--;
		}
		//for (int x = 0; x < numbers.size(); x++) {
		//	std::cout << numbers[x] << " ";
		//}
		//std::cout << std::endl;
	}
}
void bucketSort(std::vector<int>& numbers, int numBuckets) {

	//size = 1 return
	if (numbers.size() == 0 || numbers.size() == 1) {
		return;
	}

	int maxValue{ MaxNumberinVector(numbers) };
	int bucketIndex{ 0 };
	std::vector<std::vector<int>> buckets(numBuckets);

	//Put values in the appropriate bucket
	for (int j = 0; j < numbers.size(); j++) {
		bucketIndex = numbers[j] * (numBuckets / (maxValue + 1));
		buckets[bucketIndex].push_back(numbers[j]);
	}

	numbers.clear();//clear the list so that it can be updated
	//sort the buckets and add into the original vector
	for (int k = 0; k < buckets.size(); k++) {
		insertionSort(buckets[k]);
		numbers.insert(numbers.end(), buckets[k].begin(), buckets[k].end());
	}
}
void radixSort(std::vector<int>& numbers) {
	if (numbers.size() == 0 || numbers.size() == 1) {
		return;
	}
	int MaxLengthInteger{ LengthofMaxInteger(numbers) };
	std::vector<std::vector<int>> places(10);

	int currBase{ 1 };
	int currNumber{};
	for (int i = 0; i < MaxLengthInteger; i++) {
		for (int j = 0; j < numbers.size(); j++) {
			currNumber = numbers[j] / (currBase);
			places[currNumber % 10].push_back(numbers[j]);
		}
		numbers.clear();
		for (int k = 0; k < places.size(); k++) {
			int l = 0;
			for (; l < places[k].size(); l++) {
				numbers.push_back(places[k][l]);
			}
			places[k].clear();//clearing the index to be used in another loop
		}
		currBase = currBase * 10;
	}
}