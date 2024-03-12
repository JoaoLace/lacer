#include "ball.h"

void Ball::initVariables()
{
	Ball::xSpeed = 0.f;
	Ball::ySpeed = 5.f;
	Ball::Gravity = 0.098f;

}

const sf::FloatRect Ball::getBounds() const
{
	return ball.getGlobalBounds();
}

void Ball::initShape()
{
	ball.setRadius(6.f);
	ball.setPosition(sf::Vector2f(394.f, 0.f));
	ball.setFillColor(sf::Color::White);
}

Ball::Ball()
{
	initVariables();
	initShape();
}

void Ball::colision()
{
	if (Ball::ySpeed > 0)
	{
		ySpeed += Gravity;
	}

	else if (Ball::ySpeed < 0)
	{
		ySpeed += Gravity * 3;
	}

	if (Ball::getBounds().top == 600 or Ball::getBounds().top > 600)
	{
		Ball::ySpeed = Ball::ySpeed * -1;
	}

	std::cout << "Ball ySpeed-> " << Ball::ySpeed << "\n";
}

void Ball::update()
{
	ball.move(xSpeed, ySpeed);
	Ball::colision();
}
void Ball::render(sf::RenderTarget& target)
{
	target.draw(ball);
}