#include "Patron.h"


Patron::Patron() : name{ "" }, cardNumber{ 0 }, fees{0}
{

};
Patron::Patron(std::string nme, int card, int fee) : name{ nme }, cardNumber{ card }, fees{fee}
{
	//Validation of data should be placed here.
};
std::string Patron::getName() const
{
	return name;
};
int Patron::getCardNumber() const
{
	return cardNumber;
};
int Patron::getFees() const
{
	return fees;
};
void Patron::setFees(int fee) 
{
	fees = fee;
};
bool patronHelperFunctions::hasDebt(Patron p) {
	return p.getFees() > 0;
}

bool Patron::operator==(Patron b) const
{
	if (this->name == b.name && this->cardNumber == b.cardNumber)
		return true;
	return false;
};