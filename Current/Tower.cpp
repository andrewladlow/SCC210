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

			//std::cout << direction << " ";
			/*if (direction > 180 && direction < 270){
				this->direction += 10;
			}*/
			 if( direction > 90 && direction < 180){
				laserLength -= 40;
			}
			else if( direction < 360 && direction > 270 ){
				laserLength +=70;
			}
			/*else if( direction > 0 && direction < 90){
				this->direction -= 20;
			}*/

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

	else if(type == 2){

		towerBase.setPosition(x,y);
		towerBase.setTexture(&longRangeTowerTexture[0]);
		towerBase.setSize(sf::Vector2f(140, 140));
		window.draw(towerBase);

		if(this->hasTarget == true){
			int triangleLength = pow((currentTarget->xPos-this->x),2);
			//std::cout << triangleLength << "  ";

			int triangleHeight = pow((currentTarget->yPos-this->y),2);
			//std::cout << triangleHeight << "  ";

			int laserLength = sqrt(triangleLength+triangleHeight);
			//std::cout << laserLength << "  ";

			//std::cout << direction << " ";
			if (direction > 180 && direction < 270){
				//this->direction -= 10;
			}
			else if( direction > 90 && direction < 180){
				//laserLength -= 20;
			}
			else if( direction < 360 && direction > 270 ){
				//laserLength +=70;
			}
			else if( direction > 0 && direction < 90){
				//this->direction -= 20;
			}

			laser.setFillColor(sf::Color(0,255,0));
			laser.setSize(sf::Vector2f(laserLength, 5));
			laser.setRotation(direction-90);
			laser.setPosition(x+70,y+70);

			window.draw(laser);

		}

		towerTop.setTexture(&longRangeTowerTexture[1]);
		towerTop.setSize(sf::Vector2f(140, 140));
		towerTop.setOrigin(70,70);
		towerTop.setRotation(direction);
		towerTop.setPosition(x+70,y+70);
		
		window.draw(towerTop);

	}

}


