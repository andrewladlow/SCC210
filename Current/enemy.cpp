#include "enemy.h"
#include "LevelSelect.h"

Enemy::Enemy(float xPos, float yPos, int type)
{
		sf::RectangleShape enemyRect; 
		this->xPos = xPos;
		this->yPos = yPos;
		this->healthPoints = healthPoints + (currentLevel * 15); // enemies become stronger as level increases
		this->startingHealthPoints = healthPoints + (currentLevel * 15);
		this->type = type;
		this->timerStarted = false;
		this->frame = 0;
		this->rotateFlagN = false;
		this->rotateFlagE = false;
		this->rotateFlagS = false;
		this->rotateFlagW = false;
		// set enemy speed and hp based on type
		// 0
		switch (this->type) { 
			case 0: // invisible type
				this->speed = 5.0f + (waveNum * 0.4); // enemies become faster as wave increases
				this->healthPoints = 150;
				this->startingHealthPoints = 150;
				break;
			case 1: // standard type
				this->speed = 4.0f + (waveNum * 0.4);
				this->healthPoints = 150;
				this->startingHealthPoints = 150;
				break;
			case 2: // weak + fast
				this->speed = 5.0f + (waveNum * 0.4);
				this->healthPoints = 100;
				this->startingHealthPoints = 100;
				break;
			case 3: // strong + slow
				this->speed = 3.0f + (waveNum * 0.4);
				this->healthPoints = 250;
				this->startingHealthPoints = 250;
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

// call when an enemy becomes visible to redefine speed and hp
void Enemy::setProperties(int typeVal) {
	switch (typeVal) { 
		case 1:
			this->type = typeVal;
			this->speed = 5.0f;
			this->healthPoints = 150;
			this->startingHealthPoints = 150;
			break;
	}
}
