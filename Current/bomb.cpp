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
	bombRect.setPosition(x,y);
	bombRect.setTexture(&bombTexture[0]);
	bombRect.setSize(sf::Vector2f(140, 140));
	window.draw(bombRect);
}


void Bomb::enemyInRange(Enemy* enemyCheck){
	float enemyCheckX = enemyCheck->xPos;
	//std::cout << enemyCheckX << "  ";
	float enemyCheckY = enemyCheck->yPos;
	//std::cout << enemyCheckY << "  ";

	int bombRange = 200;
	
	if(enemyCheckX>0 && enemyCheckY>0){
		if( enemyCheck->xPos > (this->x-bombRange) && enemyCheck->xPos < (this->x+bombRange)){
			if( enemyCheck->yPos > (this->y-bombRange) && enemyCheck->yPos < (this->y+bombRange)){
				enemyCheck->healthPoints -= 100;
				if(enemyCheck->healthPoints < 1){enemyCheck = NULL;}

			}
		}
	}
}


void Bomb::setPos(float x, float y)
{
	this->x = x-70;
	this->y = y-70;
}