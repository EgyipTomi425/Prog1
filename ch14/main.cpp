#include <iostream>
class B1 {
public:
	void vf()
	{
		std::cout<<"vf"<<std::endl;
	}
	
	virtual void f();
	
	virtual void pvf()=0;   //absztrakt lesz tőle az osztály, ezért nem példányosítható közvetlenül
};

void B1::f()
{
std::cout<<"f"<<std::endl;	
}

class D1 : public B1
{
public:
	void f() override
	{
		std::cout<<"f2"<<std::endl;	
	}
	
	void pvf() override
	{
		std::cout<<"pvf"<<std::endl;
	}
	
/*	void a()
	{
		std::cout<<"a"<<std::endl;
	} */
};

class D2 : public D1
{
public:
	void pvf() override
	{
		std::cout<<"pvf2"<<std::endl;
	}
};

class B2
{
public:
virtual void pvf()=0;
};

class D21 : public B2
{
public:
std::string karakter="Karakter";
void pvf() override
	{
		std::cout<<"pvf override "<<karakter<<std::endl;
	}
};

int main() {

	/*B1 bosztaly;
	bosztaly.f();    
	bosztaly.vf();
	bosztaly.pvf(); //absztrakt osztály nem példányosítható */
	
	D1 dosztaly;
	dosztaly.f();    
	dosztaly.vf();
	dosztaly.pvf(); 
	
	B1& b1ref=dosztaly;
	b1ref.f();
	b1ref.vf();
	b1ref.pvf(); 
	//b1ref.a(); B1-nek nem része, bár egyenlővé tehető, de nem hívható meg rá
	
	D2 d2osztaly;
	d2osztaly.f();
	d2osztaly.vf();
	d2osztaly.pvf();
	
	D21 d21;
	d21.pvf();
	
	B2& b2=d21;
	b2.pvf();
	
	return 0;
}

