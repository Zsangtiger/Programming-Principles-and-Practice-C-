
//
// This is example code from Chapter 6.7 "Trying the second version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

/*

Take the calculator from the file calculator02buggy.cpp. Get it to compile. You need to find
and fix a few bugs. Those bugs are not in the text in the book. Find the three logic errors
deviously inserted in calculator02buggy.cpp and remove them so that the calculator
produces correct results.


	This file is known as calculator02buggy.cpp

	I have inserted 5 errors that should cause this not to compile
	I have inserted 3 logic errors that should cause the program to give wrong results

	First try to find an remove the bugs without looking in the book.
	If that gets tedious, compare the code to that in the book (or posted source code)

	Happy hunting!

*/

#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Token{
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch)    // make a Token from a char
		:kind(ch), value(0) { }
	Token(char ch, double val)     // make a Token from a char and a double
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();   // make a Token_stream that reads from cin
	Token get();      // get a Token (get() is defined elsewhere)
	void putback(Token t);    // put a Token back
private:
	bool full;        // is there a Token in the buffer?
	Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
	:full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;       // copy t to buffer
	full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full) {       // do we already have a Token ready?
		// remove token from buffer
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {
	case '=':    // for "print"
	case 'x':    // for "quit"
	case '(': case ')': case '+': case '-': case '*': case '/': case '{': case '}': case '!':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token('8', val);   // let '8' represent "a number"
	}
	default:
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()

//------------------------------------------------------------------------------

// deal with numbers and parentheses
double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') 
			error("')' expected");
		return d;
	}
	case '{':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != '}')
			error("'}' expected");
		return d;
	}
	case '8':            // we use '8' to represent a number
		return t.value;  // return the number's value
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

// deal with '{' '}' 


double secondary() 
{
	double left = primary();
	Token t = ts.get();
	if (t.kind == '!') {
		
		int ileft = trunc(left);
		//return facotrial
		if (ileft == 0)
		{
			return 1;
		}
		else if (ileft < 0)
		{
			return left;
		}
		else 
		{
			for (int i = ileft-1; i > 1; i--)
				ileft *= i;
			return ileft;
		}

	}
	else {
		ts.putback(t);
		return left;
	}

}


// deal with *, /, and %
double term()
{
	double left = secondary();
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '*':
			left *= secondary();
			t = ts.get();
			break;
		case '/':
		{
			double d = secondary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);     // put t back into the token stream
			return left;
		}
	}
}

//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();        // get the next token from token stream

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);     // put t back into the token stream
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

int main()
try
{

	cout << "Welcome to our simple calculator.\nPlease enter expressions using floating - point numbers. Use +,-,/,* on doubles press x to exit press = to print\n";

	double val = 0;
	while (cin) {
		//OK
		

		Token t = ts.get();
		if (t.kind == 'x') break; // 'x' for quit
		if (t.kind == '=')        // ';' for "print now"
			cout << "=" << val << '\n';
		else
			ts.putback(t);
		t.value = expression();
		val = t.value;
		
	}
	keep_window_open();
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}

//------------------------------------------------------------------------------

/*
Since it is impossible to tell where the mistakes were and what they were i list the logical mistakes. Syntactic mistakes aren't at all interesting

A break was missing from the switch statement. The subtraction was an addition operator in expression.

*/