bool Tower::checkPlacement(int currentLevel){
switch(currentLevel)
		{
		case 1:
			if(x>1160)
				return false;

			if(x<640 && y<240 && y>93)
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
	
		case 2:
			if(x>1160)
				return false;

			if(x>35 && x<200 && y<550)
				return false;
		
			if(x>25 && x<554 && y<553 && y>390)
				return false;
		
			if(x>380 && x<565 && y<553 && y>100)
				return false;

			if(x>380 && x<900 && y<270 && y>100)
				return false;

			if(x>730 && x<910 && y<550 && y>100)
				return false;

			if(x>730 && x<1280 && y<560 && y>380)
				return false;
			else{
				towerX=this->x;
				towerY=this->y;
				return true;
			}
		
		case 3:
			if(x>1160)
				return false;

			if(x<280 && y<270 && y>100)
				return false;
			
			if(x>100 && x<280 && y<550 && y>100)
				return false;
		
			if(x>100 && x<1130 && y<550 && y>380)
				return false;
	
			if(x>840 && x<880 && y<550 && y>200)
				return false;

			if(x>950 && x<1130 && y<530 && y>100)
				return false;

			if(x>300 && x<1130 && y<270 && y>100)
				return false;

			if(x>300 && x<490 && y<422 && y>100)
				return false;
			else{
				towerX=this->x;
				towerY=this->y;
				return true;
			}

		case 4:
			if(x>1160)
				return false;

			if(x<1125 && y<270 && y>100)
				return false;
		
			if(x>950 && x<1125 && y<550 && y>100)
				return false;
		
			 if(x<1125 && y<553 && y>380)
				return false;
			else{
				towerX=this->x;
				towerY=this->y;
				return true;
			}

		case 5:
			if(x>1160)
				return false;

			if(x>170&&x<1050 && y<410 && y>240)
				return false;
			
			if(x>870 && x<1050 && y<410 && y>30)
				return false;
		
			if(x>30 && x<1130 && y<197 && y>30)
				return false;
	
			if(x>30 && x<203 && y<550 && y>30)
				return false;

			if(x>30 && x<1200 && y<550 && y>390)
				return false;

			if(x>1020 && x<1200 && y<550 && y>20)
				return false;

			else{
				towerX=this->x;
				towerY=this->y;
				return true;
			}

		case 6:
			if(x>1160)
				return false;

			if(x>25 && y<130)
				return false;
			
			if(x>25 && x<203 && y<412)
				return false;
		
			if(x>25 && x<1125 && y<412 && y>250)
				return false;
	
			if(x>950 && x<1125 && y<622 && y>250)
				return false;

			if(x<1125 && y<622 && y>460)
				return false;

			else{
				towerX=this->x;
				towerY=this->y;
				return true;
			}

		case 7:
			if(x>1160)
				return false;

			if(x>25 && y<200 && y>30)
				return false;
		
			if(x>25 && x<200 && y<555 && y>30)
				return false;
		
			 if(x>25 && y<555 && y>390)
				return false;
			else{
				towerX=this->x;
				towerY=this->y;
				return true;
			}
		case 8:
			if(x>1160)
				return false;

			if(x<130 && y<340)
				return false;
			
			if(x<415 && y<340 && y>180)
				return false;
		
			if(x>240 && x<415 && y<625 && y>180)
				return false;
	
			if(x>240 && x<700 && y<625 && y>464)
				return false;

			if(x>520 && x<700 && y<625)
				return false;

			if(x>520 && x<980 && y<127)
				return false;

			if(x>807 && x<980 && y<625)
				return false;

			if(x>807 && x<1197 && y<625 && y>460)
				return false;

			if(x>1020 && x<1197 && y<625)
				return false;
			else{
				towerX=this->x;
				towerY=this->y;
				return true;
			}

		case 9:
			if(x>1160)
				return false;

			if(x>590 && x<770 && y>390)
				return false;
			
			if(x>590 && y<553 && y>390)
				return false;
		
			if(x>1020 && y<553)
				return false;
	
			if(y<126)
				return false;

			if(x>130 && y<553)
				return false;

			if(x<558 && y<553 && y>390)
				return false;

			if(x>350 && x<555 && y>390)
				return false;
			else{
				towerX=this->x;
				towerY=this->y;
				return true;
			}

		case 10:
			if(x>1160)
				return false;

			if(x<275 && x>95 && y<200)
				return false;
			
			if(x<275 && y<200 && y>35)
				return false;
		
			if(x<131 && y<340 && y>35)
				return false;
	
			if(x<415 && y<340 && y>177)
				return false;

			if(x>237 && x<417 && y<625 && y>177)
				return false;

			if(x>237 && x<700 && y<625 && y>460)
				return false;

			if(x>520 && x<700 && y<625 && y>35)
				return false;

			if(x>520 && x<915 && y<200 && y>35)
				return false;

			if(x>736 && x<915 && y<625 && y>35)
				return false;

			if(x>736 && y<625 && y>460)
				return false;

			if(x>1020 && y<625)
				return false;
			else{
				towerX=this->x;
				towerY=this->y;
				return true;
			}
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

		int towerRange =0;
		if(this->type == 1){ towerRange = 200;}
		else if(this->type == 2){ towerRange = 1000;}

		if(hasTarget == false && enemyCheckX>0 && enemyCheckY>0){

			if( enemyCheckX > (this->x-towerRange) && enemyCheckX < (this->x+towerRange)){
				if( enemyCheckY > (this->y-towerRange) && enemyCheckY < (this->y+towerRange)){
					this->hasTarget = true;
					this->currentTarget = enemyCheck;
					workOutAngle(this->x,this->y,enemyCheckX,enemyCheckY);
					enemyCheck->healthPoints -= 1;
				}
			}
		}
	
		if(hasTarget == true && enemyCheckX>0 && enemyCheckY>0){
			if( currentTarget->xPos > (this->x-towerRange) && currentTarget->xPos < (this->x+towerRange)){
				if( currentTarget->yPos > (this->y-towerRange) && currentTarget->yPos < (this->y+towerRange)){
					
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

	float deltaX = (targetX-50) - towerX;
	float deltaY = (targetY-50) - towerY;
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