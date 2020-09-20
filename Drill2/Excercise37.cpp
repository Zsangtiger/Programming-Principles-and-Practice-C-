#include "std_lib_facilities.h"

/*
Make a vector holding the ten string values "zero", "one", . . . "nine".Use that in a
program that converts a digit to its corresponding spelled - out value; e.g., the input 7 gives the
output seven.Have the same program, using the same input loop, convert spelled - out numbers
into their digit form; e.g., the input seven gives the output 7.*/

int main() {

	

	/*

	vector<string> digits = { "zero", "one", "two", "three","four","five","six","seven","eigth","nine" };

	int number;
	string spelled;
	cout << "Give a number and Give a number in spelled out form \n";

	This work well for number to spelled out conversion

	while (cin >> number || cin >> spelled)
	{
		cout << digits[number] << "\n";
		for (int i = 0; i < digits.size(); i++)
			if (digits[i] == spelled)
				cout << i << "\n";
	}

	*/

	/*

	This makes it work both ways.
	vector<string> digits = { "zero", "one", "two", "three","four","five","six","seven","eigth","nine" };

	int number;
	string spelled;
	cout << "Give a number and Give a number in spelled out form \n";
	vector<string> numbers = { "0","1","2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" };
	while (cin >> spelled) 
	{
		int count = 0;
		for (string it : digits)
		{	
			if (it == spelled)
				cout << count;
			count++;
		}
		count = 0;
		for (string it : numbers)
		{
			if (it == spelled)
				cout << digits[count];
			count++;
		}


	}

	*/

	return 0;
}