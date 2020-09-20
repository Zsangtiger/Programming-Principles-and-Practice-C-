#include "std_lib_facilities.h"

/*

Modify the “mini calculator” from exercise 5 to accept (just) single-digit numbers written as
either digits or spelled out.
*/

int main() {

	vector<string> digits = { "zero", "one", "two", "three","four","five","six","seven","eigth","nine" };

	int number;
	string spelled;
	cout << "Give a number and Give a number in spelled out form \n";
	vector<string> numbers = { "0","1","2" ,"3" ,"4" ,"5" ,"6" ,"7" ,"8" ,"9" };
	
		



	char oper;
	string first_op, secound_op;
	int num1 = -1, num2 = -1;

	cout << "Write 2 numbers and an operation to be performed on them\n";

	while (cin >> first_op >> secound_op >> oper)
	{
		int count = 0;
		for (string it : digits)
		{
			if (it == first_op)
				num1 = count;
			count++;
		}
		count = 0;
		for (string it : numbers)
		{
			if (it == first_op)
				num1 = count;
			count++;
		}
		count = 0;
		for (string it : digits)
		{
			if (it == secound_op)
				num2 = count;
			count++;
		}
		count = 0;
		for (string it : numbers)
		{
			if (it == secound_op)
				num2 = count;
			count++;
		}

		if (num1 == -1 || num2 == -1)
		{	
			cout << "Bad number\n";
			break;
		}
		switch (oper) {
		case '+':
			cout << num1 + num2 << "\n";
			break;
		case '-':
			cout << num1 - num2 << "\n";
			break;
		case '*':
			cout << num1 * num2 << "\n";
			break;
		case '/':
			if (num2 != 0)
				cout << double(num1) / num2 << "\n";
			break;
		default:
			cout << "Bad oper";
		}

	}

	return 0;
}