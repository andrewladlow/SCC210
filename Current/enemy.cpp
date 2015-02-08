#include "enemy.h"

Enemy::Enemy(float xcoor, float ycoor, int hp, int t, int aN)
{
		sf::RectangleShape enemyRect; 
		xPos = xcoor;
		yPos = ycoor;
		healthPoints = hp;
		type = t;
		arrayNum = aN;
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

