#include "std_lib_facilities.h"
/*

Modify the program described in the previous exercise to take an input value max and then
find all prime numbers from 1 to max.

*/

int main() {

	int max = 2;
	std::cout << "Give a max value and i tell you the prime numbers form 2 to max";
	if (cin >> max) {
		;
	}
	else {
		simple_error("Baka i told you to give a number");
	}

	vector<int> primes = { 2 };


	for (int i = 3; i < max; i = i+2) {

		bool prime = true;
		for (int it : primes)
		{
			if (i % it == 0)
			{
				prime = false;
			}

		}
		if (prime)
			primes.push_back(i);
	}

	for (int it : primes)
		cout << it << " is prime \n";


	return 0;
}