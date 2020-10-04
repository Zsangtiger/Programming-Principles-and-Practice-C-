#pragma once
/*
12. Change the representation of a Date to be the number of days since January 1, 1970 (known as
day 0), represented as a long int, and re-implement the functions from §9.8. Be sure to reject
dates outside the range we can represent that way (feel free to reject days before day 0, i.e., no
negative days).

*/

#include <iostream>

namespace Chrono2 {
	enum class Day;
	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};
	class Date {
	public:
		class Invalid { }; // to throw as exception
		Date(int y, Month m, int d); // check for valid date and initialize
		Date(); // default constructor
		// the default copy operations are fine
		// nonmodifying operations:
		int day() const;
		Month month() const;
		int year() const;
		int correctYear() const;
		// modifying operations:
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
		
	private:
		//could be unsigned
		int subtractYears() const ;
		int subtractMonths() const;
		long int d =0;
		
	};
	//std::vector<int> daysInMonthVec{ 31,28,31,30,31,30,31,31,30,31,30,31 };
	
	bool is_date(int y, Month m, int d); // true for valid date
	bool leapyear(int y); // true if y is a leap year
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	std::ostream& operator<<(std::ostream& os, const Date& d);
	std::istream& operator>>(std::istream& is, Date& dd);
	Day day_of_week(const Date& d);
	Date next_weekday(const Date& d);
	Date next_Sunday(const Date& d);
}
