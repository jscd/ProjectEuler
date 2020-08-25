#include <iostream>
#include <vector>
#include <cstdint>

typedef uint64_t val_t;


bool isDuodigit(val_t);
val_t smallestDuoMult(val_t const);
std::vector<val_t> listOfSmallestDuos(val_t const);


constexpr val_t GOAL_VAL = 500;

int main() {
	std::vector<val_t> list = listOfSmallestDuos(GOAL_VAL);

	val_t sum = 0;

	for(int i = 0; i < GOAL_VAL; i++){
		// std::cout << (i+1) << " : " << list.at(i) << "\n";
		sum += list.at(i);
	}

	std::cout << "INT RESULT: " << sum << "\n";

	double res = sum;
	val_t power = 0;
	while(sum > 10){
		sum /= 10;
		power++;
	}

	std::cout << "\nFINAL RESULT: " << res << "\n";

}

std::vector<val_t> listOfSmallestDuos(val_t const k) {
	std::vector<val_t> lst{};

	for(val_t n = 1; n <= k; n++){
		lst.push_back(smallestDuoMult(n));
	}

	return lst;
}

val_t smallestDuoMult(val_t const val) {
	for(val_t i = 1 ;; ++i){
		val_t mult = val * i;
		if(isDuodigit(mult)) return mult;
	}
}

bool isDuodigit(val_t num) {
	constexpr val_t V = 100; 

	uint8_t const d1 = num % 10;
	uint8_t d2 = V;

	while(num > 0){
		uint8_t const digit = num % 10;
		num /= 10;

		if(digit == d1 || digit == d2) continue;

		if(d2 == V){
			d2 = digit;
		} else {
			return false;
		}
	}

	return true;
}