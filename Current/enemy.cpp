#include "enemy.h"

Enemy::Enemy(float xPos, float yPos, int type)
{
		sf::RectangleShape enemyRect; 
		this->xPos = xPos;
		this->yPos = yPos;
		this->healthPoints = healthPoints;
		this->startingHealthPoints = healthPoints;
		this->type = type;
		// set enemy speed and hp based on type
		// 0
		switch (this->type) { 
			case 0:
				this->speed = 5.0f;
				this->healthPoints = 150;
				this->startingHealthPoints = 150;
			case 1:
				this->speed = 5.0f;
				this->healthPoints = 150;
				this->startingHealthPoints = 150;
		}
		this->end = false;
}
//
void Enemy::draw() 
{
	if (this->type != 0) {
		sf::RectangleShape healthRect; 	
		healthRect.setPosition(sf::Vector2f(xPos, yPos - 20));
		float x, y;
		x = (float) healthPoints;
		y = (float) startingHealthPoints;
		healthRect.setSize(sf::Vector2f((x / y) * 50.0f, 10));
		healthRect.setFillColor(sf::Color::Green);
		window.draw(healthRect);
	}

		enemyRect.setTexture(&enemyTexture[this->type], true);
		enemyRect.setSize(sf::Vector2f(50, 50));
		enemyRect.setPosition(xPos, yPos);
		window.draw(enemyRect);
}

// call when an enemy becomes visible to redefine speed and hp
void Enemy::setProperties(int typeVal) {
	switch (typeVal) { 
		case 1:
			this->type = typeVal;
			this->speed = 5.0f;
			this->healthPoints = 150;
			this->startingHealthPoints = 150;
	}
}
