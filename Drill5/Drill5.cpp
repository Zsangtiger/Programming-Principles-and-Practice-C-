
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.

1. Starting from the file calculator08buggy.cpp, get the calculator to compile.
2. Go through the entire program and add appropriate comments.
3. As you commented, you found errors (deviously inserted especially for you to find). Fix them;
they are not in the text of the book.
4. Testing: prepare a set of inputs and use them to test the calculator. Is your list pretty complete?
What should you look for? Include negative values, 0, very small, very large, and “silly” inputs.


5. Do the testing and fix any bugs that you missed when you commented.
6. Add a predefined name k meaning 1000.
7. Give the user a square root function sqrt(), for example, sqrt(2+6.7). Naturally, the value of
sqrt(x) is the square root of x; for example, sqrt(9) is 3. Use the standard library sqrt()
function that is available through the header std_lib_facilities.h. Remember to update the
comments, including the grammar.
8. Catch attempts to take the square root of a negative number and print an appropriate error
message.


9. Allow the user to use pow(x,i) to mean “Multiply x with itself i times”; for example,
pow(2.5,3) is 2.5*2.5*2.5. Require i to be an integer using the technique we used for %.
10. Change the “declaration keyword” from let to #.
11. Change the “quit keyword” from quit to exit. That will involve defining a string for quit just
as we did for let in §7.8.2.
*/

//Adding a char,string consturctor to Token allowed the project to be compiled.
//Let variable declaration wasn't working properly
//Ending with something illegal isn't working properly
//breaks were missing;
//() expressions were'not working properly.
//quit wasn't working
//% wasn't implemented

/*
Test cases:
-2;
0;
3;
1+1;
1-1;
-1-1;
-1+4;
-3--3;
-3*6;
-10*-12;
(-10)*3;
(3+1)*10;
5%2;
-9%-2;
(10%3)*10+2;
let alma = 10;
alma;
alma = 30;
let alma2;
let alma 2 = 2+2;
let alma3 = -3;
let alma4 = -10.12;
-10.12;
110.4;


Review
1. What is the purpose of working on the program after the first version works? Give a list of
reasons.
	Adding new features.
	Finding mistakes made in the earlier stages.
	We have an option to make the code better/ easier to maintain/ cleaner

2. Why does 1+2; q typed into the calculator not quit after it receives an error?

	If we find ; we look for an expression and q is not one.

3. Why did we choose to make a constant character called number?
	Before that we used number 8 to indicate a number. It was arbitrary and hard to remember.

4. We split main() into two separate functions. What does the new function do and why did we
split main()?

	Main was handling errors and running the calculation loop. This is 2 logically separate steps and every funciton should be one logical unit.
5. Why do we split code into multiple functions? State principles.
	^

6. What is the purpose of commenting and how should it be done?
	To express details the code can not, to state what the code is supposed to do. Use commnets to make understanding easier don't be redundant
	if a comment is redundant probably need some change in the  code.
7. What does narrow_cast do?
	Tests if a cast from one value to another would cause narrowing. If it causes narrowing it throws instead.
8. What is the use of symbolic constants?
	To use values which more clearly represent our purpose with using it. Make it easier to replace the original value.
9. Why do we care about code layout?
	The easier the code to read the easier is to find bugs.
10. How do we handle % (remainder) of floating-point numbers?
	Either not allowing it if narrowing happens or using the float modulo operation from cmath
11. What does is_declared() do and how does it work?
	Checks if a variable name is in the vector of variables.

12. The input representation for let is more than one character. How is it accepted as a single
token in the modified code?
	We read alnum characters and check if the "let" sequence is found.

13. What are the rules for what names can and cannot be in the calculator program?
	names must start with an alnum character and can have alnum chars and ints in it.
14. Why is it a good idea to build a program incrementally?
	We can find error. If we have a working version we can understand what our program does, and what it doesn't do.
15. When do you start to test?
	When i have a working core program, after a change of the original code, after the implementation of a new feature.
16. When do you retest?
	^
17. How do you decide what should be a separate function?
	Separate logical units should be separate functions. 1 function should have one rule.
18. How do you choose names for variables and functions? List possible reasons.
	Find a name that is relatively short, describes what the funciton does, or the variable holds, i use abbreviations to make it short.
19. Why do you add comments?
	To help me and other to understand the code. Other who never seen the code, for me is for when i forgot what the code was supposed to do.
20. What should be in comments and what should not?
	What the code supposed to do. What is not finished. What causes errors. What is yet to be implemented. Our presuppositions when we implement a functions. 
	What the code does describes should not be a comment. When something must be stated over and over again it probably should not be a comment.
21. When do we consider a program finished?
	I don't think we consider a program finished. To be fair after implementing all the critical features the program can be released and there is always some improvement for the code, 
	Usually a deadline is when a program is released.

*/

