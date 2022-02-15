/*
    g++ main.cpp ../GUI/Graph.cpp ../GUI/Window.cpp ../GUI/GUI.cpp ../GUI/Simple_window.cpp -o progi `fltk-config --ldflags --use-images`
*/
#include "../GUI/Simple_window.h" 
#include "../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;
    Point tl {100,100};

Simple_window win {tl,600,400,"Canvas"};

Image ii {Point(100,50),"image.jpg"};
win.attach(ii);

Axis xa{Axis::x,Point{20,300},280,10,"Buszjegymeter"};
win.attach(xa);
win.set_label("Szia, Uram!");

Axis ya{Axis::y,Point{20,300},280,10,"Cigimeter"};
ya.set_color(Color::green);
ya.label.set_color(Color::dark_red);
win.attach(ya);

Function sine {sin,0,100,Point{20,150},1000,50,50};
sine.set_color(Color::yellow);
win.attach(sine);

Polygon poly;
poly.add(Point{300,200});
poly.add(Point{350,100});
poly.add(Point{400,200}); 
poly.set_color(Color::green);
poly.set_style(Line_style::dash);
win.attach(poly);

Rectangle r {Point{200,200}, 100, 50};
win.attach(r);

Closed_polyline poly_rect;
poly_rect.add(Point{100,50});
poly_rect.add(Point{200,50});
poly_rect.add(Point{200,100});
poly_rect.add(Point{100,100});
win.attach(poly_rect);
poly_rect.add(Point{50,75});

r.set_fill_color(Color::red);
poly.set_style(Line_style(Line_style::dash,4));
poly_rect.set_style(Line_style(Line_style::dash,2));
poly_rect.set_fill_color(Color::yellow);

Text t {Point{150,150}, "Szia Uram, fiat cinquecento 'erdekel?"};
win.attach(t);
t.set_color(Color::red);
t.set_font(Font::times_bold);
t.set_font_size(20);

win.wait_for_button(); 
}
