

/*
Modify Token_stream::get() to return Token(print) when it sees a newline. This implies
looking for whitespace characters and treating newline ('\n') specially. You might find the
standard library function isspace(ch), which returns true if ch is a whitespace character,
useful.
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
	const char constVal = '0';
}
Token Token_stream::get()
{
	if (full) { full = false; return buffer; }
	char ch;
	cin.get(ch);
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
		if (isalpha(ch) || ch == '_') {
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
			if (s == "const") return Token(LC::constVal);
			return Token(LC::name, s);
		}
		if (isspace(ch)) 
		{
			cout << "Space\n";
			if (ch == '\n')
				return Token(LC::print);
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
	bool cv;
	Variable(string n, double v, bool c = 0) :name(n), value(v), cv(c) { }
};

//vector<Variable> names = { Variable("k",1000,true) };

class Symbol_table {
private:
	vector<Variable> var_table;
public:
	Symbol_table() { ; };
	Symbol_table(vector<Variable>& tmp);
	double get(string);
	void set(string, double);
	bool is_declared(string);
	void declare(Variable);

};
Symbol_table tbl;

Symbol_table::Symbol_table(vector<Variable> & tmp) {
	this->var_table = tmp;
}

void Symbol_table::declare(Variable tmp) {
	var_table.push_back(tmp);
}

double Symbol_table::get(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return var_table[i].value;
	error("get: undefined name ", s);
}

void Symbol_table::set(string s, double d)
{
	for (int i = 0; i <= var_table.size(); ++i)
		if (var_table[i].name == s) {
			if (var_table[i].cv == false) {
				var_table[i].value = d;
				return;
			}
			else
			{
				error("You can't modify const values\n");
			}
			return;
		}
	error("set: undefined name ", s);
}

bool Symbol_table::is_declared(string s)
{
	for (int i = 0; i < var_table.size(); ++i)
		if (var_table[i].name == s) return true;
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
			tbl.set(t.name, expression());
		else
			ts.unget(nextTok);
		return tbl.get(t.name);
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
	//This might be a part of the class.
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (tbl.is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind == LC::constVal) {
		Token t3 = ts.get();
		if (t3.kind != '=') error("= missing in declaration of ", name);
		double d = expression();
		tbl.declare(Variable(name, d, true));
		return d;
	}
	else if (t2.kind != '=') error("= missin in declaration of ", name);
	else
	{
		double d = expression();
		tbl.declare(Variable(name, d, false));
		return d;
	}
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