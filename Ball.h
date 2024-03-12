#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
class Ball
{
private:
	sf::CircleShape ball;

	float xSpeed, ySpeed;
	 float Gravity;
	void initShape();
	void initVariables();

public:
	Ball();
	const sf::FloatRect getBounds() const;
	void colision();
	void update();
	void moves();
	void render(sf::RenderTarget& target);
};

