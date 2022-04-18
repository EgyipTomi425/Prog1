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

template<typename pointer>
 void readfile(pointer& mutato)
{
	std::ifstream fbe;
	fbe.open("itemlist.txt");
	while (!fbe.eof())
	{
		std::string nev;
		int iid;
		double ertek;

		fbe >> nev;
		fbe >> iid;
		fbe >> ertek;

		mutato->push_back(item(nev, iid, ertek));
	}
	mutato->pop_back();
	fbe.close();
}
 
struct namesort
{
	bool operator()(const item & item1, const item & item2) const
	{
		return bool(item1.getname() < item2.getname());
	}
};

struct iidsort
{
	bool operator()(const item& item1, const item& item2) const
	{
		return bool(item1.getiid() < item2.getiid());
	}
};

struct valuesort
{
	bool operator()(const item& item1, const item& item2) const
	{
		return bool(item1.getvalue() < item2.getvalue());
	}
};

void feladat1vector()
{
	std::vector<item>items;
	auto vecpointer = &items;
	readfile(vecpointer);
	std::cout << "vector beolvasva:" << std::endl << items << std::endl;

	std::sort(items.begin(), items.end(), namesort());
	std::cout << "vector sort by name:" << std::endl << items << std::endl;
	std::sort(items.begin(), items.end(), iidsort());
	std::cout << "vector sort by iid:" << std::endl << items << std::endl;
	std::sort(items.begin(), items.end(), valuesort());
	std::cout << "vector sort by value:" << std::endl << items << std::endl;

	vecpointer->push_back(item("horse shoe", 99, 12.34));
	items.push_back(item("Canon S400", 9988, 499.95));
	std::cout << items[10] << std::endl;
	std::cout << items[11] << std::endl;
	items.pop_back();
	vecpointer->pop_back();
	std::cout << std::endl;
	std::cout << std::endl;
}

void feladat1lista()
{
	std::list<item>items;
	auto listpointer = &items;
	readfile(listpointer);
}

int main()
{
	feladat1vector();
	feladat1lista();

	return 0;
}