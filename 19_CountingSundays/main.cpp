#include <iostream>
#include <cstdint>

typedef uint8_t Month;
typedef uint16_t Year;
typedef uint8_t Day;
typedef uint8_t DayOfWeek;

constexpr Day DAYS_IN_WEEK = 7;
constexpr Month MONTHS_IN_YEAR = 12;

struct Date {
	Day day;
	Month month;
	Year year;
};


Day daysInMonth(Month const m, Year const y) {
	if(m == 1){
		bool const isLeap = (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
		return (isLeap) ? 29 : 28;
	}

	static constexpr Day daysInMonth[] = {
		31,	// JAN
		0,	// FEB
		31,	// MAR
		30,	// APR
		31,	// MAY
		30,	// JUN
		31,	// JUL
		31,	// AUG
		30,	// SEP
		31,	// OCT
		30,	// NOV
		31	// DEC
	};

	return daysInMonth[m];

}

void thruTheDays(Year const start, Year const end, DayOfWeek const stDOW, void (*onDay)(Date const, DayOfWeek const)) {
	DayOfWeek dow = stDOW;
	for(Year year = start; year <= end; year++){
		for(Month month = 0; month < MONTHS_IN_YEAR; month++){
			Day const dinm = daysInMonth(month, year);
			for(Day day = 0; day < dinm; day++){
				Date date;
				date.day = day;
				date.month = month;
				date.year = year;
				if(onDay != NULL) onDay(date, dow);


				dow++;
				dow %= DAYS_IN_WEEK;
			}
		}
	}
}


int numSundays = 0;

void doStuff(Date const date, DayOfWeek const dow) {
	if(date.year >= 1901){
		if(date.day == 0 && dow == 0) numSundays++;
	}
}



int main() {
	std::cout << "Calculating...\n";
	
	constexpr DayOfWeek STARTING_DOW = 1; // Monday
	constexpr Year STARTING_YEAR = 1900;
	constexpr Year ENDING_YEAR = 2000;

	thruTheDays(STARTING_YEAR, ENDING_YEAR, STARTING_DOW, doStuff);

	std::cout << "Number of Sundays: " << numSundays << "\n.";


	std::cout << "Done.\n";
}
