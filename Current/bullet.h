#include "level.h"

class Bullet {
public:
	float xPos;
	float yPos;
      float* originX;
      float* originY;
	  float* targetX;
	  float* targetY;
	  Bullet(float*, float*, float*, float*);
	  void draw();
};