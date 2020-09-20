
// 1. allow _ to be in variable names.
/* 2. Provide an assignment operator, =, so that you can change the value of a variable after you
introduce it using let.Discuss why that can be usefuland how it can be a source of problems
 Assignment to variables is useful because that way we can modify and reuse names.
 We can accidentally modify, modify set constants,have to create new grammar rules.
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
	const char assignment = '=';
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
		if (isalpha(ch) ||ch == '_') {
			string s;

			//read a variable
			s += ch;
			//wasn't appending
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch) || ch == '_')) s += ch;
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

vector<Variable> names = { Variable("k",1000) };



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
	{
		//This implemented assignment. However can't use ts.get() when we don't have another input char.
		Token nextTok = ts.get();
		if (nextTok.kind == LC::assignment)
			set_value(t.name, expression());
		else
			ts.unget(nextTok);
		return get_value(t.name);
		break;
	}
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