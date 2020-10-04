#pragma once

/*
9. Create a Library class. Include vectors of Books and Patrons. Include a struct called
Transaction. Have it include a Book, a Patron, and a Date from the chapter. Make a vector
of Transactions. Create functions to add books to the library, add patrons to the library, and
check out books. Whenever a user checks out a book, have the library make sure that both the
user and the book are in the library. If they aren’t, report an error. Then check to make sure that
the user owes no fees. If the user does, report an error. If not, create a Transaction, and place
it in the vector of Transactions. Also write a function that will return a vector that contains the
names of all Patrons who owe fees.
*/


#include <vector>
#include "Transaction.h"

class Library
{
public:
	void addBook(Book);
	void addPatron(Patron);
	void checkOutBook(Patron, Book,Chrono::Date);
	bool hasFee(Patron);
	std::vector<Patron> patronsWithFee();
private:
	std::vector<Book> bookVec;
	std::vector<Patron> patronVec;
	std::vector<Transaction> transactions;
};

