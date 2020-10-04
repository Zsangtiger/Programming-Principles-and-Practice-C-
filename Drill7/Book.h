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

#include <string>
#include <iostream>
#include "Date.h"

enum class Genre;

class Book {
public:
	Book();
	Book(std::string, std::string, Chrono::Date, std::string, bool, Genre);
	std::string getISBN()const;
	std::string getTitle()const;
	Chrono::Date getDate()const;
	std::string getAuthor()const;
	bool isCheckedOut()const;
	void checkIn();
	void checkOut();
	bool operator==(const Book) const;
private:
	std::string ISBN;
	std::string title;
	Chrono::Date copyright;
	std::string author;
	bool checkedOut;
	Genre genre;
};

bool operator!=(const Book a, const Book b);
std::ostream& operator<<(std::ostream& os, Book b);