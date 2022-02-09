#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
	std::ifstream txt_file; //Input stream class to operate on file
	int char_occurrences = 0;//Counts Character Occurence in the file
	std::vector<int> char_indexes; //A Vector to store the index of the characters found

	txt_file.open("input.txt", std::ios::in);//reads in a file named input.txt and open the file
	std::cout << EXIT_FAILURE << std::endl;
	//If the file is not open at this point, return EXIT_FAILURE and print to the screen
	if (!txt_file.is_open()) {
		std::cout << "The file cant be opened";
		return EXIT_FAILURE;
	}
		
	//Make a string and input the content of the file into str
	//getline is used because there is only one line of text in the file
	std::string str;
	std::getline(txt_file, str);


	//Prompt user to input a character (this is a valid character)
	std::cout << "Enter the character to search for: ";
	char inputChar{};
	std::cin >> inputChar;

	/*Loop from index 0 to index length() - 1
		Increment char_occurrences for every user-input char found
		Add index to char_indexes for every user-input char found*/
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == inputChar) {
			char_occurrences++;
			char_indexes.push_back(i);
		}
	}

	//cout the result to the screen
	std::cout << "The number of occurrences of the character " << inputChar << " is " << char_occurrences;
	
	//char_occurrences > 0 means there is atleast one item in the vector
	
	if (char_occurrences > 0) {
		std::cout << "\nThe indices of the character positions are ";
		
		//loop through the vector and display all index
		int currentPointer = 0;
		while (currentPointer < char_indexes.size()) {
			std::cout << char_indexes.at(currentPointer) << ' ';
			currentPointer++;
		}
	}
	txt_file.close();//closing the file
	return 0;
}
