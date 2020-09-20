#include "std_lib_facilities.h"

/*

Write a program that performs as a very simple calculator. Your calculator should be able to
handle the four basic math operations — add, subtract, multiply, and divide — on two input
values. Your program should prompt the user to enter three arguments: two double values and
a character to represent an operation. If the entry arguments are 35.6, 24.1, and '+', the program
output should be The sum of 35.6 and 24.1 is 59.7. In Chapter 6 we look at a much more
sophisticated simple calculator.
*/

int main() {

	char oper;
	double first_op, secound_op;

	cout << "Write 2 numbers and an operation to be performed on them\n";

	while (cin >> first_op >> secound_op >> oper)
	{
		switch (oper) {
		case '+':
			cout << first_op + secound_op << "\n";
			break;
		case '-':
			cout << first_op - secound_op << "\n";
			break;
		case '*':
			cout << first_op * secound_op << "\n";
			break;
		case '/':
			if(secound_op != 0)
				cout << first_op / secound_op << "\n";
			break;
		default:
			cout << "Bad oper";
		}
	
	}

	return 0;
}