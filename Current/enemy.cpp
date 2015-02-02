#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "loadTexture.h"
#include "level.h"
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
	  void draw(int arrayNum);
	  void save(int arrayNum);
};

Enemy::Enemy(float xcoor, float ycoor, int hp, int t)
{
	x = xcoor;
	y = ycoor;
	healthPoints = hp;
	type = t;
}

void Enemy::save(int arrayNum)
{
	glColor4f(1.0,1.0,1.0,1);
	//we set the texture based on the enemy type
	switch(type)
	{
		case 0:
			loadTexture((const wchar_t*)"images/megaman.png", &levelIluintArray[arrayNum], &levelGluintArray[arrayNum]);

			//	glBindTexture(GL_TEXTURE_2D, g_image1[0]);
		break;
		case 1:
		//	glBindTexture(GL_TEXTURE_2D, g_image1[1]);
		break;
		default:
		//	glBindTexture(GL_TEXTURE_2D, g_image1[0]);
		break;
	}
}

void Enemy::draw(int arrayNum) 
{

	glColor4f(1.0,1.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, levelGluintArray[arrayNum]);
		glPushMatrix();
			//glTranslatef(xPos, yPos, 0.0f);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex2f(x+xPos,y+yPos);
				glTexCoord2f(0.0, 1.0); glVertex2f(x+xPos,y+yPos+50);
				glTexCoord2f(1.0, 1.0); glVertex2f(x+xPos+50,y+yPos+50);
				glTexCoord2f(1.0, 0.0); glVertex2f(x+xPos+50,y+yPos);
			glEnd();
		glPopMatrix();
}