/*
Terms
code layout
	How your code is spaced/placed in your files
commenting
	The addition of comments to the soruce code.
error handling
	The way our program behaves when a runtime error occures
feature creep
	When we want to implement too many features too early
maintenance
	Keeping the code clean and working and bugs and error free
recovery
	The program continues to work properly after an error occured
revision history
	A list of changes made to the problem should be mentioned with date and name and with the list of changes
scaffolding
	Building a limited version of the software
symbolic constant
	Giving names to constant values we use
testing	Running our program against a set of systematically selected inputs to find possible errors
*/
#include "std_lib_facilities.h"

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val), name("") { }
	Token(char ch, string nme) :kind(ch), value(0), name(nme) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer = t; full = true; }
	void ignore(char);
};
namespace LC {
	const char let = 'L';
	const char quit = 'Q';
	const char print = ';';
	const char number = '8';
	const char name = 'a';
	const char sqrt = '9';
	const char pow = '7';
}
Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '#': 
		return Token(LC::let);
		break;
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
	double val;
	cin >> val;
	return Token(LC::number, val);
	}
	default:
		if (isalpha(ch)) {
			string s;

			//read a variable
			s += ch;
			//wasn't appending
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;
				cin.unget();
			
			//if (s == "let") return Token(LC::let);
			if (s == "exit") return Token(LC::quit);
			if (s == "sqrt") return Token(LC::sqrt);
			if (s == "pow") return Token(LC::pow);
			return Token(LC::name, s);
		}
		error("Bad token");
	}
}

//Reads characters until a specific value is met.
void Token_stream::ignore(char c)
{
	 
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names = {Variable("k",1000)};



double get_value(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d)
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s)
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

//Get's the most tightly binding units in an expression that is unary +/- , (),variables, numbers, sqrt() and returns the value of it;
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
		//In this case if the first ( is missing the number will be part of the sqrt identifier. That is how to names have been defined.
	case LC::pow: 
	{
		Token nextTok = ts.get();
		if (nextTok.kind != '(') error("Missing '('\n");
		double val1 = expression();
		nextTok = ts.get();
		if (nextTok.kind != ',') error("Illegal syntax: missing ',' \n");
		double val2 = expression();
		nextTok = ts.get();
		if (nextTok.kind != ')') error("Missing ')'\n");
		return pow(val1, narrow_cast<int>(val2));
		break;
	
	}
	
	case LC::sqrt:
	{
		Token nextTok = ts.get();
		if (nextTok.kind != '(') error("Missing '('\n");
		double val = expression();
		nextTok = ts.get();
		if (nextTok.kind != ')') {
			ts.unget(nextTok);
			error("Missing ')'\n");
		}
			/* //This piece of code should work just fine. It does not.
			errno = 0;
			if(math_errhandling & MATH_ERRNO)
				if (errno == EDOM) error("Domain error\n");*/
		if (val < 0)
			error("Domain error\n");

		return std::sqrt(val);
		break;
		
	}
	case '(':
	{	double d = expression();
	t = ts.get();
	if (t.kind != ')') error("')' expected");
	return d;
	}
	
	break;
	case '-':
		return -primary();
		break;
	case '+':
		return primary();
		break;
	case LC::number:
		return t.value;
		break;
	case LC::name:
		return get_value(t.name);
		break;
	default:
		error("primary expected");
	}
}

//Calculates binary expression with * and / in it.
double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		case '%':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left = narrow_cast<int>(left) % narrow_cast<int>(d);
			break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

//Calculates binary expressions with - and + in it.
double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

//Gets a name, and if it isn't declared assigns a value to it and appends to the variables array
double declaration()
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

//Tells wheater what we read is a declaration or an expression
double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case LC::let:
		return declaration();
	default:
		ts.unget(t);
		return expression();
	}
}

//Used in catch block discards chars until a Token type we specified
void clean_up_mess()
{
	ts.ignore(LC::print);
}

const string prompt = "> ";
const string result = "= ";


//Main loop handles multiple calculations and escaping
void calculate()
{
	
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == LC::print) t = ts.get();
		if (t.kind == LC::quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error & e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
};


int main()

try {
	calculate();
	return 0;
}
catch (exception & e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}