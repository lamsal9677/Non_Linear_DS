#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <forward_list>


int main() {
	std::string str;
	std::ifstream txt_file;
	std::unordered_map<int, std::forward_list<int>> fbGraph;
	txt_file.open("facebook-links.txt");
	if (!txt_file.is_open()) {
		std::cout << "The file cant be opened";
		return EXIT_FAILURE;
	}
	while (getline(txt_file, str)) {
		std::istringstream iss(str);
		std::string a, b;
		iss >> a >> b;
		int num1 = stoi(a);
		int num2 = stoi(b);

		auto pos = fbGraph.find(num1);
		//adding key value pair
		{
			if (pos == fbGraph.end()) {//num1 does not exist in graph
				std::forward_list<int> node;
				node.push_front(num2);
				fbGraph.insert(std::make_pair(num1, node));
			}
			else {
				bool contains = false;
				for (int& b : pos->second) {//checking if the edge exists or not
					if (b == num2) { contains = true; }
				}
				if (!contains) {
					pos->second.push_front(num2);
				}
			}
		}
		//adding value key pair
		{
			pos = fbGraph.find(num2);
			if (pos == fbGraph.end()) {//num2 does not exist in graph
				std::forward_list<int> node;
				node.push_front(num1);
				fbGraph.insert(std::make_pair(num2, node));
			}
			else {
				bool contains = false;
				for (int& b : pos->second) {//checking if the edge exists or not
					if (b == num1) { contains = true; }
				}
				if (!contains) {
					pos->second.push_front(num1);
				}
			}
		}
	}

	int verticesCountMain = 0;
	auto itr2 = fbGraph.begin();
	int degreeCount = 0;
	int numberofMainEdges = 0;
	double result = 0.0;
	
	int count = 0;
	//looping through all vertices(i.e. keys in the hashtable)
	for (auto itr = fbGraph.begin(); itr != fbGraph.end(); itr++)
	{
		verticesCountMain++;
		numberofMainEdges = 0;
		degreeCount = 0;
		for (int& b : itr->second) {
			numberofMainEdges++;
			itr2 = fbGraph.find(b);
			for (int& c : itr2->second) {
				degreeCount++;
			}
		}
		result = result + ((double)degreeCount / (double)numberofMainEdges);
	}
	std::cout << result / (double)verticesCountMain << std::endl;
	txt_file.close();
	return 0;
}