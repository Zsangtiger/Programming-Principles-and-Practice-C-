#include "std_lib_facilities.h"

/*

There is an old story that the emperor wanted to thank the inventor of the game of chess and
asked the inventor to name his reward. The inventor asked for one grain of rice for the first
square, 2 for the second, 4 for the third, and so on, doubling for each of the 64 squares. That
may sound modest, but there wasn’t that much rice in the empire! Write a program to calculate
how many squares are required to give the inventor at least 1000 grains of rice, at least
1,000,000 grains, and at least 1,000,000,000 grains. You’ll need a loop, of course, and
probably an int to keep track of which square you are at, an int to keep the number of grains on
the current square, and an int to keep track of the grains on all previous squares. We suggest
that you write out the value of all your variables for each iteration of the loop so that you can
see what’s going on.


*/

int main() {

	int lim1 = 1000, lim2 = 1000000, lim3 = 1000000000;

	int sum = 0,rice_on_square = 1, count = 1;

	bool greater_than_lim1 = false, greater_than_lim2 = false, greater_than_lim3 = false;

	while (!greater_than_lim3)
	{
		sum += rice_on_square;

		if (sum >= lim1 && !greater_than_lim1) {
			greater_than_lim1 = true;
			cout << "You need at least " << count << " squares to get " << lim1 << " grains of rice\n";
		}
		if (sum >= lim2 && !greater_than_lim2) {
			greater_than_lim2 = true;
			cout << "You need at least " << count << " squares to get " << lim2 << " grains of rice\n";
		}
		if (sum >= lim3 && !greater_than_lim3) {
			greater_than_lim3 = true;
			cout << "You need at least " << count << " squares to get " << lim3 << " grains of rice\n";
		}

		rice_on_square *= 2;
		count++;

	}

	return 0;
}