#include "enemy.h"
#include "LevelSelect.h"

Enemy::Enemy(float xPos, float yPos, int type)
{
		sf::RectangleShape enemyRect; 
		this->xPos = xPos;
		this->yPos = yPos;
		this->healthPoints = 100;
		this->startingHealthPoints = 100;
		this->type = type;
		switch(this->type) {
			case 0: // invisible type
				this->originalSpeed = 10.0f;
				break;
			case 1: // standard type
				this->originalSpeed = 5.0f;
				break;
			case 2: // fast type
				this->originalSpeed = 6.0f;
				break;
			case 3: // slow type
				this->originalSpeed = 4.0f;
				break;
		}
		this->speed = 0;
		this->timerStarted = false;
		this->frame = 0;
		this->isSlowed = false;
		this->isFrozen = false;
		this->rotateFlagN = false;
		this->rotateFlagE = false;
		this->rotateFlagS = false;
		this->rotateFlagW = false;
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

	enemyRect.setTexture(&enemyTexture[this->type][this->frame], true);
	enemyRect.setSize(sf::Vector2f(50, 50));
	enemyRect.setPosition(xPos, yPos);
	window.draw(enemyRect);

	if(isFrozen)
	{
		sf::RectangleShape ice; 	
		ice.setPosition(sf::Vector2f(xPos, yPos));
		ice.setSize(sf::Vector2f(50, 50));
		ice.setTexture(&iceTexture);
		window.draw(ice);

		sf::Time elapsedFrozen = frozenTimer.getElapsedTime();
		if(elapsedFrozen.asSeconds() > 2)
			isFrozen = false;
	}

	if (this->timerStarted) {
		sf::Time elapsed1 = timer.getElapsedTime();
		if (elapsed1.asMilliseconds() > 150) { //change enemy texture every 150ms
			timer.restart();
			frame++;
			if (frame == 3) {
				frame = 0;
			}
		}
	}
}

// call to set an enemy's type
void Enemy::setType(int typeVal) {
	this->type = typeVal;
}

// call to set an enemy's speed value
void Enemy::setSpeed(int typeVal) {
	switch(typeVal) {
		case 0:
			this->originalSpeed = 10.0f + (waveNum * 0.1); // enemies become faster as wave increases
			break;
		case 1:
			this->originalSpeed = 5.0f + (waveNum * 0.1);
			break;
		case 2:
			this->originalSpeed = 6.0f + (waveNum * 0.1);
			break;
		case 3:
			this->originalSpeed = 4.0f + (waveNum * 0.1);
			break;
	}
}

// call to set an enemy's health
void Enemy::setHealth(int typeVal) {
	switch(typeVal) {
		case 0:
			break;
		case 1:
			this->healthPoints = 350 + (currentLevel * 35) + (waveNum * 10.0); // enemies become stronger as level and wave increases
			this->startingHealthPoints = 350 + (currentLevel * 35) + (waveNum * 10.0);
			break;
		case 2:
			this->healthPoints = 300 + (currentLevel * 35) + (waveNum * 10.0);
			this->startingHealthPoints = 300 + (currentLevel * 35) + (waveNum * 10.0);
			break;
		case 3:
			this->healthPoints = 450 + (currentLevel * 35) + (waveNum * 10.0);
			this->startingHealthPoints = 450 + (currentLevel * 35) + (waveNum * 10.0);
			break;
	}
}