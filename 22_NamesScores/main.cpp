#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
#include <algorithm>
#include <cstdint>

constexpr char* namesFilename = "p022_names.txt";

int main() {
	std::ifstream namesFile;
	namesFile.open(namesFilename);

	std::vector<std::string> names{};

	if(namesFile.is_open()){
		std::cout << "Getting names...\n";
		std::string line;
		getline(namesFile, line);
		std::regex nameRegex("\\\"(\\w+)\\\"", std::regex_constants::ECMAScript);
		auto matchesBegin = std::sregex_iterator(line.begin(), line.end(), nameRegex);
		auto matchesEnd = std::sregex_iterator();
		for(std::sregex_iterator i = matchesBegin; i != matchesEnd; i++){
			std::smatch match = *i;
			names.push_back(match[1].str());
		}


		std::cout << "Got all names!\n";

		namesFile.close();
	} else {
		std::cerr << "Could not open file!\n";
		return -1;
	}

	std::sort(names.begin(), names.end());

	uint64_t totalSum = 0;
	for(int nameIdx = 0; nameIdx < names.size(); nameIdx++){
		std::string const& name = names.at(nameIdx);
		uint64_t nameSum = 0;
		for(int i = 0; i < name.length(); i++){
			nameSum += name.at(i) - 'A' + 1;
		}

		totalSum += (nameSum * (nameIdx + 1));
	}

	std::cout << totalSum << "\n";

}