#include "std_lib_facilities.h"

/*
Try to calculate the number of rice grains that the inventor asked for in exercise 8 above. You’ll
find that the number is so large that it won’t fit in an int or a double. Observe what happens
when the number gets too large to represent exactly as an int and as a double. What is the
largest number of squares for which you can calculate the exact number of grains (using an
int)? What is the largest number of squares for which you can calculate the approximate
number of grains (using a double)?
*/

int main() {

	int intsum = 0,count = 1 ;
	double doublesum = 0, square_rice = 1;
	

	for (int i = 0; i < 64; i++) 
	{
		intsum += square_rice;
		doublesum += square_rice;

		cout << "You get " << intsum << " rice in int variable in " << count << " steps\n";
		cout << "You get " << doublesum << " rice in double variable in " << count << " steps\n";
		count++;
		square_rice *= 2;
	}

	return 0;
}