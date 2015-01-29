#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>

#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>




class Enemy
{
   public:
      float x;
      float y;
	  int healthPoints;
	  float speed;
	  int type;
	  Enemy(float, float, int, int);
	  void draw();
};

Enemy::Enemy(float xcoor, float ycoor, int hp, int t)
{
	x = xcoor;
	y = ycoor;
	healthPoints = hp;
	type = t;
}

void Enemy::draw()
{
	glColor4f(1.0,1.0,1.0,1);
	//we set the texture based on the enemy type
	switch(type)
	{
		case 0:
		//	glBindTexture(GL_TEXTURE_2D, g_image1[0]);
		break;
		case 1:
		//	glBindTexture(GL_TEXTURE_2D, g_image1[1]);
		break;
		default:
		//	glBindTexture(GL_TEXTURE_2D, g_image1[0]);
		break;
	}

	//we then draw the enemy at the given coords
	/*glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex2f(x, y);
			glTexCoord2f(0.0, 1.0); glVertex2f(x, y + 50);
			glTexCoord2f(1.0, 1.0); glVertex2f(x + 50, y + 50);
			glTexCoord2f(1.0, 0.0); glVertex2f(x + 50, y);
		glEnd();
	glPopMatrix();*/
}
