#include "CharacterFrequencies.h"

// Initialize empty instance with no characters
CharacterFrequencies::CharacterFrequencies() {
	frequencies;
};

// Initialize instance with character frequencies from line
CharacterFrequencies::CharacterFrequencies(string line) {
	frequencies;
	readString(line);
};

// Read line and add character frequencies to already stored frequencies
void CharacterFrequencies::readString(string line) {
	for (int i = 0; i < line.length(); i++) {
		bool exists = false;
		for (int j = 0; j < frequencies.size(); j++) {
			if (frequencies[j].first == line[i]) {
				char character = frequencies[j].first;
				int occurence = frequencies[j].second;
				frequencies[j] = make_pair(character, ++occurence);
				exists = true;
			}
		}
		if (!exists) {
			frequencies.push_back(make_pair(line[i], 1));
		}
	}
};

// Reset all character frequencies to 0
void CharacterFrequencies::reset() {
	frequencies.clear();
};

// Return the frequency of character c
int CharacterFrequencies::getFrequency(char c) {
	for (int j = 0; j < frequencies.size(); j++) {
		if (frequencies[j].first == c) {
			return frequencies[j].second;
		}
	}
};

// Print the frequencies of all characters with non-zero frequencies to
// the console in the following format:
// r: 4
// o: 8
// w: 2
// n: 2
// Do not print a line for any element that has 0 frequency!
void CharacterFrequencies::printFrequencies() {
	for (int i = 0; i < frequencies.size(); i++) {
		if (frequencies[i].second > 0) {
			cout << frequencies[i].first << ": " << frequencies[i].second << '\n';
		}
	}
};