#include "std_lib_facilities.h"

int main() {

	vector<double> numbers;
	for (double i; cin >> i;)
		numbers.push_back(i);
		
	const int size = numbers.size();

	sort(numbers);
	double median = 0;
	if (size % 2 == 0) 
	{
		median = (numbers[size / 2] + numbers[size / 2 - 1]) / 2.0;
	}
	else
	{
		median =numbers[size / 2 ];
	}

	cout << median;
	return 0;
}
