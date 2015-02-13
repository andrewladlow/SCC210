#include "enemy.h"

Enemy::Enemy(float xPos, float yPos, int healthPoints, int type, int arrayNum)
{
		sf::RectangleShape enemyRect; 
		this->xPos = xPos;
		this->yPos = yPos;
		this->healthPoints = healthPoints;
		this->startingHealthPoints = healthPoints;
		this->type = type;
		this->arrayNum = arrayNum;
		spawned = false;
		end = false;
}
//
void Enemy::draw() 
{
		sf::RectangleShape healthRect; 	
		healthRect.setPosition(sf::Vector2f(xPos, yPos - 20));
		float x, y;
		x = (float) healthPoints;
		y = (float) startingHealthPoints;
		healthRect.setSize(sf::Vector2f((x / y) * 50.0f, 10));
		healthRect.setFillColor(sf::Color::Green);
		window.draw(healthRect);

		enemyRect.setTexture(&enemyTexture[this->type], true);
		enemyRect.setSize(sf::Vector2f(50, 50));
		enemyRect.setPosition(xPos, yPos);
		window.draw(enemyRect);
}
