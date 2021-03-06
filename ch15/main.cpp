/*
    g++ main.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o progi `fltk-config --ldflags --use-images`
*/
#include "../GUI/Simple_window.h" 
#include "../GUI/Graph.h"
#include <vector>

using namespace Graph_lib;

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double cosinus(double x) {return cos(x);}
double sloping_cos(double x) {return (cosinus(x)+slope(x));}

struct person
{
private:
	string name;
	int age;
public:
	person(string nev, int kor)
	{
		name=nev;
		age=kor;
	}
	
	void kiiradat() const
	{
		std::cout<<"Nev: "<<name<<std::endl;
		std::cout<<"Kor: "<<age<<std::endl;
	}
	
	string getname() const
	{
		return name;
	}
	
	int getage() const
	{
		return age;
	} 
	
	void setname(string nev)
	{
		if(nev.find(";")>-1 || nev.find("[")>-1 || nev.find("]")>-1 || nev.find("*")>-1 || nev.find("&")>-1 || nev.find("^")>-1 || nev.find("%")>-1 || nev.find("$")>-1)error("invalid name");
		name=nev;
	}
	
	void setage(int kor)
	{
		if(kor<0 || kor>150) error("Hibas kormegadas");
		age=kor;
	}
	
	void beolvasadat()
	{	
		string nev="Peti";
		int kor=27;
		cin>>nev;
		cin>>kor;
		setname(nev);
		setage(kor);		
	}
};

ostream& operator<<(ostream& os, const person& ember)
{
	os << "Nev: " << ember.getname() << std::endl;
	os << "Kor: " << ember.getage();
	return os;
} 

istream& operator>>(istream& is, person& ember)
{	
	string a="0";
	int b=0;
	cin>>a;
	cin>>b;
	ember.setname(a); 
	ember.setage(b);
//	is >> ember.name(); 
//	is >> ember.age();
	return is;
}

int main()
{
	constexpr int xmax = 600;
	constexpr int ymax = 600;
	constexpr int x_orig = xmax/2;
	constexpr int y_orig = ymax/2;
        Point orig{x_orig,y_orig};
	constexpr int r_min = -10;
	constexpr int r_max = 11;
	constexpr int n_points = 400;
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;
	constexpr int xlength=400;
	constexpr int ylength=400;
	constexpr int xbegin=x_orig-(xlength/2);
	constexpr int ybegin=y_orig+(ylength/2);
	Simple_window win {Point{500,200},xmax,ymax,"Function graphing"};
	
	Axis x {Axis::x,Point{xbegin,y_orig}, xlength, xlength/x_scale, "1 == 20 pixel"};
	Axis y {Axis::y,Point{x_orig, ybegin}, ylength, ylength/y_scale, "1 == 20 pixel"};
	x.set_color(Color::red);
	y.set_color(Color::red);
	win.attach(x);
	win.attach(y);
	
	Function s{one,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s2{slope,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s3{square,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s4{cosinus,r_min,r_max,orig,n_points,x_scale,y_scale};
	Function s5{sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};
	
	Text ts{Point{100,y_orig+y_orig/2-70},"x/2"};
	
	win.attach(s);
	win.attach(s2);
	win.attach(s3);
	win.attach(s4);
	win.attach(s5);
	win.attach(ts);
	
	//structur
	person ember("Goofy",63);
	std::cout<<"F??ggv??nnyel:"<<std::endl;
	ember.kiiradat();
	std::cout<<std::endl<<"Oper??torral:"<<std::endl;
	std::cout<<ember<<std::endl<<std::endl;
	
	std::cout<<"F??ggv??nnyel:"<<std::endl;
	string neve="Peti";
	int kora=27;
	std::cout<<"Sz??k??zzel elv??lasztva adj meg egy nevet ??s egy kort. Pl: Peti 27"<<std::endl;
	ember.beolvasadat();
	ember.kiiradat();
	
	std::cout<<std::endl<<"Oper??torral:"<<std::endl;
	std::cout<<"Sz??k??zzel elv??lasztva adj meg egy nevet ??s egy kort. Pl: Peti 27"<<std::endl;
	std::cin>>ember;
	std::cout<<ember<<std::endl<<std::endl;
	
	std::cout<<"Vektoros beolvas??sok:"<<std::endl;
	vector<person>emberek;
	emberek.push_back(person("sa",21));

	win.wait_for_button();
	return 0;
}
