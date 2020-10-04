#include "Library.h"


void Library::addBook(Book b) 
{
	this->bookVec.push_back(b);
};
void Library::addPatron(Patron p) 
{
	this->patronVec.push_back(p);
};
void Library::checkOutBook(Patron p, Book b, Chrono::Date d) 
{
	bool hasPatron = false;
	bool hasBook = false;
	for (Patron it : patronVec)
		if (it == p)
			hasPatron = true;
	for (Book it : bookVec)
		if (it == b)
			hasBook = true;

	//Migth be better to just write out an error and return form the function
	if (!hasPatron)
		throw std::exception{ "Not a member" };
	if (!hasBook)
		throw std::exception{ "Don't have book" };
	if (hasFee(p))
		throw std::exception{ "In debt" };

	transactions.push_back(Transaction{ b,d,p });
	
};
bool Library::hasFee(Patron p)
{
	return p.getFees() > 0;
};
std::vector<Patron> Library::patronsWithFee() 
{
	std::vector<Patron> v;
	for (Patron it : patronVec)
		if (hasFee(it))
			v.push_back(it);
	return v;
};