/*
5. This exercise and the next few require you to design and implement a Book class, such as you
can imagine as part of software for a library. Class Book should have members for the ISBN,
title, author, and copyright date. Also store data on whether or not the book is checked out.
Create functions for returning those data values. Create functions for checking a book in and out.
Do simple validation of data entered into a Book; for example, accept ISBNs only of the form
n-n-n-x where n is an integer and x is a digit or a letter. Store an ISBN as a string.
*/

/*
6. Add operators for the Book class. Have the == operator check whether the ISBN numbers are
the same for two books. Have != also compare the ISBN numbers. Have a << print out the title,
author, and ISBN on separate lines.
*/

/*
7. Create an enumerated type for the Book class called Genre. Have the types be fiction,
nonfiction, periodical, biography, and children. Give each book a Genre and make appropriate
changes to the Book constructor and member functions.
*/

#include "string"
#include "iostream"
#include "Book.h"

using namespace std;

enum class Genre {
	unknown = 0 ,fiction , nonficiton, periodiacl, bibliography, children
};

bool Book::operator==(const Book b) const
{
	return this->getISBN() == b.getISBN();
};

bool operator!=(const Book a, const Book b)
{
	return !(a == b);
}

ostream& operator<<(ostream& os, Book b)
{
	os << b.getTitle() << '\n' << b.getAuthor() << '\n' << b.getISBN() << '\n';
	return os;
}



Book::Book() : ISBN{ "" }, title{ "" }, copyright{ Chrono::Date{1970,Chrono::Month::jan,1} }, author{ "" }, checkedOut{ false }, genre{Genre::unknown} {};

Book::Book(string isbn, string title, Chrono::Date date, string aauthor, bool check, Genre g) : ISBN{ isbn },
title{ title }, copyright{ date }, author{ aauthor }, checkedOut{ false }, genre{g}
{
	//Basic validation for the ISBN format;
	int counter = 0;
	for (int i = 0; i < ISBN.size(); i++) {
		if (counter < 3 && isdigit(ISBN[i]))
			continue;
		else if (counter < 3 && ISBN[i] == '-')
		{
			counter++;
			continue;
		}
		else if (counter == 3 && isalnum(ISBN[i]))
			continue;
		else
			throw exception{ "Incorrect ISBN format\n" };
	}
};
string Book::getISBN() const { return ISBN; };
string Book::getTitle()const { return title; };
Chrono::Date Book::getDate()const { return copyright; };
string Book::getAuthor()const { return author; };
bool Book::isCheckedOut()const { return checkedOut; };
void Book::checkIn() { if (!checkedOut) cout << "Checked in\n"; else this->checkedOut = true; };
void Book::checkOut() { if (checkedOut) cout << "Checked out\n"; else this->checkedOut = false; };