#include "level.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
   public:
      float xPos;
      float yPos;
	  int healthPoints;
	  int startingHealthPoints;
	  float speed;
	  int type;
	  int arrayNum;
	  bool spawned;
	  bool end;
	  sf::RectangleShape enemyRect;
	  Enemy(float, float, int, int, int);

	  void draw();
};
#endif
