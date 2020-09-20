#include <vector>
#include <iostream>
#include <cmath>

/*

Modify the program described in the previous exercise to take an input value max and then
find all prime numbers from 1 to max.

*/

using namespace std;

int main() {

	int max;

	cout << "Give a max value for searching primes\n";
	if (!(cin >> max)) {
		std::cout << "Error";
		exit;
	}

	std::vector<bool> numbers(max, true);
	numbers[0] = false;
	numbers[1] = false;

	int lim1 = 100;

	for (int i = 2; i <= floor(sqrt(max)); i++)
	{
		if (numbers[i])
			for (int j = i * i; j < numbers.size(); j += i)
				numbers[j] = false;
	}

	for (int i = 0; i < max; i++) {
		if (numbers[i])
			std::cout << i << "\n";
	}

	return 0;
}