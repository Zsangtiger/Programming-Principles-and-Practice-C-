#include "std_lib_facilities.h"

/*

Define a class Name_value that holds a string and a value. Rework exercise 19 in Chapter 4
to use a vector<Name_value> instead of two vectors.

*/

class Name_value {
public:
	string name;
	int value;
};

int main() {

	

	vector<Name_value> names;
	
	string name;
	int score;

	cout << "Give name score pairs. Make sure you don't enter a name twice\n";

	while (cin >> name >> score)
	{
		if (name == "NoName" && score == 0)
			break;

		names.push_back(Name_value{name,score});
		

	}

	//Checking if a name is unique

	for (int i = 0; i < names.size(); i++)
	{
		for (int j = i + 1; j < names.size(); j++) {
			if (names[j].name == names[i].name)
				simple_error("Double names");
		}
	}

	for (int i = 0; i < names.size(); i++)
	{
		cout << "Name: " << names[i].name << " score: " << names[i].value << "\n";
	}




	return 0;
}
