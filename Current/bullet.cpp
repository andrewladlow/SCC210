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
      float x;
      float y;
	  int healthPoints;
	  float speed;
	  int type;
	  Bullet(float, float, int);
	  void draw();
};

Bullet::Bullet(float xcoor, float ycoor, int t)
{
	x = xcoor;
	y = ycoor;
	type = t;
}

void Bullet::draw()
{
	glColor4f(1.0,0,0,1.0);

	////we then draw the bullet at the given coords
	//glPushMatrix();
	//	glBegin(GL_QUADS);
	//		glVertex2f(x, y);
	//		glVertex2f(x, y + 50);
	//		glVertex2f(x + 50, y + 50);
	//		glVertex2f(x + 50, y);
	//	glEnd();
	//glPopMatrix();
}
