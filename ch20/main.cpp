#include <vector>
#include <list>
#include <array>
#include <iostream>
#include <iterator>
#include <bits/stdc++.h>

template<typename it1, typename it2>
it2 masolas(it1 t1,it1 t2,it2 t3)
{
	while(t1!=t2)
	{
		*t3=*t1;
		t1++;
		t3++;
	}
	return t3; 
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
    }
    
    //Nem lehet pl. vektorból arraybe másolni, mert nem egyezik meg a típusa. Max akkor lehetne, ha külön függvényt írnánk rá.
    //De azonos típus másolására működik:
    
    masolas(listarray.begin(),listarray.end(),listarray2.begin());
    
    std::cout<<"Masolt listaelemek:"<<std::endl;	
    it=listarray2.begin();
    while(it!=listarray2.end())
    {
    	std::cout<<*it<<std::endl;
    	it++;
    }
    std::cout<<std::endl;
    
    std::vector<int>::iterator vecit;
    int elem=3;
    vecit=std::find(begin(vectorarray),end(vectorarray),elem); //#include <bits/stdc++.h> kell hozzá
    if(vecit!=vectorarray.end())
    {
    	std::cout<<"Az elem "<<elem<<" a(z) "<<distance(vecit,vectorarray.begin())<<" pozicioban talalhato."<<std::endl; 
    }else
    {
    	std::cout<<"Az elem "<<elem<<" nem találhato."<<std::endl;
    }
    
    elem=27;
    vecit=std::find(begin(vectorarray),end(vectorarray),elem); //#include <bits/stdc++.h> kell hozzá
    if(vecit!=vectorarray.end())
    {
    	std::cout<<"Az elem "<<elem<<" a(z) "<<distance(vecit,vectorarray.begin())<<" pozicioban talalhato."<<std::endl; 
    }else
    {
    	std::cout<<"Az elem "<<elem<<" nem találhato."<<std::endl;
    }
}

