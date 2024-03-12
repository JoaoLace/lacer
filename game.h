#include "Ball.h"
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
class game
{
private:
	sf::RenderWindow* window;
	Ball* ball;



	void initWindow();
	void initBalls();



public:
	game();
	virtual ~game();


	void update();
	void render();
	void pollEvents();
	void run();
};

