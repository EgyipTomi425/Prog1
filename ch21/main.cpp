#include "std_lib_facilities.h"

struct item
{
private:
	string name;
	int iid;
	double value;
public:
	item(string name1,int iid1, double value1)
	{
		name=name1;
		iid=iid1;
		value=value1;
	}
	
	string getname() const
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

ostream& operator<<(ostream& os, const item& targy)
{
	os << "Name: " << targy.getname() << " iid: " << targy.getiid() << " value: " << targy.getvalue() << endl;
	return os;
}

template<class t>
ostream& operator<<(ostream& os, const vector<t>& vektor)
{
	for(int i=0; i<vektor.size(); i++)
	{
		os << vektor[i];
	}
	return os;
}

void readfile(vector<item>&items)
{
	ifstream fbe;
	fbe.open("itemlist.txt");
	
	while(!fbe.eof())
	{
		string nev;
		int id;
		double ertek;
	
		fbe >> nev;	
		fbe >> id;
		fbe >> ertek;

		items.push_back(item(nev,id,ertek));
	}
	items.pop_back();	
	
	cout<<items[1];
}

int main()
{
	vector<item>items;
	readfile(items);	
	cout<<items;
}
