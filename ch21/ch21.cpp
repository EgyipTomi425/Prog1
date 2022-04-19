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
#include <map>

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

template<class t>
std::ostream& operator<<(std::ostream& os, const std::list<t>& lista)
{
	for (auto it=lista.begin(); it != lista.end(); it++)
	{
		os << *it << std::endl;
	}
	return os;
}

template<typename t1, typename t2>
std::ostream& operator<<(std::ostream& os, const std::map<t1, t2>& m)
{
	for (const auto& p : m)
	{
		os << "{ " << p.first << ", " << p.second << " }" << std::endl;
	}
	return os;
}

template<typename t1, typename t2>
std::istream& operator>>(std::istream& is, std::map<t1, t2>& m)
{
	t1 type1;
	std::cin >> type1;
	t2 type2;
	std::cin >> type2;
	m.insert({ type1,type2 });
	return is;
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

template<typename t1, typename t2>
void copyswap(const std::map<t1,t2>& m1, std::map<t2,t1>& m2)
{
	for (const auto& p : m1)
	{
		m2.insert({ p.second,p.first });
	}
}

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
	std::cout << "lista beolvasva:" << std::endl << items << std::endl;

	items.sort(namesort());
	std::cout << "lista sort by name:" << std::endl << items << std::endl;
	items.sort(iidsort());
	std::cout << "lista sort by iid:" << std::endl << items << std::endl;
	items.sort(valuesort());
	std::cout << "lista sort by value:" << std::endl << items << std::endl;

    listpointer->push_back(item("horse shoe", 99, 12.34));
	std::list<item>::iterator listit;
	listit = items.end();
	listit--;
	std::cout << *listit << std::endl;

	items.push_back(item("Canon S400", 9988, 499.95));
	listit++;
	std::cout << *listit << std::endl;
	
	items.pop_back();
	listpointer->pop_back();
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

void feladat2()
{
	std::map<std::string, int>msi;
	msi.insert({"Gabor", 2});
	msi.insert({"Anna", 4});
	msi.insert({"Laci", 8});
	msi.insert({"Janos", 12});
	msi.insert({"Benedek", 21});
	msi.insert({"Hanna", 74});
	msi.insert({"Gabriella", 102});
	msi.insert({"Peter", 1});
	msi.insert({"Nandor", 67});
	msi.insert({"Bence", 7});
	std::cout << "Using map:" << std::endl;
	std::cout << msi << std::endl;
	msi.erase({ "Gabor" });
	msi.erase({ "Anna" });
	msi.erase({ "Laci" });
	msi.erase({ "Janos" });
	msi.erase({ "Hanna" });
	msi.erase({ "Gabriella" });
	msi.erase({ "Peter" });
	msi.erase({ "Nandor" });
	msi.erase({ "Bence" });
	msi.erase({ "Benedek" });
	std::cout << msi;

	//en most csak 5 part fogok beolvasni, mert ennyit is elmeny vegiggepelni
	std::cin >> msi;
	std::cin >> msi;
	std::cin >> msi;
	std::cin >> msi;
	std::cin >> msi;
	std::cout << msi << std::endl;

	int sum = 0;
	for (const auto p : msi)
	{
		sum += p.second;
	}
	std::cout << "sum of the (int) elements: " << sum << std::endl;
	std::cout << std::endl;

	std::cout << "The mis map:" << std::endl;
	std::map<int, std::string>mis;
	copyswap(msi, mis);
	std::cout << mis << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
}

int main()
{
	feladat1vector();
	feladat1lista();
	feladat2();

	return 0;
}