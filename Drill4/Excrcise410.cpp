#include "std_lib_facilities.h"

/*
A permutation is an ordered subset of a set. For example, say you wanted to pick a
combination to a vault. There are 60 possible numbers, and you need three different numbers
for the combination. There are P(60,3) permutations for the combination, where P is defined by
the formula
where ! is used as a suffix factorial operator. For example, 4! is 4*3*2*1.
Combinations are similar to permutations, except that the order of the objects doesn’t matter.
For example, if you were making a “banana split” sundae and wished to use three different
flavors of ice cream out of five that you had, you wouldn’t care if you used a scoop of vanilla at
the beginning or the end; you would still have used vanilla. The formula for combinations is
Design a program that asks users for two numbers, asks them whether they want to calculate
permutations or combinations, and prints out the result. This will have several parts. Do an
analysis of the above requirements. Write exactly what the program will have to do. Then, go
into the design phase. Write pseudo code for the program, and break it into sub-components.
This program should have error checking. Make sure that all erroneous inputs will generate
good error messages.
*/

/*
Analysis phase
	I will have to:
		-Ask the user for 2 numbers.
		-Ask if they want to calcualte permutations or combinations
		-Need to write a function that claculates permutations and one that calculates combinations
		-In order to do the above step i need to calculate factorials first.
		-Printing the result
*/

/*
Desing phase
	
	Ask for two numbers.
	Ask for a mode.
	Calculate value based on the numbers and mode
	Write the calculated value to standard output.
	Part of the desing phase is looking for libraries that might help. For this problem there ought to be an already existing statistics library. But i choose not to use one.
*/

double fact(int param)
{

	//I initialized value to 1 because we divide with this value and 0 division could be a problem
	double value = 1;
	//Facotrial of negatives is undefined. In this case i rise an error;
	if (param < 0)
		error("Factorial must be a natural number\n");
	//Overflow is common in this case. Should be handled.
	for (int i = param; i > 1; i--) {

		//only way to overflow in this case is if the calculated value is smaller then the old one.
		double newVal = value * i;

		if (value > newVal)
			error("overflow\n");

		value = newVal;
	}
	if (isinf(value))
		error("Too big values doulbe is inf\n");
	return value;
	//The returned value is at least 1
	//For big numbers we might lose precision or return inf. Retrned number might look like 2.231e+123;
	//Should check for infinity by isinif();
}

double permutation(int num1, int num2)
{
	//if num1 < num 2 the calculation is meaningless. Cant choose 3 different elements from 2 elements.
	if (num1 < num2)
		error("Illegal permutation\n");
	
	return fact(num1) / fact(num1 - num2);

}

double combination(int num1, int num2)
{
	//Combinations in this excercise are not defined if num1 is smaller than num2
	if (num1 < num2)
		error("Illegal argument\n");
	//fact can't be zero.
	//Mathematics tells us that permutatins are whole numbers. So int division is not a problem here.
	return permutation(num1, num2) / fact(num2);
}

int main() {

	try {
		int num1, num2;
		string mode;
		cout << "Give two numbers and either comb or perm\n";
		cin >> num1 >> num2 >> mode;
		if (!cin)
			error("Failed to give correct arguments");
		if (mode == "comb")
			cout << combination(num1, num2) << '\n';
		else if (mode == "perm")
			cout << permutation(num1, num2) << '\n';
		else
			cerr << "Not a valid third argument\n";
		return 0;
	}
	catch (exception & e) {
		cerr << e.what();
	}
}