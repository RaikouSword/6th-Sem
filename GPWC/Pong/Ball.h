#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball{
private:
	Vector2f ball_pos;	
	CircleShape ball_shape;

	float ball_speed = 1000.0f;
	float ball_dirX = .2f;
	float ball_dirY = .2f;

public:
	Ball(float startX, float startY);

	FloatRect getPosition();

	CircleShape getShape();

	float getXVelocity();

	void reboundSides();

	void reboundBatOrTop();

	void reboundBottom();

	void update(Time dt);

};