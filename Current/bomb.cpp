#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "bomb.h"
#include "enemy.h"

Bomb::Bomb(float x, float y, int type)
{
	this->x = x;  
	this->y = y;
	this->type = type;
	this->timerStarted = false;
}

void Bomb::DrawBomb(){
	if (this->timerStarted) {
		sf::Time elapsed1 = timer.getElapsedTime();
		sf::RectangleShape timerRect; 	
		timerRect.setPosition(sf::Vector2f(x, y - 20));
		float a, b;
		a = (float) elapsed1.asMilliseconds();
		if(type == 0)
			timerRect.setFillColor(sf::Color::Red);
		else 
			timerRect.setFillColor(sf::Color::Blue);
		timerRect.setSize(sf::Vector2f((a / 1500.0f) * 140.0f, 10));

		window.draw(timerRect);
	}


	bombRect.setPosition(x,y);
	bombRect.setTexture(&bombTexture[type]);
	bombRect.setSize(sf::Vector2f(140, 140));
	window.draw(bombRect);
}


void Bomb::enemyInRange(Enemy* enemyCheck){
	
	if(enemyCheck->xPos > 0 && enemyCheck->yPos >0)
	{
		switch(type)
		{
			case 0:
				enemyCheck->healthPoints -= 400;
				if(enemyCheck->healthPoints < 1)
					enemyCheck = NULL;
				break;
			case 1:
				enemyCheck->isFrozen = true;
				enemyCheck->frozenTimer.restart();
				break;
		}
	}
}


void Bomb::setPos(float x, float y)
{
	this->x = x-70;
	this->y = y-70;
}