#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <SFML/Graphics.hpp>
#include <cstdlib>

int main(){
    Vector2f res;
    res.x = VideoMode::getDesktopMode().width;
    res.y = VideoMode::getDesktopMode().height;

    VideoMode vm(res.x,res.y);

    RenderWindow rm(vm,"Pong", Style::Fullscreen);

    int score = 0;
    int lives = 3;

    Bat bat(res.x/2,res.y-50);
    Ball ball(res.x/2,0);

    Text hud;
    Font font;
    font.loadFromFile("Sprites/Font/DS-DIGI.TTF");
    hud.setFont(font);
    hud.setCharacterSize(60);
    hud.setFillColor(Color::White);
    hud.setPosition(10,10);

    Clock clock;

    while(rm.isOpen()){
        Event event;
        while(rm.pollEvent(event)){
            if(event.type==Event::Closed) rm.close();
        }
        
        // Handle the player quitting
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            rm.close();
        }

        // Handle the pressing and releasing of the arrow keys
        if(Keyboard::isKeyPressed(Keyboard::Left)){
            if(bat.getPosition().left<=0) bat.stopLeft();
            else bat.moveLeft();
        }else{
            bat.stopLeft();
        }
        if(Keyboard::isKeyPressed(Keyboard::Right)){
            if(bat.getPosition().left+bat.getPosition().width>=res.x) bat.stopRight();
            else bat.moveRight();
        }else{
            bat.stopRight();
        }

        // Update the delta time
        Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);

        // Update the HUD text
        std::stringstream ss;
        ss<<"Score: "<<score<<" Lives: "<<lives;
        hud.setString(ss.str());

        // Handle ball hitting the bottom
        if(ball.getPosition().top > rm.getSize().y){
            ball.reboundBottom();
            lives--;
            if(lives<=0){
                score = 0;
                lives = 3;
            }
        }
        // Handle ball hitting top
        if(ball.getPosition().top < 0){
            ball.reboundBatOrTop();
            score++;
        }
        // Handle ball hitting sides
        if(ball.getPosition().left<0 || ball.getPosition().left+10>rm.getSize().x){
            ball.reboundSides();
        }
        // Has the ball hit the bat?
        if(ball.getPosition().intersects(bat.getPosition())){
            ball.reboundBatOrTop();
        }

        //Draw
        rm.clear();
        rm.draw(hud);
        rm.draw(bat.getShape());
        rm.draw(ball.getShape());
        rm.display();
    }
    return 0;
}