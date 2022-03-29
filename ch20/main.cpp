#include <vector>
#include <list>
#include <array>
#include <iostream>

struct Copy
template<typename it1, typename it2>
struct copy
{

}

int main()
{
	std::array<int,10>tomb={0,1,2,3,4,5,6,7,8,9};
	std::vector<int>vectorarray;
	for(int i=0;i<10;i++)
	{
        vectorarray.push_back(i);
	}
	std::list<int>listarray;
	std::list<int>::iterator it;
	it=listarray.begin();
	for(int i=0;i<10;i++)
	{
        listarray.push_back(i);
	}

	std::array<int,10>tomb2=tomb;
	std::vector<int>vectorarray2=vectorarray;
	std::list<int>listarray2=listarray;

    for(int i=0;i<10;i++)
    {
        tomb[i]=tomb[i]+2;
        vectorarray[i]=vectorarray[i]+3;
    }
    for(it=listarray.begin();it!=listarray.end();it++)
    {
        *it=*it+5;
        std::cout<<*it<<std::endl;
    }
}

