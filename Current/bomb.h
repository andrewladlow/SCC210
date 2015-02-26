#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "level.h"
#include "enemy.h"
#ifndef BOMB_H
#define BOMB_H

class Bomb {
   public:
      float x;
      float y;
	  int type;
	  sf::Sound sound;
	  Bomb(float, float, int);
	  void DrawBomb();
	  void setPos(float newX, float newY);
	  void enemyInRange(Enemy* enemyCheck);
	  sf::Clock timer;
	  sf::RectangleShape bombRect;
	  bool timerStarted;
};

#endif