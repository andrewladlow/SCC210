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
		this->rotateFlagN = false;
		this->rotateFlagE = false;
		this->rotateFlagS = false;
		this->rotateFlagW = false;
		// set enemy originalSpeed and hp based on type
		switch (this->type) { 
			case 0: // invisible type
				this->originalSpeed = 10.0f;
				this->healthPoints = 150 + (currentLevel * 30); // enemies become stronger as level increases
				this->startingHealthPoints = 150 + (currentLevel * 30);
				break;
			case 1: // standard type
				this->originalSpeed = 4.0f;
				this->healthPoints = 150 + (currentLevel * 30);
				this->startingHealthPoints = 150 + (currentLevel * 30);
				break;
			case 2: // weak + fast
				this->originalSpeed = 5.0f;
				this->healthPoints = 100 + (currentLevel * 30);
				this->startingHealthPoints = 100 + (currentLevel * 30);
				break;
			case 3: // strong + slow
				this->originalSpeed = 3.0f;
				this->healthPoints = 250 + (currentLevel * 30);
				this->startingHealthPoints = 250 + (currentLevel * 30);
				break;
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

		enemyRect.setTexture(&enemyTexture[this->type][this->frame], true);
		enemyRect.setSize(sf::Vector2f(50, 50));
		enemyRect.setPosition(xPos, yPos);
		window.draw(enemyRect);

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

// call when an enemy becomes visible to redefine originalSpeed and hp
void Enemy::setProperties(int typeVal) {
	switch (typeVal) { 
		case 1: // standard type
			this->type = typeVal;
			this->originalSpeed = 4.0f;
			this->healthPoints = 150 + (currentLevel * 30);
			this->startingHealthPoints = 150 + (currentLevel * 30);
			break;
		case 2: // weak + fast
			this->type = typeVal;
			this->originalSpeed = 5.0f;
			this->healthPoints = 100 + (currentLevel * 30);
			this->startingHealthPoints = 100 + (currentLevel * 30);
			break;
		case 3: // strong + slow
			this->type = typeVal;
			this->originalSpeed = 3.0f;
			this->healthPoints = 250 + (currentLevel * 30);
			this->startingHealthPoints = 250 + (currentLevel * 30);
			break;
	}
}

// call to set an enemy's speed value
void Enemy::setSpeed(int typeVal) {
	switch(typeVal) {
		case 1:
			this->originalSpeed = 4.0f + (waveNum * 1.5); // enemies become faster as wave increases
			break;
		case 2:
			this->originalSpeed = 5.0f +(waveNum * 1.5);
			break;
		case 3:
			this->originalSpeed = 3.0f +(waveNum * 1.5);
			break;
	}
}
