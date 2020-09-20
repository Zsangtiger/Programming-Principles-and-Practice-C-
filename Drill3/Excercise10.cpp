#include "std_lib_facilities.h"


/*

The program is a bit tedious because the answer is hard-coded into the program. Make a
version where the user can play repeatedly (without stopping and restarting the program) and
each game has a new set of four digits. You can get four random digits by calling the random
number generator randint(10) from std_lib_facilities.h four times. You will note that if you
run that program repeatedly, it will pick the same sequence of four digits each time you start the
program. To avoid that, ask the user to enter a number (any number) and call srand(n) where n
is the number the user entered before calling randint(10). Such an n is called a seed, and
different seeds give different sequences of random numbers.

*/

void guess(vector<int> & guess) {


	for (int k = 0; k < 4; k++)
	{

		int local_guess;
		if (!(cin >> local_guess))
			error("Bad input\n");
		if (local_guess < 0 || local_guess > 9)
			error("Not a digit\n");

		for (int i = 0; i < guess.size(); i++) {
			if (local_guess == guess[i])
				error("Duplicate number");
		}
		guess.push_back(local_guess);
	}

}

int main() {


	while (true) {

		cout << "give a seed\n";
		int seed;
		cin >> seed;
		if (!cin)
			error("Invalid seed\n");
		srand(seed);
		vector<int> data(4);
		for (int i = 0; i < 4; i++)
		{
			data[i]=randint(10);
		}
		

		bool win = false;

		cout << "Cows and bulls game. Insert a 4 different digits\n";

		try {
			while (!win)
			{
				int bull = 0, crow = 0;
				vector<int> user_guess;
				guess(user_guess);

				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						if (data[i] == user_guess[j])
						{
							if (i == j)
								bull++;
							else
								crow++;
						}
					}
				}

				cout << "You have guessed " << bull << " bulls and " << crow << " crows with " << user_guess[0] << user_guess[1] << user_guess[2] << user_guess[3] << "\n";
				if (bull == 4)
					win = true;

			}
			if (win)
				cout << "Congratulations, you have won\n";


		}
		catch (exception e) {
			cout << e.what();
		}

	}

	return 0;
}