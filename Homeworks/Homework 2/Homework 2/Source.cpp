#include "CharacterFrequencies.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>


int main() {
	std::string line2 = "Twinkle twinkle little star, how I wonder what you are.";
	std::cout << line2 << endl;
	CharacterFrequencies line2CharFreq(line2);
	//CharacterFrequencies line2CharFreq("abc");
	
	//line2CharFreq.printFrequencies();
	//cout << line2CharFreq.getFrequency('a');
	//line2CharFreq.readString("abc");
	//line2CharFreq.printFrequencies();
	//cout << line2CharFreq.getFrequency('a');


	line2CharFreq.printFrequencies();
	line2CharFreq.reset();
	line2CharFreq.readString(line2);
	line2CharFreq.printFrequencies();
	//cout<<"FREQUENCY" << line2CharFreq.getFrequency('T');
	return 0;
}

