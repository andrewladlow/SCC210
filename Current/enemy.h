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
		bool isFrozen; 
		bool end;
		bool timerStarted;
		bool rotateFlagN;
		bool rotateFlagE;
		bool rotateFlagS;
		bool rotateFlagW;
		sf::RectangleShape enemyRect;
		sf::Clock timer;
		sf::Clock frozenTimer;
		Enemy(float, float, int);

		void draw();
		void setType(int);
		void setSpeed(int);
		void setHealth(int);
};
#endif
