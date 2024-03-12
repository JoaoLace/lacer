#include "game.h"
#include "ball.h"

void game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Testando", sf::Style::Close | sf::Style::Titlebar);
	window->setFramerateLimit(120);
}

void game::initBalls()
{
	ball = new Ball();
}


game::game()
{
	initWindow();
	initBalls();
}

game::~game()
{
	delete window;
}

void game::pollEvents()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		switch (e.Event::type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (e.Event::key.code == sf::Keyboard::Escape)
			{
				window->close();
				break;
			}
		}
	}
}

void game::update()
{
	ball->update();
}

void game::render()
{
	window->clear();

	ball->render(*window);

	window->display();
}

void game::run()
{
	while (window->isOpen())
	{
		pollEvents();
		update();
		render();
	}
}

