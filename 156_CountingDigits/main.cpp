#include <iostream>
#include <vector>




int main() {
	int inp;
	std::cin >> inp;
	unsigned int const b = inp;
	std::cin >> inp;
	unsigned int const M = inp;

	std::vector<unsigned int> digits(M);  
	for(int i = 0; i < M; i++) {
		std::cin >> inp;
		digits.push_back(inp);
	}

	
}
