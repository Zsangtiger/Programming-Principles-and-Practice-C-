#include "std_lib_facilities.h"


/*

Redo the “Bulls and Cows” game from exercise 12 in Chapter 5 to use four letters rather than
four digits.

*/
bool isDifferent(string param) {
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 4; j++)
		{
			if (param[i] == param[j])
			{
				return false;
			}
		}
	}
	return true;
}
string guess() {
	// string must be 4 letters long. Must be 4 different letters. Ideally small letters. 
	string tmp;
	do
	{
		cout << "Guess 4 different letters\n";
		cin >> tmp;
		if (!cin)
			error("Something went wrong\n");
	}while (tmp.length() != 4 || !isDifferent(tmp));
	
	return tmp;
}

int main() {

	string data = "abcd";
	bool win = false;
	cout << "Cows and bulls game. Insert a 4 different digits\n";
	try {
		while (!win)
		{
			int bull = 0, crow = 0;
			string user_guess;
			user_guess = guess();
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



	return 0;
}