#pragma once
/*
13. Design and implement a rational number class, Rational. A rational number has two parts: a
numerator and a denominator, for example, 5/6 (five-sixths, also known as approximately
.83333). Look up the definition if you need to. Provide assignment, addition, subtraction,
multiplication, division, and equality operators. Also, provide a conversion to double. Why
would people want to use a Rational class?
*/
#include <iostream>
namespace MMath {


	class rational
	{
	public:
		rational();
		rational(int);
		rational(int, int);

		double getValue() const;
		rational getSimplified() const;
		rational operator=(rational);
		bool operator==(rational) const;
		//This interface could be further minimized, but it looks simple and fine to me so i don't want to.
		rational operator*(rational) const;
		rational operator+(rational) const;
		rational operator-(rational) const;
		rational operator/(rational) const;
		operator int();
		friend std::ostream& operator<<(std::ostream &,rational);
	private:
		bool is_valid();
		int numer;
		int denom;
	
	};
	std::ostream& operator<<(std::ostream &,rational);
}