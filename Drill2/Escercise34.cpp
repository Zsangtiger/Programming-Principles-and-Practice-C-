#include "std_lib_facilities.h"
/*Write a program to play a numbers guessing game.The user thinks of a number between 1 and
100 and your program asks questions to figure out what the number is(e.g., “Is the number you
	are thinking of less than 50 ? ”).Your program should be able to identify the number after asking
	no more than seven questions.Hint: Use the < and <= operators and the if - else construct.
*/
int main() {

	int initial = 50, lower_bound = 0, upper_bound = 100;
	

	cout << "Think of a whole number between 0 and 100\n";

	for (int i = 0; i < 7; i++) {
		cout << "Is your number greater than " << initial << " ?\nInsert y or n press w if the game got your number\n";
		string answer;
		cin >> answer;
		if (answer == "n")
		{
			upper_bound = initial;
			initial = (upper_bound + lower_bound) /2 ;
		}
		else if (answer == "y") 
		{
			lower_bound = initial;
			initial = (upper_bound + lower_bound) / 2;
		}
		else
		{
			cout << "you lose";
			break;
		}
	}

	return 0;
}