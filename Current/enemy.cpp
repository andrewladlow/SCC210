#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "loadTexture.h"
#include "level.h"
#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>

#include "enemy.h"

Enemy::Enemy(float xcoor, float ycoor, int hp, int t, int aN)
{
	xPos = xcoor;
	yPos = ycoor;
	healthPoints = hp;
	type = t;
	arrayNum = aN;
	spawned = false;
	end = false;

	switch(type)
	{
		case 0:
			loadTexture((const wchar_t*)"images/megaman.png", &enemyIluintArray[arrayNum], &enemyGluintArray[arrayNum]);
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

void Enemy::draw() 
{


	glColor4f(1.0,1.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, enemyGluintArray[arrayNum]);
		glPushMatrix();
			//glTranslatef(xPos, yPos, 0.0f);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0); glVertex2f(xPos,yPos);
				glTexCoord2f(0.0, 1.0); glVertex2f(xPos,yPos+50.0);
				glTexCoord2f(1.0, 1.0); glVertex2f(xPos+50.0,yPos+50.0);
				glTexCoord2f(1.0, 0.0); glVertex2f(xPos+50.0,yPos);
			glEnd();
		glPopMatrix();
}

