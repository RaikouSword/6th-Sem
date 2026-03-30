#include "Ball.h"

Ball::Ball(float startX,float startY){
    ball_pos.x = startX;
    ball_pos.y = startY;

    ball_shape.setRadius(10.0);
    ball_shape.setPosition(ball_pos);
}

FloatRect Ball::getPosition(){
    return ball_shape.getGlobalBounds();
}

CircleShape Ball::getShape(){
    return ball_shape;
}

float Ball::getXVelocity(){
    return ball_dirX;
}

void Ball::reboundSides(){
    ball_dirX = - ball_dirX;
}

void Ball::reboundBatOrTop(){
    ball_dirY = -ball_dirY;
}

void Ball::speed(){
    ball_speed+=1.10*ball_speed;
}

void Ball::reboundBottom(){
    ball_pos.y = 0;
    ball_pos.x = 650;
}

void Ball::update(Time dt){
    //Update the ball position vars
    ball_pos.y += ball_dirY * ball_speed * dt.asSeconds();
    ball_pos.x += ball_dirX * ball_speed * dt.asSeconds();

    //Move the ball and the bat
    ball_shape.setPosition(ball_pos);
}