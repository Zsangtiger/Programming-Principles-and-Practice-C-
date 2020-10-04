#pragma once
/*
14. Design and implement a Money class for calculations involving dollars and cents where
arithmetic has to be accurate to the last cent using the 4/5 rounding rule (.5 of a cent rounds up;
anything less than .5 rounds down). Represent a monetary amount as a number of cents in a
long int, but input and output as dollars and cents, e.g., $123.45. Do not worry about amounts
that don’t fit into a long int.

15. Refine the Money class by adding a currency (given as a constructor argument). Accept a
floating-point initializer as long as it can be exactly represented as a long int. Don’t accept
illegal operations. For example, Money*Money doesn’t make sense, and
USD1.23+DKK5.00 makes sense only if you provide a conversion table defining the
conversion factor between U.S. dollars (USD) and Danish kroner (DKK).

*/
#include <iostream>
#include <vector>

namespace moneySpace{
	
	struct Currency
	{
		std::string name;
		double rateToDollar;
	};
class Money
{
public:
	double getAmount() const ;
	std::string getCurrency() const ;
	Money(double, std::string);
	Money(double);
	Money();
private:
	long int cents;
	Currency c;
};

bool is_valid(double);
int convertToCents(double b);
std::ostream& operator<<(std::ostream& os, Money m);
std::istream& operator>>(std::istream& is, Money &m);


const Currency eur{ "€", 1.1 };
const Currency dollar{ "$",1 };
const Currency eur2{ "eur",1.1 };

static std::vector<Currency> currTable{eur,dollar,eur2};
Currency findConv(std::string);
};

