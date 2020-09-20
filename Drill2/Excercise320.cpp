#include "std_lib_facilities.h"

/*

Write a program where you first enter a set of name-and-value pairs, such as Joe 17 and
Barbara 22. For each pair, add the name to a vector called names and the number to a
vector called scores (in corresponding positions, so that if names[7]=="Joe" then
scores[7]==17). Terminate input with NoName 0. Check that each name is unique and
terminate with an error message if a name is entered twice. Write out all the (name,score) pairs,
one per line

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
		for (int j = i+1; j < names.size(); j++) {
			if (names[j] == names[i])
				simple_error("Double names");
		}
	}

	for (int i = 0; i < names.size(); i++) 
	{
		cout << "Name: " << names[i] << " score: " << scores[i] << "\n";
	}




	return 0;
}
