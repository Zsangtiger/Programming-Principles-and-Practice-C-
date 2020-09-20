#include "std_lib_facilities.h"


/*

Implement a little guessing game called (for some obscure reason) “Bulls and Cows.” The
program has a vector of four different integers in the range 0 to 9 (e.g., 1234 but not 1122) and
it is the user’s task to discover those numbers by repeated guesses. Say the number to be
guessed is 1234 and the user guesses 1359; the response should be “1 bull and 1 cow” because
the user got one digit (1) right and in the right position (a bull) and one digit (3) right but in the
wrong position (a cow). The guessing continues until the user gets four bulls, that is, has the
four digits correct and in the correct order.

*/

void guess(vector<int> & guess) {

	
	for (int k = 0; k < 4; k++)
	{

		int local_guess;
		if (! (cin >> local_guess))
			error("Bad input\n");
		if (local_guess < 0 || local_guess > 9)
			error("Not a digit\n");
		
		for (int i = 0; i < guess.size() ; i++) {
			if (local_guess == guess[i])
				error("Duplicate number");	
		}
		guess.push_back(local_guess);
	}

}

int main() {


	vector<int> data{1, 2, 3, 4};
	
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
		

	}catch(exception e) {
		cout << e.what();
	}
	
	

	return 0;
}