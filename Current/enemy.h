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
		bool end;
		sf::RectangleShape enemyRect;
		Enemy(float, float, int);

		void draw();
		void setProperties(int);
};
#endif
