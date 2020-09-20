#include "std_lib_facilities.h"
/*
Write a program that writes out the first so many values of the Fibonacci series, that is, the
series that starts with 1 1 2 3 5 8 13 21 34. The next number of the series is the sum of the two
previous ones. Find the largest Fibonacci number that fits in an int
*/

int summation(int a, int b) {

	//Assumptions are that a and b are positive integers
	if (a > 0 && b > 0)
	{
		int sum = a + b;
		if (sum < a || sum < b)
			error("overflow");
		else
			return sum;
	}// Assumpitons are that a and b are negative integers.
	else if (a < 0 && b < 0)
	{
		int sum = a + b;
		if (sum > a || sum > b)
			error("overflow");
		else
			return sum;
	}
	//If one is > 0 and the other one is < 0 they overflow when one of them overflows. In that case cin will fail.
}

int main() {

	int fib0 = 1;
	int fib1 = 1;
	cout << fib0 << " " << fib1 << " ";
	while (true) {
		try {
			int sum = summation(fib0, fib1);
			fib0 = fib1;
			fib1 = sum;

			cout << sum << " ";
		}
		catch (runtime_error e) {
			cout<<e.what();
			break;
		}
	}

	return 0;
}