#include "std_lib_facilities.h"

/*

Read (day-of-the-week,value) pairs from standard input. For example:
Tuesday 23 Friday 56 Tuesday –3 Thursday 99
Collect all the values for each day of the week in a vector<int>. Write out the values of the
seven day-of-the-week vectors. Print out the sum of the values in each vector. Ignore illegal
days of the week, such as Funday, but accept common synonyms such as Mon and monday.
Write out the number of rejected values.

*/

void printVectorSum(vector<int> & vec) {
	int sum = 0;
	for (int a : vec)
		sum += a;
	cout << sum << " ";
};

void insertValues(vector< vector<int> > &week, string day, int value, int & count) {
	
	if (day == "Monday" || day == "Mon" || day == "1")
		week[0].push_back(value);
	else if (day == "Tuesday" || day == "Tue" || day == "2")
		week[1].push_back(value);
	else if (day == "Wednesday" || day == "Wed" || day == "3")
		week[2].push_back(value);
	else if (day == "Thursday" || day == "Thu" || day == "4")
		week[3].push_back(value);
	else if (day == "Friday" || day == "Fri" || day == "5")
		week[4].push_back(value);
	else if (day == "Saturday" || day == "Sat" || day == "6")
		week[5].push_back(value);
	else if (day == "Saturday" || day == "Sun" || day == "7")
		week[6].push_back(value);
	else
	{
		cout << "Illegal day\n";
		count++;
	}

}

int main() {

	vector< vector<int> > lweek(7);
	string lday;
	int lvalue, lcount =0;
	cout << "Give day of the week value pairs. Write q if you want to quit\n";
	while (cin >> lday >> lvalue) 
	{
		if (lday == "q")
			break;
		insertValues(lweek, lday, lvalue,lcount);
	}

	cout << "Number of rejected values: " << lcount << "\n";
	cout << "Sum of vectors are ";  
	for (int i = 0; i < 7; i++)
		printVectorSum(lweek[i]);
	return 0;
}