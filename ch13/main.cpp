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
Rectangle r1 {Point{x,y}, 100, 100};
r1.set_color(Color::red);
r1.set_fill_color(Color::red);
win.attach(r1);
x=x+100;
y=y+100;

Rectangle r2 {Point{x,y}, 100, 100};
r2.set_color(Color::red);
r2.set_fill_color(Color::red);
win.attach(r2);
x=x+100;
y=y+100;

Rectangle r3 {Point{x,y}, 100, 100};
r3.set_color(Color::red);
r3.set_fill_color(Color::red);
win.attach(r3);
x=x+100;
y=y+100;

Rectangle r4 {Point{x,y}, 100, 100};
r4.set_color(Color::red);
r4.set_fill_color(Color::red);
win.attach(r4);
x=x+100;
y=y+100;

Rectangle r5 {Point{x,y}, 100, 100};
r5.set_color(Color::red);
r5.set_fill_color(Color::red);
win.attach(r5);
x=x+100;
y=y+100;

Rectangle r6 {Point{x,y}, 100, 100};
r6.set_color(Color::red);
r6.set_fill_color(Color::red);
win.attach(r6);
x=x+100;
y=y+100;

Rectangle r7 {Point{x,y}, 100, 100};
r7.set_color(Color::red);
r7.set_fill_color(Color::red);
win.attach(r7);
x=x+100;
y=y+100;

Rectangle r8 {Point{x,y}, 100, 100};
r8.set_color(Color::red);
r8.set_fill_color(Color::red);
win.attach(r8);
//négyzet felpakolgatásának vége

grid.set_color(Color::red);

win.attach(grid);

win.wait_for_button(); 
}
