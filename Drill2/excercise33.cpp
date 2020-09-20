#include "std_lib_facilities.h"
#include <limits.h>

int main() {
	vector<double> distances;
	for (double i; cin >> i;)
	{
		distances.push_back(i);
	}

	numeric_limits<double> lim;

	double sum = 0, maxDist = lim.min(), minDist = lim.max(), mean = 0;



	for (double i : distances)
	{
		if (i < minDist)
			minDist = i;
		if (i > maxDist)
			maxDist = i;
	}

	cout << "The minimum distance is: " << minDist << "\n";
	cout << "The maximum distance is: " << maxDist << "\n";
	cout << "The mean distance is: " << sum / distances.size() << "\n";
	cout << "The sum distance is: " << sum << "\n";
	cout << "The number of distances is: " << distances.size() << "\n";




	return 0;
}