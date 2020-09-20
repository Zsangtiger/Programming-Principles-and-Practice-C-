#include "std_lib_facilities.h"

/*
Write a program that reads and stores a series of integers and then computes the sum of the first
N integers. First ask for N, then read the values into a vector, then calculate the sum of the first
N values. For example:
“Please enter the number of values you want to sum:”
3
“Please enter some integers (press '|' to stop):”
12 23 13 24 15 |
“The sum of the first 3 numbers ( 12 23 13 ) is 48.”
Handle all inputs. For example, make sure to give an error message if the user asks for a sum of
more numbers than there are in the vector.
*/

int main() {

	vector<int> integers;
	int N;
	int temp;

	cout << "Please enter the number of values you want to sum.\n";
	cin >> N;
	if (!cin) {
		error("Failed to give an integer");
	}

	cout << "Please enter some integers (press '|' to stop). \n";
	while (cin>>temp) {
		integers.push_back(temp);
	}

	int sum=0;

	//Checking if N is in range
	if (N >= integers.size())
		error("Out of bound N is too large");
	for (int i = 0; i < N; i++) 
	{
		sum += integers[i];
	}

	cout << "The sum of the first " << N << " numbers is : " << sum << "\n";

	return 0;
}