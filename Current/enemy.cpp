#include "enemy.h"
#include "LevelSelect.h"

Enemy::Enemy(float xPos, float yPos, int type)
{
		sf::RectangleShape enemyRect; 
		this->xPos = xPos;
		this->yPos = yPos;
		this->healthPoints;
		this->startingHealthPoints;
		this->type = type;
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

// call when an enemy becomes visible to redefine type
void Enemy::setProperties(int typeVal) {
	this->type = typeVal;
}

// call to set an enemy's speed value
void Enemy::setSpeed(int typeVal) {
	switch(typeVal) {
		case 1:
			this->originalSpeed = 5.0f + (waveNum * 0.75); // enemies become faster as wave increases
			break;
		case 2:
			this->originalSpeed = 6.0f + (waveNum * 0.75);
			break;
		case 3:
			this->originalSpeed = 4.0f + (waveNum * 0.75);
			break;
	}
}

void Enemy::setHealth(int typeVal) {
	switch(typeVal) {
		case 1:
			this->healthPoints = 275 + (currentLevel * 35) + (waveNum * 5.0); // enemies become stronger as level and wave increases
			this->startingHealthPoints = 275 + (currentLevel * 35) + (waveNum * 5.0);
		case 2:
			this->healthPoints = 225 + (currentLevel * 35) + (waveNum * 5.0);
			this->startingHealthPoints = 225 + (currentLevel * 35) + (waveNum * 5.0);
		case 3:
			this->healthPoints = 375 + (currentLevel * 35) + (waveNum * 5.0);
			this->startingHealthPoints = 375 + (currentLevel * 35) + (waveNum * 5.0);
	}
}