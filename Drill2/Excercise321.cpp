#include "std_lib_facilities.h"

/*

 Modify the program from exercise 19 so that when you enter a name, the program will output
the corresponding score or name not found.

*/

int main() {

	vector<string> names;
	vector<int> scores;
	string name;
	int score;

	cout << "Give name score pairs. Make sure you don1t enter a name twice\n";

	while (cin >> name >> score)
	{
		if (name == "NoName" && score == 0)
			break;

		names.push_back(name);
		scores.push_back(score);

	}

	//Checking if a name is unique

	for (int i = 0; i < names.size(); i++)
	{
		for (int j = i + 1; j < names.size(); j++) {
			if (names[j] == names[i])
				simple_error("Double names");
		}
	}

	cout << "Enter a name\n";
	string searc_name;
	cin >> searc_name;

	bool nameFound = false;
	int counter;
	for (int i = 0; i < names.size(); i++) 
	{

		if (names[i] == searc_name)
		{
			nameFound = true;
			counter = i;
		}
	}
	if (nameFound)
		cout << "Name is: " << names[counter] << " score is: " << scores[counter] << "\n";
	else
		cout << "Name not found in the list\n";



	return 0;
}
