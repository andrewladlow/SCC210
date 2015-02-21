#include "level.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
	public:
		float xPos;
		float yPos;
		float originalSpeed;
		float speed;
		int healthPoints;
		int startingHealthPoints;
		int type;
		int frame;
		bool isSlowed;
		bool end;
		bool timerStarted;
		bool rotateFlagN;
		bool rotateFlagE;
		bool rotateFlagS;
		bool rotateFlagW;
		sf::RectangleShape enemyRect;
		sf::Clock timer;
		Enemy(float, float, int);

		void draw();
		void setProperties(int);
		void setSpeed(int);
};
#endif
