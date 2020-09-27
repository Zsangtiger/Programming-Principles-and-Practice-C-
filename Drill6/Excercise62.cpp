#include "std_lib_facilities.h"
#include "limits"
/*
2. Write a function print() that prints a vector of ints to cout.Give it two arguments : a string
for “labeling” the outputand a vector.*/
/*
3. Create a vector of Fibonacci numbers and print them using the function from exercise 2. To
create the vector, write a function, fibonacci(x, y, v, n), where integers xand y are ints, v is
an empty vector<int>, and n is the number of elements to put into v; v[0] will be xand v[1]
will be y.A Fibonacci number is one that is part of a sequence where each element is the sum
of the two previous ones.For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, . . . .
Your fibonacci() function should make such a sequence starting with its xand y arguments.*/

/*4. An int can hold integers only up to a maximum number.Find an approximation of that
maximum number by using fibonacci().*/

/*
5. Write two functions that reverse the order of elements in a vector<int>. For example, 1, 3, 5,
7, 9 becomes 9, 7, 5, 3, 1. The first reverse function should produce a new vector with the
reversed sequence, leaving its original vector unchanged. The other reverse function should
reverse the elements of its vector without using any other vectors (hint: swap).

*/

/*

6-Write versions of the functions from exercise 5, but with a vector<string>.

*/

/*
7. Read five names into a vector<string> name, then prompt the user for the ages of the people
named and store the ages in a vector<double> age. Then print out the five (name[i],age[i])
pairs. Sort the names (sort(name.begin(),name.end())) and print out the (name[i],age[i])
pairs. The tricky part here is to get the age vector in the correct order to match the sorted
name vector. Hint: Before sorting name, take a copy and use that to make a copy of age in
the right order after sorting name. Then, do that exercise again but allowing an arbitrary
number of names
*/

/*
9. Write a function that given two vector<double>s price and weight computes a value (an
“index”) that is the sum of all price[i]*weight[i]. Make sure to have
weight.size()==price.size().

*/
/*
10. Write a function maxv() that returns the largest element of a vector argument
*/
/*
11. Write a function that finds the smallest and the largest element of a vector argument and also
computes the mean and the median. Do not use global variables. Either return a struct
containing the results or pass them back through reference arguments. Which of the two ways of
returning several result values do you prefer and why?
*/

/*
12. Improve print_until_s() from §8.5.2. Test it. What makes a good set of test cases? Give
reasons. Then, write a print_until_ss() that prints until it sees a second occurrence of its quit
argument.

void print_until_s(vector<string> v, string quit)
{
for(int s : v) {
if (s==quit) return;
cout << s << '\n';
}
}

*/
/*
13. Write a function that takes a vector<string> argument and returns a vector<int> containing
the number of characters in each string.Also find the longest and the shortest string and the
lexicographically first and last string.How many separate functions would you use for these
tasks ? Why ?

// Using 1 separate function makes the code cleaner and separates functionality nicely.
// Using 1 function is better performance
*/

int constArgs(const int a) {
	return a;
}

vector<int> & wordLength(const vector<string>& v) {
	if (v.size() == 0){
		vector<int> a;
		return a;
	}
	vector<int> lengths;
	int shortIndex = 0, shortValue = v[0].length() -1;
	int longIndex = 0, longValue = v[0].length()-1;
	string first = v[0], last = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		int len = v[i].length() - 1;
		lengths.push_back(len);
		if (len < shortValue) {
			shortIndex = i;
			shortValue = len;
		}
		if (len > longValue) {
			longIndex = i;
			longValue = len;
		}
		if (v[i] < first)
			first = v[i];
		if (v[i] > last)
			last = v[i];
		
	}
	return lengths;
};

void print_until_s(const vector<string> &v, string quit, std::ostream os)



{ /*A good set of test cases, empty non empty vecs, vecs with & without s*/
	for (string s : v) {
		if (s == quit) return;
		os << s << '\n';
	}
}

void print_until_ss(const vector<string>& v, string quit, std::ostream os)
{
bool found = false;

/*A good set of test cases, empty non empty vecs, vecs with & without s*/
	for (string s : v) {
		if (s == quit && found) return;
		if (s == quit && !found) found = 1;
		os << s << '\n';

	}
}



struct stats {
	double min;
	double max;
	double mean;
	double med;
};

stats caclStats(vector<double> v) {
	int size = v.size();
	if (size == 0)
		error("Empty vector");
	double min, max, mean, med;
	min = std::numeric_limits<double>::max();
	max = std::numeric_limits<double>::min();
	mean = 0; med = 0;
	sort(v.begin(), v.end());
	if (size % 2 == 0)
		mean = (v[size / 2] + v[size / 2]) / 2;
	else
		mean = (size / 2 + 1);
	min = v[0];
	max = v[size - 1];
	double sum = 0;
	for (double i : v)
		sum += i;
	mean = sum = v.size();
	return stats{ min, max, mean, med };
	/*I prefer returning a struct to chaning variables. It is more straigth forward, shows better what you do,preserves state*/
}

