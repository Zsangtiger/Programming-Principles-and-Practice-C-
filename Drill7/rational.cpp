#include "rational.h"
#include <cmath>

namespace MMath {

	rational::rational() : numer{ 0 }, denom{ 1 }{};
	rational::rational(int n) : numer{ n }, denom{ 1 }{};
	rational::rational(int n, int d) : numer{ n }, denom{ d }
	{
		this->is_valid();
	};

	double rational::getValue() const
	{
		return double(numer) / double(denom);
	};

	bool rational::is_valid() 
	{
		if (denom == 0) throw std::exception{ "Divison by zero" };
	}
	rational rational::operator=(rational b) 
	{
		numer = b.numer;
		denom = b.denom;
		return *this;
	}
	rational rational::getSimplified() const
	{
		rational tmp{ *this };
		for (int i = std::max(denom,numer); i>1; i--)
		{	
			if ((tmp.denom % i == 0) && (tmp.numer % i == 0))
			{
				tmp.numer = tmp.numer / i;
				tmp.denom = tmp.denom / i;
			}
		}
		return tmp;
	}
	bool rational::operator==(rational a) const
	{
		rational simple = this->getSimplified();
		rational simple2 = a.getSimplified();
		return simple.numer == simple2.numer && simple.denom == simple2.denom ? true : false;
	}
	rational rational::operator*(rational a) const
	{
		return rational{ this->numer * a.numer, this->denom * a.denom }.getSimplified();
	}
	rational rational::operator+(rational a) const
	{
		rational copy{ *this };
		copy.numer *= a.denom;
		//copy.denom *= a.denom;
		a.numer *= this->denom;
		a.denom *= this->denom;
		
		return rational{ copy.numer + a.numer, a.denom }.getSimplified();
	}
	rational rational::operator-(rational a) const
	{
		rational copy{ *this };
		copy.numer *= a.denom;
		copy.denom *= a.denom;
		a.numer *= this->denom;
		a.denom *= this->denom;

		return rational{ copy.numer - a.numer, a.denom }.getSimplified();
	}
	rational rational::operator/(rational a) const 
	{
		if (a.numer == 0) throw std::exception{ "Division by zero" };
		return rational{ this->denom * a.numer,this->numer * a.denom }.getSimplified();
	}

	rational::operator int()
	{
		if (numer % denom == 0)
			return numer / denom;
		else
			throw std::exception("Not int");
	}
	std::ostream& operator<<(std::ostream &os,rational a) 
	{

		if (a.numer % a.denom == 0)
			os << '('<< int(a) << ')';
		else 
			os << '(' << a.numer << '/' << a.denom << ')';
		return os;
	}
}