/*
    g++ main.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o progi `fltk-config --ldflags --use-images`
*/
#include "../GUI/Simple_window.h" 
#include "../GUI/Graph.h"

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
	
	void kiiradat()
	{
		std::cout<<"Nev: "<<name<<std::endl;
		std::cout<<"Kor: "<<age<<std::endl;
	}
};

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
	ember.kiiradat();

	win.wait_for_button();
	return 0;
}
