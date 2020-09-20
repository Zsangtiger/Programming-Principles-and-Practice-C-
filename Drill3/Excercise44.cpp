#include "std_lib_facilities.h"

/*

6. Write a program that converts from Celsius to Fahrenheit and from Fahrenheit to Celsius
(formula in §4.3.3). Use estimation (§5.8) to see if your results are plausible

*/

double ftoc(double v) {
	// calculates celsius from farenheit
	// precondition is  value is f > -459.67

	if (v < -459.67)
		error("Impossible value");
	double cel = (v-32) * 5.0 / 9.0;
	return cel;
};

double ctof(double v) {
	// calculates farenheit to celsius
	// pre-condition is that c > -273.5
	if (v < -273.5)
		error("Impossible value");

	double far = 9.0 / 5.0 * v + 32;
	return far;
};


int main() {

	double value;
	char unit;
	cout << "Give a temperature and a unit f for farenheit c for celsius\n";
	cin >> value >> unit;
	if (!cin)
		error("Incerrect parameters");

	if (unit == 'f')
	{
		double temp = ftoc(value);
		cout << "The given value is about : " << temp << " celsius\n";
	}
	else if (unit == 'c')
	{
		double temp = ctof(value);
		cout << "The given value is about : " << temp << " farenheit\n";
	}
	else
	{
		error("Unknows unit for measuing temperature\n");
	}
	

	return 0;
}