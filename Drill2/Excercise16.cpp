#include "std_lib_facilities.h"

/*
Write a program that takes an input value n and then finds the first n primes.
*/

int main() {
	int max;
	cout << "Give a number and i'll find the first n prime numbers\n";
	cin >> max;
	vector<int> numbers = { 2 };
	int number_to_test = 2;
	while (numbers.size() < max)
	{
		bool prime = true;
		for (int it : numbers)
			if (number_to_test % it == 0)
				prime = false;
		if (prime)
			numbers.push_back(number_to_test);
		++number_to_test;
	}
	for (int i : numbers)
		cout << i << " \n";
	return 0;
}