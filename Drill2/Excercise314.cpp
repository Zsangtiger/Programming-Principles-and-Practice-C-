
#include <vector>
#include <iostream>

/*

Create a program to find all the prime numbers between 1 and 100. There is a classic method
for doing this, called the “Sieve of Eratosthenes.” If you don’t know that method, get on the web
and look it up. Write your program using this method.

*/
using namespace std;

int main(){

	std::vector<bool> numbers(100,true);
	numbers[0] = false;
	numbers[1] = false;

	int lim1 = 100;

	for (int i = 2; i <= 10; i++)
	{
		if (numbers[i])
			for (int j = i * i; j < numbers.size(); j += i)
				numbers[j] = false;
	}

	for (int i = 0; i < 100; i++) {
		if (numbers[i])
			std::cout << i << "\n";
	}

	return 0;
}

// This porject has some promblems with the header provided for this book so i used the orignial headers instead