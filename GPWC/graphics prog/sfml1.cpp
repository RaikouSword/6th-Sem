#include <SFML/Graphics.hpp>
using namespace sf;

int main(){
    VideoMode vm(800,600);

    RenderWindow rm(vm, "Hello World");

    while(rm.isOpen()){
        rm.clear();
        //draw objs
        rm.display();
    }
}