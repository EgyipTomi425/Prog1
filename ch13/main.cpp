/*
    g++ main.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o progi `fltk-config --ldflags --use-images`
*/
#include "../GUI/Simple_window.h" 
#include "../GUI/Graph.h"
#include <iostream>
#include <vector>

int main()
{
    using namespace Graph_lib;
    Point tl {100,100};

Simple_window win {tl,800,1000,"NEM"};

Lines grid;
for(int i=100;i<800;i=i+100)
{
    grid.add(Point(i,0),Point(i,800));
}
for(int i=100;i<900;i=i+100)
{
    grid.add(Point(0,i),Point(800,i));
}

int x=0;
int y=0;
//négyzetek felpakolgatása
Vector_ref<Rectangle> negyzetek;
for(int i=0;i<8;i++)
{
	negyzetek.push_back(new Rectangle {Point{x,y}, 100, 100});
	negyzetek[negyzetek.size()-1].set_color(Color::red);
	negyzetek[negyzetek.size()-1].set_fill_color(Color::red);
	win.attach(negyzetek[negyzetek.size()-1]);
	x=x+100;
	y=y+100;
}
//négyzet felpakolgatásának vége

grid.set_color(Color::red);

win.attach(grid);

//képek
Vector_ref<Image> nagyrendor;
nagyrendor.push_back(new Image{Point(0,200),"rendorauto200.jpg"});
win.attach(nagyrendor[0]);

nagyrendor.push_back(new Image{Point(0,400),"rendorauto200.jpg"});
win.attach(nagyrendor[1]);

nagyrendor.push_back(new Image{Point(0,600),"rendorauto200.jpg"});
win.attach(nagyrendor[2]);

Image kisrendor{Point(0,0),"rendorauto100.jpg"};
win.attach(kisrendor);

Image fiat{Point(200,0),"fiat.jpg"};
win.attach(fiat);
//képek vége

x=0;
y=0;

for(int i=0;i<13;i++)
{
if(y%2==0)
{
y=y+1;
win.wait_for_button(); 
kisrendor.move(100,0);
}else
{
win.wait_for_button(); 
fiat.move(100,0);
y=y+1;
}
win.set_label("Debreceni Forma1");
}
}
