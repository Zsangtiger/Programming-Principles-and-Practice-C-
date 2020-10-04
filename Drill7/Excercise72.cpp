#include "iostream"
#include <vector>
#include <algorithm>
/*
3. Replace Name_pair::print() with a (global) operator << and define == and != for
Name_pairs.
*/
using namespace std;

class Name_pairs {
public:
	Name_pairs();
	Name_pairs(const vector<string> &nn, const  vector<double> &aa);
	vector<string> getName()const ;
	vector<double> getAge() const ;
	void read_names();
	void read_ages();
	void print();
	void sort();
	bool operator==(const  Name_pairs&) const ;

private:
	vector<string> name;
	vector<double> age;

};
bool
vecEqual(const vector<string>& a, const vector<string>& b)
{
	if (a.size() != b.size()) {
		return false;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

vector<string> Name_pairs::getName()const
{
	return name;
}

vector<double> Name_pairs::getAge()const
{
	return age;
}

//This would be a perfect place for a template function however it is not covered until later chapters and as a result
//i don't want to use it here.
bool
vecEqual(const vector<double>& a, const vector<double>& b)
{
	if (a.size() != b.size()) {
		return false;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

	
bool Name_pairs::operator==(const Name_pairs &b) const
{
	if (this->name.size() != b.name.size() || this->age.size() != b.age.size())
	{
		return false;
	}
	else if (!vecEqual(this->name, b.name) || !vecEqual(this->age, b.age))
	{
		return false;
	}
	else {
		return true;
	}
}

bool operator!=(const Name_pairs& a, const Name_pairs& b)
{
	return !(a == b);
}

//This could be a member function or a friend funciton. For the same reasons as before and because the excercise asks i do it this way;
void operator<<(ostream & os, const Name_pairs& a)
{
	for (int i = 0; i < a.getName().size() && a.getAge().size(); i++) {
		os << "(" << a.getName()[i] << ", " << a.getAge()[i] << ")\n";
	}
}

Name_pairs::Name_pairs() : name{ vector<string>{} }, age{ vector<double>{} }{};
Name_pairs::Name_pairs(const vector<string> &nn,const  vector<double> &aa) : name{ nn }, age{ aa }
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
	while (cin >> tmp)
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
	//An invariant of age is that it must be greater than 0
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
		else if (temp < 0)
			continue;
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
		std::sort(name.begin(), name.end());

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
		cout << firstNamePairs;
		firstNamePairs.sort();
		cout << firstNamePairs;
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