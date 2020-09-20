#include "std_lib_facilities.h"

/*

Write a program that plays the game “Rock, Paper, Scissors.” If you are not familiar with the
game do some research (e.g., on the web using Google). Research is a common task for
programmers. Use a switch-statement to solve this exercise. Also, the machine should give
random answers (i.e., select the next rock, paper, or scissors randomly). Real randomness is
too hard to provide just now, so just build a vector with a sequence of values to be used as
“the next value.” If you build the vector into the program, it will always play the same game,
so maybe you should let the user enter some values. Try variations to make it less easy for the
user to guess which move the machine will make next.

*/

int main() {

	vector<int> steps = { 1,2,3,1,2,3,1,1,1,2,3,1,2,3,1 };
	int player;

	for (int it : steps)
	{
		cout<< "Iput 1 if you play rock, input 2 if you play paper, input 3 if you input scissor\n";
		if (cin >> player)
		{
			switch (player - it) {
			case 0:
				cout << "It is a draw but don't worry we play another game\n";
				break;
			case -1:
				cout << "Sadly you've list this round but don't worry there is always another one\n";
				break;
			case 1:
				cout << "Congrats you have won\n";
				break;
			case 2:
				cout << "Sadly you've list this round but don't worry there is always another one\n";
				break;
			case -2:
				cout << "Congrats you have won\n";
				break;
			default:
				cout << "Baaka I told oyu to insert 0,1 or 2 nothing else\n";
			}
			cout << "The computer played ";
			switch (it) {
			case 1:
				cout << "rock ";
				break;
			case 2:
				cout << "paper ";
				break;
			case 3:
				cout << "scissor ";
				break;
			default:
				cout << "Even i don't konw what ";

			};
			cout << "\n";
		}
		else {
			cout << "Baaka I told you to insert a number\n";
		}

	}
	cout << "I don't want to play with you any more rounds\n";

	return 0;
}