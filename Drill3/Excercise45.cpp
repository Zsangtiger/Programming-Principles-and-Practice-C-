#include "std_lib_facilities.h"

/*

Quadratic equations are of the form
a · x
2 + b · x + c = 0
To solve these, one uses the quadratic formula:
There is a problem, though: if b2–4ac is less than zero, then it will fail. Write a program that
can calculate x for a quadratic equation. Create a function that prints out the roots of a quadratic
equation, given a, b, c. When the program detects an equation with no real roots, have it print
out a message. How do you know that your results are plausible? Can you check that they are
correct?

*/

void printRoots(double a, double b, double c) {
	//Preconditions. Sadly there isn't a good one in my mind

	//Checking if the equation is infact a quadratic one.

	double dist = 0.001;

	if (a == 0) 
	{
		if (b == 0)
			cout<< "The solution is : "<< -c << "\n";
		else
			cout << "The solution is : "<< -c / b << "\n";
	}
	else
	{
		//Check if there is a solutin

		double quadr = b * b - 4 * a*c;
		if (quadr < 0)
		{
			cout << "There is no real solution to this equation try a complex quadratic equation solver\n";
		}
		else
		{

			double sol1 = (-b + sqrt(quadr)) / 2 * a;
			double  sol2 = (-b - sqrt(quadr)) / 2 * a;

			//Postcondition checks. If sol1 or sol2 is not infact a solution we must have made a logical error. I chose 0.001 for precision.
			if (a * sol1*sol1 + b * sol1 + c < -dist || a * sol1*sol1 + b * sol1 + c > dist || a * sol2*sol2 + b * sol2 + c < -dist || a * sol2*sol2 + b * sol2 + c > dist)
				error("There is a logical error in the program");
			else
				cout << "The solutions are : " << sol1 << " and " << sol2 << "\n";
		}
	}



}

int main(){


	cout << "Give 3 arguments for a quadratic equation in the form of ax^2+bx+c=0 in the order a b and c\n";

	double a, b, c;
	cin >> a >> b >> c;

	if (!cin)
		error("Failed the give correct arguments");

	printRoots(a, b, c);

	return 0;
}