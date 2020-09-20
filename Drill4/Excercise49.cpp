#include "std_lib_facilities.h"

/*

Write a program that reads digits and composes them into integers. For example, 123 is read as
the characters 1, 2, and 3. The program should output 123 is 1 hundred and 2 tens and 3
ones. The number should be output as an int value. Handle numbers with one, two, three, or
four digits. Hint: To get the integer value 5 from the character '5' subtract '0', that is,
'5'–'0'==5.

*/


void computeValue(string num) 
{

	//First char can't be null;
	//Only works for max 4 digits;

	bool firstChar = true;
	int sum = 0;
	string message = "";
	int size = num.size()-1;
	for (int i = 0; i < size; i++)
	{
		char tempChar = num[i];
		int tempInt = tempChar - '0';
		if (firstChar && tempChar == '0' && size > 1)
			continue;
		else {
			firstChar = false;
			switch (size - i) {
			case 4:
				sum += 1000 * tempInt;
				message.push_back(tempChar);
				message += " thousands and ";
				break;
			case 3:
				sum += 100 * tempInt;
				message.push_back(tempChar);
				message += " hundreds and ";
				break;
			case 2:
				sum += 10 * tempInt;
				message.push_back(tempChar);
				message += " tens and ";
				break;
			case 1:
				sum += tempInt;
				message.push_back(tempChar);
				message += " ones.";
				break;
			default:
				error("Too many digits\n");
			}
		}
	}
	std::cout << sum << " equals " << message << "\n";

}

int main() {

	//Frist try;
	try {
		char writeChar;
		string number;
		cout << "write 1,2,3 or 4 digits\n";
		do
		{
			cin.get(writeChar);
			if (!cin)
				error("Can't write char\n");
			number.push_back(writeChar);
		}							//This part of the code is broken. Get ignores space
		while (writeChar != '\n' && writeChar != 32 );
		computeValue(number);

	}
	catch (exception & e) {
		cout<< e.what();
	}
}