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

for(int i=0;i<8;i++)


grid.set_color(Color::red);

win.attach(grid);

win.wait_for_button(); 
}
