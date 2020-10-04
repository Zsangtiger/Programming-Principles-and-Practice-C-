#include "library.h"
#include "Date.h"
#include "Date2.h"
#include "rational.h"
#include "Money.h"

using namespace MMath;
int main() {
	try {
		std::cout << "First i create a Library object myLib and insert books and patrons into it\n";
		Library myLib;
		Book firstBook(Book("1-1-1-n", "valami", Chrono::Date(2004, Chrono::Month::jan, 2), "vmi", true, Genre(1)));
		std::cout << "The first book created\n";
		std::cout << firstBook;
		myLib.addBook(firstBook);
		Patron firstPatron(Patron("Peti", 1, 0));
		Patron secPatron(Patron("FeeFee", 1, 2000));
		myLib.addPatron(firstPatron);
		myLib.addPatron(secPatron);
		myLib.checkOutBook(firstPatron, firstBook, Chrono::Date(2020, Chrono::Month::jan, 1));
		std::vector<Patron> debt = myLib.patronsWithFee();
		for (Patron it : debt)
			std::cout << it.getName() << "\n";

		std::cout << "This is a comparison between the date using our original y,m,d representation vs the days since 1970.jan.1 represtentation\n";
		Chrono::Date origDate(1970, Chrono::Month::jan, 1);
		Chrono2::Date newDate(1970, Chrono2::Month::jan, 1);
		std::cout << "The original dates\n";
		std::cout << origDate << "\n";
		std::cout << newDate << "\n";
		std::cout << "After using add_month(1)\n";
		origDate.add_month(1);
		newDate.add_month(1);
		std::cout << origDate << "\n";
		std::cout << newDate << "\n";
		std::cout << "After using add_day(30)\n";
		origDate.add_day(30);
		newDate.add_day(30);
		//origDate.add_year(4);
		//newDate.add_year(4);
		std::cout << "Original date:" << origDate << "\n";
		std::cout << "New date:: " << newDate << "\n";

		origDate.add_day(7000);
		newDate.add_day(7000);
		std::cout << "After Adding 7000 days\n";
		std::cout << origDate << "\n";
		std::cout << newDate << "\n";

		//Day of the week. Returns a day. A << operator could be added.
		Chrono::day_of_week(origDate);
		std::cout << "\nCreating rational numbers and testing ordinary operations\n";
		MMath::rational num1{ 1,2 };
		std::cout << num1 <<'\n';
		//std::cout << int(num1) + 2;
		num1 = num1 + MMath::rational{ 5,6 };
		std::cout << num1<<'\n';

		MMath::rational num2{ 2,10 };
		MMath::rational num3{ -4,20 };
		std::cout << "Num2 is :" << num2 << '\n' << "Num3 is : " << num3 << '\n';

		std::cout <<"num2+num3: " << num2 + num3 << "\n";
		std::cout <<"num2-num3: " << num2 - num3 << "\n";
		std::cout <<"num2*num3: " << num2 * num3 << "\n";
		std::cout <<"num2/num3: " << num2 / num3 << "\n";

		//moneySpace::Money m1(12.12, "€");
		//std::cin >> m1;
		//std::cout << m1;

		/*
		17. Give an example of a calculation where a Rational gives a mathematically better result than
		Money.
		18. Give an example of a calculation where a Rational gives a mathematically better result than
		double.
		*/
		std::cout << "\n";
		//Here rational gives an accurate value for a valur can't be represented by money;
		std::cout << "Rational rr contains 8/1000. This is more accourate then 2 decimal places thus cannot be represented by money. This is excercise 17\n";
		MMath::rational rr{ 8,1000 };
		std::cout << rr <<'\n';
		//moneySpace::Money m{ 0.008 };

		std::cout << "In this example 10/9 ratinal is more accurate then it's double counterpart (infinitely recurring decimals)\n";
		MMath::rational betterThanDouble{ 10,9 };
		std::cout << betterThanDouble<<'\n';
		//getValue() return a double.
		std::cout << betterThanDouble.getValue()<<'\n';
	}
	catch (std::exception& e) 
	{
		std::cout<<e.what();
	}

	return 0;
}