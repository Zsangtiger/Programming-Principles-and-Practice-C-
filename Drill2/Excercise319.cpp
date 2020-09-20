#include "std_lib_facilities.h"

/*
8. Write a program to solve quadratic equations. A quadratic equation is of the form
ax^2 + bx + c = 0
If you don’t know the quadratic formula for solving such an expression, do some research.
Remember, researching how to solve a problem is often necessary before a programmer can
teach the computer how to solve it. Use doubles for the user inputs for a, b, and c. Since there
are two solutions to a quadratic equation, output both x1 and x2
*/

int main() {
	
	cout << "Give 3 numbers namely a b and c int he formula ax^2+bx+c = 0\n";

	double a = 0, b = 0, c = 0;
	if (!(cin >> a >> b >> c))
		simple_error("Something went wrong");

	double solution1, solution2;


	
	if (b*b - 4 * a* c < 0)
		simple_error("No real solution\n");

	
	if (a != 0) 
	{

		solution1 = (-b + sqrt(b*b - 4 * a* c)) / 2 * a;
		solution2 = (-b - sqrt(b*b - 4 * a* c)) / 2 * a;

		cout << "The two solutions are : " << solution1 << " " << solution2 << "\n";
	}
	else
	{
		cout << "The only solution is : " << -c / b << "\n";
	}
	
	return 0;
}