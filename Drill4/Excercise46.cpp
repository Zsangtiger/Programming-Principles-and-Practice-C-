#include "std_lib_facilities.h"

/*

6. Write a program that checks if a sentence is correct according to the “English” grammar in
§6.4.1. Assume that every sentence is terminated by a full stop (.) surrounded by whitespace.
For example, birds fly but the fish swim . is a sentence, but birds fly but the fish swim
(terminating dot missing) and birds fly but the fish swim. (no space before dot) are not. For
each sentence entered, the program should simply respond “OK” or “not OK.” Hint: Don’t
bother with tokens; just read into a string using >>.

*/

class streamClass {
public:
	string getString();
	void putString(string);
	streamClass();
	string buffer;
	bool buffer_empty = true;
 };

streamClass::streamClass() {
	buffer = "";
	buffer_empty = true;
};

string streamClass::getString() {
	if (!buffer_empty)
	{
		buffer_empty = true;
		return buffer;
	}
	else
	{
		string tmp;
		cin >> tmp;
		if (!cin)
			error("failed to read character");
		else
		{
			return tmp;
		}
	
	}

};

void streamClass::putString(string paramString) {
	if (!buffer_empty)
		error("Buffer wasn't empty");
	else {
		buffer = paramString;
		buffer_empty = false;
	}

};

streamClass SC;

bool verb() 
{
	string readString = SC.getString();

	if (readString == "rules")
	{
		return true;
	}
	else if (readString == "fly")
	{
		return true;
	}
	else if (readString == "swim")
	{
		return true;
	}
	else
	{
		SC.putString(readString);
		return false;
	}

};

bool noun() 
{
	string readString = SC.getString();

	if (readString == "birds")
	{
		return true;
	}
	else if (readString == "fish")
	{
		return true;
	}
	else if (readString == "C++")
	{
		return true;
	}
	else
	{
		SC.putString(readString);
		return false;
	}
};

bool article() {
	string art = SC.getString();
	if (art == "the")
	{
		cout << "the == " << art;
		return noun();
	}
	else
	{
		SC.putString(art);
		return noun();
	}
}
namespace local {
	bool conjunction() {
		string tmp = SC.getString();

		if (tmp == "and" || tmp == "or" || tmp == "but")
			return true;
		else
			SC.putString(tmp);
		return false;
	};
}

bool ending() {
	string tmp = SC.getString();
	if (tmp == ".")
	{
		return true;
	}
	else
	{
		SC.putString(tmp);
		return false;
	}
}


bool sentence() {

	bool valid = article();
	if (valid) 
	{
		valid = verb();
		if (valid)
		{
			valid = ending();
			if (valid)
				return true;
			else
			{
				bool tmp = local::conjunction() && sentence();
				return tmp;
			}
		}
	}
}

int main() {
	try {
		string end = "";
		while (end != "x")
		{
			SC = streamClass();
			cout << "Enter a valid sentence\n";
			if (sentence())
				cout << "OK\n";
			else
			{
				cout << "not OK\n";
			}
			cout << "Type 'x' if you want to terminate the program. Press anything else to continue\n";
			cin >> end;
			if (!cin)
				error("Something went wrong");
		}
	}
	catch (exception & e)
	{
		e.what();
	}

	return 0;
}