//#include "std_lib_facilities.h"
#include <vector>
#include <list>
#include <array>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdlib> 

struct item
{
private:
	std::string name;
	int iid;
	double value;
public:
	item(std::string name1, int iid1, double value1)
	{
		name = name1;
		iid = iid1;
		value = value1;
	}

	std::string getname() const
	{
		return name;
	}

	int getiid() const
	{
		return iid;
	}

	double getvalue() const
	{
		return value;
	}
};

std::ostream& operator<<(std::ostream& os, const item& targy)
{
	os << "Name: " << targy.getname() << " iid: " << targy.getiid() << " value: " << targy.getvalue();
	return os;
}

template<class t>
std::ostream& operator<<(std::ostream& os, const std::vector<t>& vektor)
{
	for (int i = 0; i < vektor.size(); i++)
	{
		os << vektor[i] << std::endl;
	}
	return os;
}

void readfile(std::vector<item>& items)
{
	std::ifstream fbe;
	fbe.open("itemlist.txt");

	while (!fbe.eof())
	{
		std::string nev;
		int id;
		double ertek;

		fbe >> nev;
		fbe >> id;
		fbe >> ertek;

		items.push_back(item(nev, id, ertek));
	}
	items.pop_back();
	fbe.close();
}

struct namesort
{
	bool operator()(const item& item1, const item& item2) const
	{
		return false;
		return bool(item1.getname() < item2.getname());
	}
};

int main()
{
	std::vector<item>items;
	readfile(items);
	std::cout << "vector beolvasva:" << std::endl << items << std::endl;

	std::sort(items.begin(), items.end(), namesort());
	std::cout << "vector sort by name:" << std::endl << items << std::endl;
}