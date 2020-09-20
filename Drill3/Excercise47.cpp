#include "std_lib_facilities.h"

/*
Modify the program from exercise 8 to write out an error if the result cannot be represented as
an int.
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
		if (sum  > a || sum > b)
			error("overflow");
		else
			return sum;
	}
	//If one is > 0 and the other one is < 0 they overflow when one of them overflows. In that case cin will fail.
}

int main() {

	vector<int> integers;
	int N;
	int temp;

	cout << "Please enter the number of values you want to sum.\n";
	try {
		cin >> N;
		if (!cin) {
			error("Failed to give an integer");
		}

		cout << "Please enter some integers (press '|' to stop). \n";
		while (cin >> temp) {
			integers.push_back(temp);
		}

		int sum = 0;

		//Checking if N is in range
		if (N > integers.size())
			error("Out of bound N is too large");
		for (int i = 0; i < N; i++)
		{
			sum = summation(sum, integers[i]);
		}

		cout << "The sum of the first " << N << " numbers is : " << sum << "\n";
	}
	catch (runtime_error r) {
		cout << r.what();
	}

	return 0;
}