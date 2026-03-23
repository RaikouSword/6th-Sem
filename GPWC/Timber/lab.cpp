#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main(){
    Vector2f res;
    // res.300 = VideoMode::getDesktopMode().width;
    // res.400 = VideoMode::getDesktopMode().height;
    VideoMode vm(800,600);
    RenderWindow rm(vm,"Timber!",Style::Default);
    
    RectangleShape rect;
    rect.setSize(Vector2f(100,50));
    rect.setPosition(300,400);
    std::cout<<"Coordinates: ";
    std::cout << "Top-left: ("<<300<< "," <<400<<")\n";
    std::cout << "Top-right: ("<<300+100 << "," <<400<<")\n";
    std::cout << "Bottom-left: ("<<300<< "," <<400+50<<")\n";
    std::cout << "Bottom-right: ("<<300+100<< "," <<400+50<<")\n";
    std::cout << "Center: ("<<300+100/2 << "," <<400+50/2<<")\n";
    rect.setOrigin(100/2,50/2);
    rect.setPosition(300,400);
    rect.setRotation(120);

    RectangleShape sq1(Vector2f(50,50));
    RectangleShape sq2(Vector2f(50,50));
    RectangleShape sq3(Vector2f(50,50));
    RectangleShape sq4(Vector2f(50,50));
    sq1.setFillColor(Color::Red);
    sq2.setFillColor(Color::Blue);
    sq3.setFillColor(Color::Yellow);
    sq4.setFillColor(Color::Magenta);
    
    while(rm.isOpen()){
        Event event;
        while (rm.pollEvent(event)){
            if(event.type == Event::Closed)
                rm.close();
        }
        rm.clear();
        rm.draw(rect);
        rm.display();
    }

}