#include "enemy.h"

Enemy::Enemy(float xcoor, float ycoor, int hp, int t, int aN)
{
		sf::RectangleShape enemyRect; 
		xStart = xcoor;
		yStart = ycoor;
		xPos = 0.0f;
		yPos = 0.0f;
		xMod = 0.0f;
		yMod = 0.0f;
		healthPoints = hp;
		type = t;
		arrayNum = aN;
		spawned = false;
}
//
void Enemy::draw() 
{
	spawned = true;
	xPos = xStart + xMod;
	yPos = yStart + yMod;
	enemyRect.setTexture(&enemyTexture[type]);
	enemyRect.setSize(sf::Vector2f(50, 50));
	enemyRect.setPosition(xPos, yPos);
	window.draw(enemyRect);
}

