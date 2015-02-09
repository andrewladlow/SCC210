#include "enemy.h"

Enemy::Enemy(float xcoor, float ycoor, int healthPoints, int type, int arrayNum)
{
		sf::RectangleShape enemyRect; 
		this->xPos = xPos;
		this->yPos = yPos;
		this->healthPoints = healthPoints;
		this->type = type;
		this->arrayNum = arrayNum;
		spawned = false;
		end = false;
}
//
void Enemy::draw() 
{
	enemyRect.setTexture(&enemyTexture[type]);
	enemyRect.setSize(sf::Vector2f(50, 50));
	enemyRect.setPosition(xPos, yPos);
	window.draw(enemyRect);
}

