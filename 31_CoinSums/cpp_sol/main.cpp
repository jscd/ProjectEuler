#include <iostream>
#include <cstdint>
#include <array>
#include <tuple>

constexpr int NUM_PIECES = 8;
constexpr std::array<int, NUM_PIECES> pieces{1, 2, 5, 10, 20, 50, 100, 200};

uint64_t waysToBreak(int, int);

int main() {
	for(int piece : pieces)
		std::cout << piece << ": " << waysToBreak(piece, 8) << "\n";
	// std::cout << waysToBreak(200) << "\n";
}


// This function should give the number of different ways
// to break up a denomination of currency, including the
// piece itself. For example, 2p can be broken into 2 poss-
// iblities—either 1 2p piece or 2 1p pieces.
uint64_t waysToBreak(int piece, int limit) {
	static std::array<std::tuple<bool, uint64_t>, 2000> wtb{};

	if(piece == 0)
		return 1;

	if(piece < 0)
		return 0;

	if(limit <= 0 && piece >= 1)
		return 0;

	if(std::get<0>(wtb[piece-1])) return std::get<1>(wtb[piece-1]);

	return waysToBreak(piece, limit - 1) + waysToBreak(piece - pieces[limit - 1], limit);
}