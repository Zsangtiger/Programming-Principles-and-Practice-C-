#include "std_lib_facilities.h"

/*
Absolute zero is the lowest temperature that can be reached; it is –273.15°C, or 0K. The above
program, even when corrected, will produce erroneous results when given a temperature below
this. Place a check in the main program that will produce an error if a temperature is given
below –273.15°C.

*/


double ctok(double c) // converts Celsius to Kelvin
{
	if (c < -273.15)
		error("Not possible\n");

	double k = c + 273.15;
	return k;
}

double ktoc(double k)
{

	if (k < 0)
		error("Not possible\n");
	
	double c = k - 273.15;
	return c;
}
int main()
{
	char unit;
	double c = 0; // declare input variable
	cout << "Give a temperature in the form value unit where unit is either k for kelvin or c for celsius\n";
	cin >> c >> unit; // retrieve temperature to input variable
	if (!cin)
		error("Error reading variables\n");

	if (unit == 'c')
	{
		double k = ctok(c); // convert temperature
		cout << k << '/n'; // print out temperature
	}
	else if (unit == 'k')
	{
		double cel = ktoc(c); // convert temperature
		cout << cel << '/n'; // print out temperature
	}
	else
		error("Unknown unit\n");
}