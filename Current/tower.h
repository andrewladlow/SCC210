#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "level.h"
#include "enemy.h"
#ifndef TOWER_H
#define TOWER_H

class Tower {
   public:
      float x;
      float y;
	  float direction;
	  bool isShooting;
	  bool hasTarget;
	  Enemy* currentTarget;
	  int type;

	  Tower(float, float, int);
	  void DrawTower();
	  bool checkPlacement();
	  void setPos(float newX, float newY);
	  void enemyInRange(Enemy* enemyCheck);
	  void workOutAngle(float towerX, float towerY, float targetX, float targetY);

	  sf::RectangleShape towerBase;
	  sf::RectangleShape towerTop;
	  sf::RectangleShape laser;
};

#endif