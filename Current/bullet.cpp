#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

class Bullet
{
   public:
      float* originX;
      float* originY;
	  float* targetX;
	  float* targetY;
	  Bullet(float*, float*, float*, float*);
	  void draw();
};

Bullet::Bullet(float* theOriginX, float* theOriginY, float* theTargetX, float* theTargetY)
{
	originX = theOriginX;
	originY = theOriginY;
	targetX = theTargetX;
	targetY = theTargetY;

}

void Bullet::draw()
{
	glColor4f(1.0,0,0,1.0);

	//we then draw the bullet at the given coords
	glPushMatrix();
		glBegin(GL_LINES);
			glVertex2f(*originX, *originY);
			glVertex2f(*targetX, *targetY);
		glEnd();
	glPopMatrix();
}
