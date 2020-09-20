#include "std_lib_facilities.h"
#include <limits.h>

int main(){
	vector<double> distances;
	for (double i; cin >> i;)
	{
		distances.push_back(i);
	}

	numeric_limits<double> lim;
	
	double sum = 0, max = lim.min(), min = lim.max(), max = 0, mean = 0;

	

	for (double i : distances) 
	{
		if (i < min)
			min = i;
		if (i > max)
			max = i;
	}

	cout << "The minimum distance is: " << min << "\n";
	cout << "The maximum distance is: " << max << "\n";
	cout << "The mean distance is: " << sum / distances.size() << "\n";
	cout << "The sum distance is: " << sum << "\n";
	cout << "The number of distances is: " << distances.size() << "\n";




	return 0;
}