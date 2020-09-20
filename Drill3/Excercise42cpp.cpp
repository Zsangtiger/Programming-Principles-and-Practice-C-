#include "std_lib_facilities.h"

/*
Absolute zero is the lowest temperature that can be reached; it is –273.15°C, or 0K. The above
program, even when corrected, will produce erroneous results when given a temperature below
this. Place a check in the main program that will produce an error if a temperature is given
below –273.15°C.

*/


double ctok(double c) // converts Celsius to Kelvin
{
	double k = c + 273.15;
	return k;
}
int main()
{
	double c = 0; // declare input variable
	cin >> c; // retrieve temperature to input variable

	if (c < -273.15)
		simple_error("Not possible");
	else
	{
		double k = ctok(c); // convert temperature
		cout << k << '/n'; // print out temperature
	}
}