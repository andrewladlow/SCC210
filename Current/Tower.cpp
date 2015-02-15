#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "tower.h"
#include "enemy.h"

Tower::Tower(float x, float y, int type)
{
	this->x = x;  
	this->y = y;
	this->direction = 0;
	//isShooting = false;
	this->hasTarget = false;
	this->type = type;

}

void Tower::DrawTower(){

	if(type == 1){

		towerBase.setPosition(x,y);
		towerBase.setTexture(&basicTowerTexture[0]);
		towerBase.setSize(sf::Vector2f(140, 140));
		window.draw(towerBase);

		if(this->hasTarget == true){
			int triangleLength = pow((currentTarget->xPos-this->x),2);
			//std::cout << triangleLength << "  ";

			int triangleHeight = pow((currentTarget->yPos-this->y),2);
			//std::cout << triangleHeight << "  ";

			int laserLength = sqrt(triangleLength+triangleHeight);
			//std::cout << laserLength << "  ";

			std::cout << direction << " ";
			if (direction > 180 && direction < 270){
				this->direction += 10;
			}
			else if( direction > 90 && direction < 180){
				laserLength -= 20;
			}
			else if( direction < 360 && direction > 270 ){
				laserLength +=70;
			}
			else if( direction > 0 && direction < 90){
				this->direction -= 20;
			}

			laser.setFillColor(sf::Color(255,0,0));
			laser.setSize(sf::Vector2f(laserLength, 5));
			laser.setRotation(direction-90);
			laser.setPosition(x+70,y+70);

			window.draw(laser);

		}

		towerTop.setTexture(&basicTowerTexture[1]);
		towerTop.setSize(sf::Vector2f(140, 140));
		towerTop.setOrigin(70,70);
		towerTop.setRotation(direction);
		towerTop.setPosition(x+70,y+70);
		
		window.draw(towerTop);

	}

}


bool Tower::checkPlacement(){
		if(x>0 && x<640 && y<240 && y>93)
			return false;
		
		if(x>486 && x<643 && y<525 && y>150)
			return false;
		
		if(x>534 && x<1225 && y<525 && y>378)
			return false;
		else{
			towerX=this->x;
			towerY=this->y;
			return true;
		}
}

void Tower::setPos(float newX, float newY){

	this->x = newX-70;
	this->y = newY-70;

}

void Tower::enemyInRange(Enemy* enemyCheck){
	if (enemyCheck->type != 0) { // must not be blank type
		float enemyCheckX = enemyCheck->xPos;
		//std::cout << enemyCheckX << "  ";
		float enemyCheckY = enemyCheck->yPos;
		//std::cout << enemyCheckY << "  ";
		if(hasTarget == false){
			if( enemyCheckX > (this->x-200) && enemyCheckX < (this->x+200)){
				if( enemyCheckY > (this->y-200) && enemyCheckY < (this->y+200)){
					this->hasTarget = true;
					this->currentTarget = enemyCheck;
					workOutAngle(this->x,this->y,enemyCheckX,enemyCheckY);
					enemyCheck->healthPoints -= 1;
				}
			}
		}
	
		if(hasTarget == true){
			if( currentTarget->xPos > (this->x-200) && currentTarget->xPos < (this->x+200)){
				if( currentTarget->yPos > (this->y-200) && currentTarget->yPos < (this->y+200)){

					workOutAngle(this->x,this->y,currentTarget->xPos,currentTarget->yPos);
					currentTarget->healthPoints -= 1;
					if(currentTarget->healthPoints < 1){hasTarget = false;}

				}
				else { 
					this->currentTarget = NULL;
					hasTarget = false;
				}
			}
			else { 
				currentTarget = NULL;
				hasTarget = false;
			}
		}
	}
}

void Tower::workOutAngle(float towerX, float towerY, float targetX, float targetY){

	float deltaX = targetX - towerX;
	float deltaY = targetY - towerY;
	float pi = 3.14159;

	int angleInDegrees = (atan2(deltaY, deltaX)) * 180 / pi;
	angleInDegrees += 90;

	//std::cout << direction << " ";
	if(angleInDegrees < 0) { 
		angleInDegrees += 360; 
	}
	if(angleInDegrees > 360) { 
		angleInDegrees -= 360;
	}
	this->direction = angleInDegrees;
	//std::cout << direction << " ";
}