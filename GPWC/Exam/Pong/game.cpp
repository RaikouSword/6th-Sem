#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf; 

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
        
        // Window close
        if(Keyboard::isKeyPressed(Keyboard::Escape)){
            rm.close();
        }

        // Arrow keys 
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
        if(Keyboard::isKeyPressed(Keyboard::Up)){
            if(bat.getPosition().top<=0) bat.stopUp();
            else bat.moveUp();
        }else{
            bat.stopUp();
        }
        if(Keyboard::isKeyPressed(Keyboard::Down)){
            if(bat.getPosition().top+bat.getPosition().height>=res.y) bat.stopDown();
            else bat.moveDown();
        }else{
            bat.stopDown();
        }


        // Delta time updation
        Time dt = clock.restart();
        bat.update(dt);
        ball.update(dt);

        // HUD text updation
        std::stringstream ss;
        ss<<"Score: "<<score<<" \nLives: "<<lives;
        hud.setString(ss.str());

        // Ball hitting bottom
        if(ball.getPosition().top >= rm.getSize().y){
            ball.update(dt);
            ball.reboundBottom();
            lives--;
            if(lives<=0){
                score = 0;
                lives = 3;
            }
        }
        // Ball hitting top
        if(ball.getPosition().top < 0){
            score++;
            ball.reboundBatOrTop();
        }
        // Ball hitting sides
        if(ball.getPosition().left<0 || ball.getPosition().left+ball.getPosition().width>rm.getSize().x){
            ball.reboundSides();
        }
        // Ball hitting the bat
        if(ball.getPosition().intersects(bat.getPosition())){
            score++;
            ball.reboundBatOrTop();
            ball.update(dt);
            bat.update(dt);
            // ball.speed();
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