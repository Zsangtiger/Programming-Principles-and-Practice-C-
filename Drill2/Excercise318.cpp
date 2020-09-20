#include "std_lib_facilities.h"

/*

 Write a program that finds the min, max, and mode of a sequence of strings.

*/

int main() {

	string word,min,max,mode;
	vector<string> words;

	cout << "Give a sequence of strings if done enter 'q'\n";

	while (cin >> word)
	{
		words.push_back(word);
		if (word == "q")
			break;
	}

	int longest_sequence = 0;
	sort(words);

	if (words.size() > 0)
	{
		min = words[0];
		max = words[0];
	}
	int counter = 0;
	for (int i = 1; i < words.size(); i++) {
		
		if (words[i] == words[i - 1]) 
		{
			counter++;
			if (counter > longest_sequence)
			{
				longest_sequence = counter;
				mode = words[i];
			}
			else
				counter = 0;
		}
		if (words[i] > max)
			max = words[i];
		if (words[i] < min)
			min = words[i];
	}

	cout << "The min is :" << min << " \n";
	cout << "The max is :" << max << " \n";
	cout << "The mode is :" << mode << " \n";


	return 0;
}