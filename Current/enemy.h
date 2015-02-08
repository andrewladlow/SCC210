#include "level.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
   public:
	  float xStart;
	  float yStart;
      float xPos;
	  float xMod;
      float yPos;
	  float yMod;
	  int healthPoints;
	  float speed;
	  int type;
	  int arrayNum;
	  bool spawned;
	  sf::RectangleShape enemyRect;
	  Enemy(float, float, int, int, int);
	  void draw();
};
#endif
