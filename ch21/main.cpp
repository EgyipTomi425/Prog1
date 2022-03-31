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
};

void drill1()
{
	ifstream fbe;
	fbe.open("itemlist.txt")
	
}

int main()
{
	drill1();
}
