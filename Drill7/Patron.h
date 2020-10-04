#pragma once
#include <string>

/*
8. Create a Patron class for the library. The class will have a user’s name, library card number,
and library fees (if owed). Have functions that access this data, as well as a function to set the
fee of the user. Have a helper function that returns a Boolean (bool) depending on whether or
not the user owes a fee.

*/

class Patron
{
public:
	Patron();
	Patron(std::string, int, int);
	std::string getName() const;
	int getCardNumber() const;
	int getFees() const;
	void setFees(int) ;
	bool operator==(Patron b) const;
private:
	std::string name;
	int cardNumber;
	int fees;
};

namespace patronHelperFunctions {
	bool hasDebt(Patron);
	
};