double maxv(vector<double> v) {
	//I have the presupposition that v has elements, > is defined for the elements of v, and v has double elements.
	double max = v[0];
	for (double i : v)
		if (i > max)
			max = i;
	return max;
}
;
double calculateValue(const vector<double>& price, const vector<double>& weight) {
	if (weight.size() != price.size())
		error("vectors must have matching size\n");
	double sum = 0;
	for (int i = 0; i < price.size(); i++) {
		sum += price[i] * weight[i];
	}
	return sum;
}
void readNames(vector<string> & v) {
	string tmp = "";
	cout << "Enter a name\n";
	while(cin>>tmp) {
		if (tmp == "exit")
			return;
		v.push_back(tmp);
		cout << "Enter a name\n";
	}
	error("Failed to read string\n");
}

void eatCin(int & k) {
	while (true) {
		cin >> k;
			if (!cin) {
				cin.clear();
				cin.ignore();
				continue;
			}
		return;
	}
}

void readAges(vector<int>& v, int size) {

	int ct = 0;
	int tmp;
	while(ct < size){
		cout << "Enter an age\n";
		eatCin(tmp);
		v.push_back(tmp);
		ct++;
	}
}

void printNamesAndAges(vector<string> sv, vector<int> iv) {
	for (int i = 0; i < sv.size() && i < iv.size(); i++)
		cout << "name: " << sv[i] << " age: " << iv[i] << "\n";
}
void sortNamesAges() {
	vector<string> names;
	vector<int> ages;
	readNames(names);
	readAges(ages,names.size());
	cout << "Original names\n";
	printNamesAndAges(names, ages);
	//Dumb solution 1
	vector<string> names2(names);
	sort(names.begin(), names.end());
	vector<int> ages2(ages);
	for (int i = 0; i < names.size(); i++) {
		for (int j = 0; j < names2.size(); j++)
		{
			if (names2[j] == names[i])
				ages[i] = ages2[j];
		}
	}
	cout << "Sorted names\n";
	printNamesAndAges(names, ages);


}

vector<int> reverseVector1(const vector<int> &v) {
	vector<int> nw;
	nw.resize(v.size());

	for (int i = 0; i < v.size(); i++) {
		nw[v.size() - i - 1] = v[i];
	}
	return nw;
}

vector<string> reverseVector1(const vector<string>& v) {
	vector<string> nw;
	nw.resize(v.size());

	for (int i = 0; i < v.size(); i++) {
		nw[v.size() - i - 1] = v[i];
	}
	return nw;
}
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
vector<int> reverseVector2(vector<int>& v) {
	for (int i = 0; i < v.size() / 2; i++) {
		swap(v[i], v[v.size() - 1 - i]);
	}
	return v;
}

void swap(string a, string b) {

	string tmp = a;
	a = b;
	b = tmp;
}

vector<string> reverseVector2(vector<string>& v) {
	for (int i = 0; i < v.size() / 2; i++) {
		swap(v[i], v[v.size() - 1 - i]);
	}
	return v;
}




int overflowAddition(int a, int b) {
	int c = a + b;
	if (c < a || c < b)
	{
		cout << "The fibonacci estimation of the size of the int is: " << b << '\n';
		error("owerflow");
	}
	else
		return a + b;
}



void fibonacci(int x, int y, vector<int>& v, int n) {
	if (v.size() != 0)
		error("Vector must be empty\n");
	if (x > y) {
		v.push_back(y);
		v.push_back(x);
	}
	else {
		v.push_back(x);
		v.push_back(y);
	}
	/*
	for (int i = 2; i < n; i++) {
		v.push_back(v[i - 1] + v[i - 2]);
	}*/

	//to avoid unvanted copies of the content of the vector
	v.resize(n);
	for (int i = 2; i < n; i++) {
		v[i] = overflowAddition(v[i - 1], v[i - 2]);
	}


}

void print(const vector<int>& v, string b) {
	cout << b << " " ;
	if (v.size() > 0)
		for (int i : v)
			cout << i << " ";
	else
		cout << "Empty ";
}

int main() {
	try {
		vector<int> fibint;
		fibonacci(1, 3, fibint, 10);
		print(fibint, "basic fibonacci numbers");
		print(reverseVector1(fibint),"\nreversed fibint");
		print(fibint, "\nOriginal fibint");
		print(reverseVector2(fibint),"\nreference reversed fibint");
		print(fibint,"\nOriginal fibint");
		cout << '\n';
		sortNamesAges();
	}
	catch (exception e) {
		cerr << e.what();
	}
	return 0;
}