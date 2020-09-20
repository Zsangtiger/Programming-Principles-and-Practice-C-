// drill1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "std_lib_facilities.h"

int main()
{
	cout << "Enter the name of the person you want to write to (followed by 'enter'):\n";
	string first_name, friendName;
	cin >> first_name;
	cout << "Enter a friend's name:\n";
	cin >> friendName;
	char sex = 0;
	cout << "Write m if " << friendName << " is male f otherwise\n";
	cin >> sex;
	int age;
	cout << "How old is the person you are writing to?\n";
	cin >> age;j


	string introduction = "\nHow are you? I havn't heard of you in a while. I hope you are doing allright and that you are happy. I think i'm making progress with my life. I hope you are proud of me.\n";
	cout << "Dear " << first_name<< ",\n" << introduction << "have you seen " <<friendName <<" lately?\n";
	
	if (sex == 'm') 
	{
		cout << "If you see " << friendName << " please ask him to call me.\n";
	}
	else 
	{
		cout << "If you see " << friendName << " please ask her to call me.\n";
	}
	
	if (age < 0 || age > 110)
	{
		simple_error("you're kidding!");
	}
	else
	{
		cout << "I hear you just had a birthday and you are " << age << " years old.\n";
	}

	if (age < 12)
	{
		cout << "Next year you will be "<< age + 1 << " .\n";
	}
	else if (age == 17)
	{
		cout << "Next year you will be able to vote.\n";
	}
	else if (age > 70) 
	{
		cout << "I hope you're enjoying retirement.\n";
	}

	cout << "Yours sincerely, \n\nZ. \n";


	//Excercise 2
	double miles;
	cout << "Miles to convert to kms:\n";
	cin >> miles;
	cout << "It is : " << miles * 1.609 << " in kms";

	//Excercise 3
	//int 3illegalname
	int legalname;

	//Excercise 4
	int val1, val2;
	cout << "Give two numbers:\n";
	cin >> val1 >> val2;
	if (val1 < val2)
	{
		cout << "val1 is smaller\n";
	}
	if (val1 > val2)
	{
		cout << "val2 is smaller\n";
	}
	cout << "The sum of the two variables is :" << val1 + val2<<"\n";
	cout << "The difference of the two variables is :" << val1 - val2 << "\n";
	cout << "The product of the two variables is :" << val1 * val2 << "\n";
	if (val2 != 0 && val1 != 0) {
		cout << "The ratio of the two variables is :" << val1 / val2 << "\n";
	}

	//Excercise 5

	double val1, val2;
	cout << "Give two numbers:\n";
	cin >> val1 >> val2;
	if (val1 < val2)
	{
		cout << "val1 is smaller\n";
	}
	if (val1 > val2)
	{
		cout << "val2 is smaller\n";
	}
	cout << "The sum of the two variables is :" << val1 + val2 << "\n";
	cout << "The difference of the two variables is :" << val1 - val2 << "\n";
	cout << "The product of the two variables is :" << val1 * val2 << "\n";
	if (val2 != 0 && val1 != 0) {
		cout << "The ratio of the two variables is :" << val1 / val2 << "\n";
	}


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

Review:
1.What is meant by the termp prompt?
	-Ask the user the give a value;
2. Which operator do you use to read into a variable?
	>>;
3. If you want the user to input an integer value into your program fo a variable named number, wat are two lines
of code you could write to ask the user to do it and input the value into your program
cout<<"Please give an integer value\n";
cin>> number;
4. What is \n called and what purpose des it serve?
 Newline, creates a new line.
 5. What terminates input into a string?
Any whitespace
6. What terminates input into an integer
\n
7. How would you write //code as one line of code?
	cout<< "Hello, "<<first_name<<"!\n";
8. What is an object?
	A memory that has a type
9. What is a literal?
	A string of characters
10. What kind of literals are there?
	String literals, Integer literals, Floating point literals, bool literals, char literals
11. What is a variable?
	An object that has a name;
12. What are typical sizes for a char int and double
8,32,64 byte.
13. What beasures do we use for the size of small entities in memory such as ints and strings?
byte
14. What is the difference between = and ==?
The = is used in initialization and assignment the == is a logical operator checking equality
15. What is a definition
	A definition gives value to a variable
16. What is an initialization and how does it differ from an assignment?
	Initialization has declarator, assignment don't. Initialization is used when we first create a variable and has no value. Assignemnt is used when the variable already has a value
17. What is string concatenation and how do you do it in C++?
	Concatenating to string means we are appending string2 at the end of string1 syntax is string1+string2
18. Which of the following are legal names in C++? If a name is not legal why not?
	This_little_pig legal
	This_1_is_fine legal
	2_For_1_special Not legal can't begin with number
	latest thing not legal can't have space in it
	the_$12_method not legal can't have $ in a name
	_this_is_ok legal
	MiniMineMine legal
	number legal
	correct? not legal can't have ? in it.
19. 5 examples of legals names you shouldn't use?
	_a anything beginning with _ because these are for automatically generated variables
	a legal but too short
	a_really_really_really_really_long_name legal but too long hard to understand
	MXC abbreviation hard to understan
	aSnNnm chaning Capital and normal letters 

	20. some good rules for choosing a name?
		Fairly short, descriptive name.
	21. What is type safety why is it important?
		Type safety means you only use variables according to the rules of their type
	22. Why can conversion from double to int be a bad thing?
		If double is longer than int then tha value will be narrowed and possibly change to a different value
	23. Define a rule to help decide if a conversion form one type to another is safe or unsave
		if sizeof(type1) > sizeof(type2) then conversino from type1 to type2 is unsafe.
*/

/*

	Terms
	assignment: Changing a variable value to another value
	cin: character input stream
	concatenation: appending a string at the end of another
	conversion: changing the type of a value
	declaration: naming an object
	decrement: lowering the value of a variable
	definition: Giving value to a variable
	increment: increasing the value of a variable
	initialization: giving a variable a value when it is created
	name: name
	narrowing: Losing bits of information when converting
	object: a memory with a type
	operation: statement done berween operands
	type: the possible values and rules of use of a variable
	type safety: the variable is only used according to the rules of the type
	value: bits of an object
	variable: named object
*/