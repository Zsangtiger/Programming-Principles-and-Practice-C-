#include "std_lib_facilities.h"

/*

. Modify the program from exercise 19 so that when you enter an integer, the program will
output all the names with that score or score not found.

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

	cout << "Enter a score\n";
	int search_score;
	cin >> search_score;

	bool nameFound = false;
	int counter;
	for (int i = 0; i < names.size(); i++)
	{

		if (scores[i] == search_score)
		{
			nameFound = true;
			cout << "Name with a score of "<< search_score<<" : "<< names[i] << "\n";
		}
	}
	if (nameFound)
		;
	else
		cout <<"score not found\n";



	return 0;
}
