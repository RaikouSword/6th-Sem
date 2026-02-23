#include <SFML/Graphics.hpp>
using namespace sf;

int main(){
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;

    VideoMode vm(resolution.x,resolution.y);
    RenderWindow rm(vm,"Hello!!");

    RectangleShape rect1;
    Vector2f size(100,100);
    rect1.setSize(size);
    // rect1.setOrigin(size.x/2.0, size.y/2.0);
    rect1.setPosition(resolution.x/2.0-size.x/2.0,resolution.y/2.0-size.y/2.0);
    rect1.setOutlineColor(sf::Color(54, 69, 79)); //deep charcoal
    rect1.setOutlineThickness(4);
    rect1.setFillColor(sf::Color(112, 128, 144)); //slate gray
    
    while(rm.isOpen()){
        rm.clear(Color(250, 240, 230)); //off-white
        rm.draw(rect1);
        rm.display();
    }
}