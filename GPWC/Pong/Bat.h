#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat{
    private:
        Vector2f bat_pos;
        RectangleShape bat_shape;

        float bat_speed=1000.0f;
        bool bat_movingRight = false;
        bool bat_movingLeft = false;
    
    public:
        Bat(float startX, float startY);

        FloatRect getPosition();

        RectangleShape getShape();

        void moveLeft();

        void moveRight();

        void stopLeft();

        void stopRight();

        void update(Time dt);
};