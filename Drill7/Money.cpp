#include "Money.h"
#include <exception>
#include <math.h>
using namespace moneySpace;

Currency moneySpace::findConv(std::string a) {
	for (Currency it : currTable)
		if (a == it.name)
			return it;
	throw std::exception{ "Invalid currency" };
}
double Money::getAmount() const 
{
	return cents / 100.0;
}
Money::Money(double a, std::string b) : cents{ int(findConv(b).rateToDollar * convertToCents(a)) },c{findConv(b)}
{
	if (!is_valid(a))
		throw std::exception{ "invalid initialization" };
}
Money::Money(double a) : cents{ convertToCents(a) }, c{findConv("$")}
{
	if (!is_valid(a))
		throw std::exception{ "invalid initialization" };
}
Money::Money() : cents{ 0 }, c{findConv("$")}
{
}
//I don't know an invariant for money.
bool moneySpace::is_valid(double a) 
{
	return int(a*100) == a*100;
}
int moneySpace::convertToCents(double b) 
{
	return round(b * 100);
}
std::string Money::getCurrency() const 
{
	return this->c.name;
}
std::ostream& moneySpace::operator<<(std::ostream& os, Money m)
{
	os << m.getCurrency() << m.getAmount();
	return os;
}

std::istream& moneySpace::operator>>(std::istream& is, Money& m)
{
	//This code piece is error prone.
	char cha;
	std::string name;
	double amount;
	is.get(cha);
	while (!isdigit(cha))
	{
		name.push_back(cha);
		is.get(cha);
	}
	is.putback(cha);
	is >> amount;
	m = Money{ amount,name };
	return is;
}