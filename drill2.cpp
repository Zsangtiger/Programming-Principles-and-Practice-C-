// drill2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h" 
#include "limits"

int main()
{

	//Drill 1 to 5
	/*
	constexpr double diff = 0.01;
	cout << "Give two integers values. When you don't want to add more values give |\n";
	double first, second;
	while (cin >> first >> second)
	{
		if (first < second)
		{
			cout << "the smaller value is : " << first << "\n";
			if (second > first)
				cout << "the larger value is : " << second << "\n";
			if (second - first < diff)
				cout << "numbers are almost equal.\n";
		}
		else if ( second < first)
		{
			cout << "the smaller value is : " << second << "\n";
			if (second < first)
				cout << "the larger value is : " << first << "\n";
			if (first - second < diff)
				cout << "numbers are almost equal.\n";
		}
		else
			cout << "they are equals \n";
		
		

	}
	*/
	//Drill 6
	numeric_limits<double> lim;
	double smallest = lim.max(), largest = lim.min(), temp;
	string unit;
	double sum = 0;
	int numValues = 0;
	vector<double> values;
	cout << "Give a series of numbers with a unit form (cm,m,in,ft) separated by whitespace \n";
		while (cin >> temp>>unit)
		{
			cout << temp << unit << "\n";
			numValues++;
			if (unit == "cm")
			{
				temp *= 0.01;
			}
			else if (unit == "m")
			{
				temp *= 1;
			}
			else if (unit == "in")
			{
				temp *= 2.54 / 100;
			}
			else if (unit == "ft")
			{
				temp *= 12 * 2.54 / 100;
			}
			else
			{
				cout << "failed to give a proper unit\n";
				break;
				//simple_error("failed to give a proper unit\n");
			}
			values.push_back(temp);
			sum += temp;
			if (temp < smallest)
			{
				smallest = temp;
				cout << "the smallest so far : " << smallest << "m\n";
			}
			if (temp > largest)
			{
				largest = temp;
				cout << "the largest so far : " << largest << "m\n";
			}
		}
		cout << "The smallest value : " << smallest << "\nThe largest value : " << largest << "\nThe number of values : " << numValues << "\nThe sum of values : " << sum  << "m\n";
		sort(values);
		for (double i : values)
			cout << i << "m ";
		cout << "\n";
	

	
			

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


/*
Review
1. What is a computation?
	A computation is the production of an output value from input values
2. What do we mean by inputs and outputs to a computations? Give examples.
	Inputs are data we work with from other apps, hardwares etc. Output is what our program gives to other programs using it as input
	Example inputs are: text inputs from command line, function parameters, inputs from a network, of from keyboard, or touch scrren
	Output examples are: values calculated by a function, text we print to the screen
3. A computations shuld be 
	Correct
	Simple
	Efficient
4. What does an expression do
	Calculates a value form operators and operands
5. What is the difference between a statement and an expression?
	Statements are boulding block of funciton, an expression calculates a value, an expression is a kind of statement.
6. What is an lvlaue? List the operators that require an lvlaue. Why do these operatros, and not the other, require an lvalue
	An lvalue is a value that can appear on the left side of an assignment. More precisely an object. Even more precisely a part of a memory where data can be written
	Operators: =, *= /= += etc. To be able to assign you need an object to assign to.
7. What is a constant expression:
	An expression whose value is know at compile time and it's not allowed to change.
8. What is a literal?
	A series of characters
9. What is a symbolic constant and why do we use them?
	A constexpr or const variable that is used insted of magic constant in the code.
10. What is a magic constant? Give example
	Numbers randomly occuring in the code like 3.14, 99, 54. 
11. What are some operatores that we can use for integers and floating-point values
	+,-,*,/, <, >.
12. What operatos can be used on integers but not on floating-point numbers?
	%, ++, --.
13. What are som operators that can be used for strings?
	<,>, ==, =, [],
14. When would a programmer prefer a switch statement instead of an if statement
	When we need to compare against not string values known at compile time
15. What are some common problems with switch statements?
	Leaving out the break; statement or leaving out a default case.
16. What is the funciton of each part of the header line in a for-loop, and what sequence are they executed?
	(initialization of a variable, checking a logical expression, incrementing the variable)
	First is initialization, then check, then increase then check again until expression is false
17. When sould the for loop be used when sould te while loop be used.
	For simple iterations The for loop sould be used, when using the for loop makes us harder to solve a problem we use while
18. How do you print the numeric value of a char?
	Let the car be named k, using the int(k) or int{k}. The latter one prevents narrowing in every case.
19. Describe what the line char foo(int x) means in a function definition.
	Describes the signature of a function. Name is foo, return type si char, it has one parameter and the type of that is int.
20. When sould you define a separate funciton for a part of a program? List reason.
	When you can abstract away implementation detalis, if that part is expected to be reused, is that part is long, if breaking up that part into smaller part makes it easier to solve
21. What can you do to an int that you cannot do to a string?
	Cast to double, use *,%,++,-- operators. Assign it to anther int variable, use it in a switch statement 
22. What can you do to a string you can't do to an int?
	Assign it to a string variable, use member operators, and member function.
23. What is the index of the third element of a vector?
	2
24. How so you write a for loop that print every element of a vector.
	vector<T> vec;
	for(t : vec)
		cout<< t <<  " " ;
	range for loop syntax
25. what does vector<char> alphabet(26); do?
	Declares a vector of char initialized with 26 default initialized chars;
26. Describe what push_back() does to a vector?
	Append an element at the end of the vector, occasionally allocates new memory.
27. What does vector's mebmer functions begin(), end(), and size() do?
	Return an iterator the the first element, one past the last element, or return the number of elements in the vector
28. What maeks vector so popular/useful
	Ease of use.
29. How do you sort the elements of a vector.
	With the std::sort algorithm
	std::sort(vec.begin(),vec.end());

Terms:
	abstarction:
		Gettin rid of implementation details in order to have a clear interface to work with.
	computation: 
		Calculation output values values from input values
	conditional statement:
		A kind of statement that lets you select from different codes to execute based on a condition
	declaration: 
		Naming of an object in the memory
	definition:
		Giving a value to an varibale
	divide and conquer:
		When we face a problem we divide it up to smaller more easily solvable problem and solve those first
	else
		the part of an if statement that is run when the condition is false
	end()
		The member function of vector that gives an iterator to the last element
	expression
		The prduction of a value from values and operators
	for-statement
		An iteration statement used tipically to iterate over elements of somethign with a simple rule for steps
	range-for-statement:
		An iteration statement used to iterato over the elements of vectors and other containers one by one
	function:
		A collection of statements with a name
	if-statement:
		A statement allowing you to choose between differenct code segments based on a logical condition
	increment:
		Increasing a value of an int by one.
	input:
		Data we get when we run our program
	iteration
		Going over the elements of something
	loop:
		doing a part of code over and over until a condition is true
	lvlaue:
		value you can append to, an object, a part ot memory.
	member function:
		Function of user defined types.
	output:
		What our program produce and give to other programs to work with
	push_back()
		Member function of vector that allowes ut to append elemnt to the end of the vector
	repetition:
		Doing somethign mulitple times
	rvalue:
		Not lvlaue
	selection:
		if-statement or switch statemetn
	size():
		Member function of vector that tells you the number of elements in the vector
	sort():
		A function to sort the elements of something
	statement:
		Part of code that is executed in order.
		Typical statements are decl statements, expression statements, compund statements, iteration statement, selection statements.
	switch statement:
		A selection statement that allows you to compare a value against constexpr values
	vector:
		A standard container. A list of elements
	whiel-staement:
		An iteration statement.
		*/		