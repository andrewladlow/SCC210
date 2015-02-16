#include "level.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
	public:
		float xPos;
		float yPos;
		float speed;
		int healthPoints;
		int startingHealthPoints;
		int type;
		int frame;
		bool end;
		bool timerStarted;
		sf::RectangleShape enemyRect;
		sf::Clock timer;
		Enemy(float, float, int);

		void draw();
		void setProperties(int);
};
#endif
