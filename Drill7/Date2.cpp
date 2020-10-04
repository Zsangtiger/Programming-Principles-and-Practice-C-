#include "Date2.h"
#include <vector>



// Chrono.cpp
namespace Chrono2 {

	long toDays(int year) {
		long sum = 0;
		for (int i = year; i > 1970; i--)
		{
			if (leapyear(i))
				sum += 366;
			else
				sum += 365;
		}
		return sum;
	}
	int daysInMonth(int, Month);
	int toDays(int y, Month m)
	{
		int sum = 0;
		for (int i = int(m)-1; i > 0; i--)
			sum += daysInMonth(y, Month(i));
		return sum;
	}

	std::ostream& operator<<(std::ostream& os, Month m) {
		os << int(m);
		return os;
	}
	// member function definitions:
	Date::Date(int yy, Month mm, int dd)
		: d{toDays(yy) + toDays(yy,mm)+dd-1 }
	{
		std::cout << "Initilaized to: " << d << '\n';
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}
	
	const Date& default_date()
	{
		static Date dd{ 2001,Month::jan,1 }; // start of 21st century
		return dd;
	}
	Date::Date()
		:d{ 0 }
	{
	}

	int daysInMonth(int y, Month m)
	{
		int days_in_month = 31; // most months have 31 days
		switch (m) {
		case Month::feb: // the length of February varies
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30; // the rest have 30 days
			break;
		}
		return days_in_month;
	}

	void Date::add_day(int n)
	{
		d += n;
	}
	Month Date::month() const 
	{
		int monthDays = subtractYears()+1;
		int month = 1;
		while (monthDays > 0)
		{
			int diff = monthDays - daysInMonth(year(), Month(month));
			if (diff > 0)
			{
				monthDays = diff;
				month++;
			}
			else
				break;
		}
		return Month(month);
	}
	int Date::correctYear() const
	{
		int sum = 0;
		long days = d+1;
		while (days >= 366)
		{
			if (leapyear(1970 + sum))
				days -= 366;
			else
				days -= 365;
			sum++;
		}
		return 1970+sum;
	}
	int Date::subtractMonths() const 
	{
		int ld = subtractYears()+1;
		int month = 1;
		while (ld > 0) {
			int test = ld-daysInMonth(year(), Month(month));
			if (test > 0)
			{
				ld = test;
				month++;
			}
			else
				return ld;
		}
	}
	int Date::subtractYears()const 
	{
		int rawYears = d / 365;
		int leapDays = (rawYears + 2) / 4;
		leapDays -= rawYears + 30 / 100;
		leapDays += rawYears + 30 / 400;
		return d - ((rawYears - leapDays) * 365 + leapDays * 366);
	}
	int Date::year() const 
	{
		//Dividing with 365 causes a remainder of 1 with every leap year thus i calculate the number of leap years and subtract leap days.
		int rawYears = d / 365;
		int leapDays = (rawYears + 2) / 4;
		leapDays -= rawYears + 30 / 100;
		leapDays += rawYears + 30 / 400;
		return 1970+(d-leapDays) / 365; 
	}
	void Date::add_month(int n)
	{
		for (int i = 0; i < n; i++) {
			d += daysInMonth(this->year(), this->month());
		}
		
	}
	void Date::add_year(int n)
	{
		for (int i = 0; i < n; i++) 
		{
			if (leapyear(correctYear() + i))
				d += 366;
			else
				d += 365;
		}
	}
	// helper functions:
	bool is_date(int y, Month m, int d)
	{
		// assume that y is valid
		if (d <= 0) return false; // d must be positive
		if (m < Month::jan || Month::dec < m) return false;
		int days_in_month = 31; // most months have 31 days
		switch (m) {
		case Month::feb: // the length of February varies
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun: case Month::sep: case Month::nov:
			days_in_month = 30; // the rest have 30 days
			break;
		}
		if (days_in_month < d) return false;
		if (y < 1970)
			return false;
		return true;
	}
	int Date::day() const {
		return subtractMonths();
	};
	
	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << d.month()
			<< ',' << d.day() << ')';
	}
	std::istream& operator>>(std::istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
		if (!is) return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')') { // oops: format error
			is.clear(std::ios_base::failbit); // set the fail bit
			return is;
		}
		dd = Date(y, Month(m), d); // update dd
		return is;
	}
	enum class Day {
		sunday = 1, monday, tuesday, wednesday, thursday, friday, saturday
	};
	Day day_of_week(const Date& d)
	{
		// you have two options for this first is key value method, the other one is Zeller's rule.
		//A quick method of storing the values for each month required in the calculation
		static const std::vector<int> monthValueTable{ 1,4,4,0,2,5,0,3,6,1,4,6 };
		static const std::vector<int> centuryCode{ 4,2,0,6 };
		//Integer division truncates and we need that.
		int num = d.year() / 100 / 4;
		int num2 = num + d.day() + monthValueTable[int(d.month()) - 1];
		if ((d.month() == Month::jan || d.month() == Month::feb) && leapyear(d.year()))
			num2--;
		//Bad for dates before 1700
		int centIndex = ((d.year() / 100) % 17) % 4;
		num2 += centuryCode[centIndex];
		num2 += d.year() % 100;
		return Day(num2 % 7);
	}
	Date next_Sunday(const Date& d)
	{
		// ...
		Date proxy{ d };
		proxy.add_day(1);
		while (day_of_week(proxy) != Day::sunday)
			proxy.add_day(1);
		return proxy;
	}
	Date next_weekday(const Date& d)
	{
		// . . .
		Date proxy{ d };
		proxy.add_day(1);
		while (day_of_week(proxy) == Day::sunday || day_of_week(proxy) == Day::saturday)
			proxy.add_day(1);
		return proxy;
	}
	bool leapyear(int y)
	{
		if (y % 4 != 0)
			return false;
		else if (y % 100 != 0)
			return true;
		else if (y % 400 != 0)
			return false;
		else
			return true;
	}
	
} // Chrono