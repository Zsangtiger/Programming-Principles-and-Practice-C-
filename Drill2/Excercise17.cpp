#include "std_lib_facilities.h"

/*
In the drill, you wrote a program that, given a series of numbers, found the max and min of that
series. The number that appears the most times in a sequence is called the mode. Create a
program that finds the mode of a set of positive integers.
*/
int main() {

	vector<int> numbers;
	int a;
	cout << "Give a series of numbers:\n";
	while (cin >> a) {
		numbers.push_back(a);
	}

	sort(numbers);

	int max_sequence = 0;
	int mode;

	for (int i = 1; i < numbers.size(); i++) 
	{
	
		int counter = 0;
		if (numbers[i] == numbers[i - 1]) 
		{
			counter++;
			if (counter > max_sequence)
			{
				max_sequence = counter;
				mode = numbers[i];
			}
		}
		else 
			counter = 0;
		

	}
	if (max_sequence == 0)
		cout << "You don't have a mode\n";
	else
		cout << "The mode is :" << mode << "\n";

	return 0;
}