/*
Review.

1. What do we mean by “Programming is understanding”?
	In order to be able to write a program you must first understand the problem, and come up with a reasonably easy, correct solutin.
2. The chapter details the creation of a calculator program. Write a short analysis of what the
calculator should be able to do.
	The calculator sould be able to take an expression built from doubles, (, ), and from the +,-,*,/ operators. And calculate the result. After calculation it sould be able to do another calculation
3. How do you break a problem up into smaller manageable parts?
	By using funciton, and trying to find part which are relativaly short and can be reused in the project or in another project.
4. Why is creating a small, limited version of a program a good idea?
	Because we can test whather we understand the problem well enough. Also we will see what details we were missing in our plan. Getting closer to the correct solution. And if the sort program turn out to be correct we can develop it further.
5. Why is feature creep a bad idea?
	Because trying to implement too many funcitons can be confusing and significantly elongates the time needed for developing the core program
6. What are the three main phases of software development?
	Analysis of the problem and desingning the software.
	Implementing the software
	Debugging and testing
7. What is a “use case”?
	A use case a case how our program might be used.
8. What is the purpose of testing?
	Systematically running the program with predefined test cases to identify logical errors and bugs in the program
9. According to the outline in the chapter, describe the difference between a Term, an
Expression, a Number, and a Primary.
	A number is a floating point literal, A primary is either a term or and expressin between '(' ')', A term is a primary ( (expr) or number) or A term op Primary where op is either *,/, An Expression is a Term or Expression + Term or Expression - Term
10. In the chapter, an input was broken down into its component Terms, Expressions, Primarys,
and Numbers. Do this for (17+4)/(5–1).
	Assume that this is an expression: If this is an expression this must be a term since doesn't have + or - in it. If it is a term it is in the form of Term / Primary. The first term must be a primary since it doesn't have *, /. A primary is a number or starts with (. this starts with (. The first term is a primary in the form of (Expression). The expression is in the form of Expression + term. the expression is A term, the term is primary, the primary is a number. The term is a priamry, and the primary is a number so the first term is ( nubmer + number)
	The second term is a primary since it starts with (. This makes 5-1 and expression. This is an Expression - Term, expression. The first expression is term->primary->nubmer. the second one is term->primary->number.
11. Why does the program not have a function called number()?
	Because we don't want ot read a floating point number as a string of digits and '.'. We use the cin istream to parse it into a double.
12. What is a token?
	A token is a series of input chars that forms the smallest unit we want to work with.
13. What is a grammar? A grammar rule?
	A grammar is a set of simple rules.
	A grammar rule is something we use to parse input correctly. //I know this definition is not correct. The book doesn't supply one. The mathematical one for formal languages probably requires a lot of other notions i haven't introduced before so i go with this.
14. What is a class? What do we use classes for?
	A class is a way to define user defined types. It's a collection of data members and member funcitons.
15. How can we provide a default value for a member of a class?
	We can use type name = value. syntax int the class definition.
16. In the expression function, why is the default for the switch-statement to “put back” the token?
	Otherwise it would consume all the input somehting else might use.
17. What is “look-ahead”?
	Checking of the next input character in the input string literal.
18. What does putback() do and why is it useful?
	It is places the last read token into the input buffer. This way we don't discard values and we can read look-ahead
19. Why is the remainder (modulus) operation, %, difficult to implement in the term()?
	Because of typerules the modulo is only defined for integer literals and we are working with doubles.
20. What do we use the two data members of the Token class for?
	To store the type of the token and the value of the token if there is one.
21. Why do we (sometimes) split a class’s members into private and public members?
	The public members act as an interface the private members are implementation detail. Makes the calss easier to look at. Also hides implementation details form the users of our libarry.
22. What happens in the Token_stream class when there is a token in the buffer and the get()
	function is called?
		The token stream class return the token from the buffer and switches the buffer full variable to false.
23. Why were the ';' and 'q' characters added to the switch-statement in the get() function of the
Token_stream class?
	Because they are used to indicate the complete calculation and the exit from application commands.
24. When should we start testing our program?
	When we are finished with a part we can run we can test it.
25. What is a “user-defined type”? Why would we want one?
	User defined type is a collection of values and operations on those values. We use them to express ideas in code more clearly
26. What is the interface to a C++ “user-defined type”?
	The function declarations we can use to modify the data member. That is the public function declrarations.
27. Why do we want to rely on libraries of code?
	Because it is more maintainable and reusable than simply copying the code to projects.

	
Terms

analysis
	Figuring out what sould be done, and write a specification of the problem.
class
	User defined type. A collection of data members and member functions.
class member
	The data members of a class.
data member
	Members of a class.
design
	Creation an overall structure for the system. Defining the relationships bewteen the component of a system.
divide by zero
	Division by zero. It produces an error.
grammar
	A collection of grammar ruels
implementation
	The details that describe how somehting sould work
interface
	Tells the user what methods he can use from our class, and what type of parameter he needs to use it.
member function
	The functions of a class
parser
	A code that prduces tokens form an input is called a parser
private
	Access specifier inside a class. Private members cannot be a accessed from outside the class.
prototype
	A limited initial version of a program is called a prototype
pseudo code
	A code that is not program code. Just vaguely describes what the program is supposed to do
public
	Acces specifier inside a class. Public members can be accessed by anyone.
syntax analyzer
	parser
token
	is a series of input characters we accept as a unit.
use case	Example of how the program might be used.

	*/