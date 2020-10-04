#include "iostream"
#include <vector>
#include <algorithm>
/* 2. Design and implement a Name_pairs class holding(name, age) pairs where name is a string
and age is a double.Represent that as a vector<string>(called name) and a
vector<double>(called age) member.Provide an input operation read_names() that reads
a series of names.Provide a read_ages() operation that prompts the user for an age for each
name.Provide a print() operation that prints out the(name[i], age[i]) pairs(one per line) in
the order determined by the name vector.Provide a sort() operation that sorts the name
vector in alphabetical orderand reorganizes the age vector to match.Implement all
“operations” as member functions.Test the class (of course : test early and often)*/

using namespace std;

class Name_pairs {
public:
	Name_pairs();
	Name_pairs(vector<string> nn, vector<double> aa);
	void read_names();
	void read_ages();
	void print();
	void sort();

private:
	vector<string> name;
	vector<double> age;

};

Name_pairs::Name_pairs() : name{ vector<string>{} }, age{ vector<double>{} }{};
Name_pairs::Name_pairs(vector<string> nn, vector<double> aa) : name{ nn }, age{ aa }
{
	if (name.size() != age.size())
	{
		if (name.size() > age.size())
		{
			read_ages();
		}
		else 
		{
			throw exception{ "Vector size mismatch\n" };
		}
	}
};

void 
Name_pairs::read_names() 
{
	cout << "Give a series of names\n";
	string tmp = "";
	while (cin>>tmp) 
	{
		if (tmp == "exit")
			break;
		if (!cin)
			throw exception{};

		this->name.push_back(tmp);
	}
};

void
Name_pairs::read_ages()
{
	int counter = 0;
	int ageCurrentSize = age.size();
	while (counter + ageCurrentSize < name.size())
	{
		double temp;
		cout << "Give the age of: " << name[counter] << "\n";
		cin >> temp;
		if (!cin)
		{
			char dump[1000];
				cin.clear();
				cin.get(dump, 999);
		}
		else 
		{
			age.push_back(temp);
			counter++;
		}
	}
		
};

void
Name_pairs::print()
{
	for (int i = 0; i < name.size() && age.size(); i++) {
		cout << "(" << name[i] << ", " << age[i] << ")\n";
	}

};

void
Name_pairs::sort()
{
	if (name.size() != age.size())
		throw exception{ "Size mismatch, impossible to sort" };
	else 
	{
		vector<string> origNames = name;
		vector<double> age2(name.size());
		std::sort(name.begin(),name.end());

		for (int i = 0; i < name.size() && i < age.size(); i++) 
		{
			for (int j = 0; j < origNames.size(); j++)
			{
				if (name[i] == origNames[j])
				{
					age2[i] = age[j];
					continue;
				}
			}
		}

		age = age2;
	}
};

namespace helpers {
	void excerciseLoop()
	{
		Name_pairs firstNamePairs;
		firstNamePairs.read_names();
		firstNamePairs.read_ages();
		firstNamePairs.print();
		firstNamePairs.sort();
		firstNamePairs.print();
	}
};



int main() {
	try {
		helpers::excerciseLoop();
	}
	catch (exception e) {
		cerr << e.what();
	}
	
	return 0;
}