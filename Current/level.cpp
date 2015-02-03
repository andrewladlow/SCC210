#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "level.h"
#include "loadTexture.h"
#include "window.h"
#include "pathing.h"
#include "LevelSelect.h"
#include "enemy.h"
#include "bullet.h"
#include "IL/il.h"
#include <Windows.h>
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

// UI stuff
ILuint *levelIluintArray = new ILuint[5];
GLuint *levelGluintArray = new GLuint[5];


int towersPlaced = 0;

// Enemies
ILuint *enemyIluintArray = new ILuint[10];
GLuint *enemyGluintArray = new GLuint[10];

bool waveActive = false;
bool towerActive = false;

bool endLevel = false;

Enemy* testMob1;
Enemy* testMob2;
Bullet* testBullet;

void InitLevel(int levelValue)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	switch(levelValue)
	{
	case 1:
		loadTexture((const wchar_t*)"Images/Levels/Level1.jpg", &levelIluintArray[0], &levelGluintArray[0]); //level 1 map
		break;

	case 2:
		loadTexture((const wchar_t*)"Images/Levels/Level2.png", &levelIluintArray[0], &levelGluintArray[0]); //Level 2 map
		break;
	}
	
	loadTexture((const wchar_t*)"Images/Levels/UI/LevelUI.png", &levelIluintArray[1], &levelGluintArray[1]); // Side menu 

	loadTexture((const wchar_t*)"images/Towers/Basic tower/basicTowerFull.png", &levelIluintArray[2], &levelGluintArray[2]); // Test Tower

	testMob1 = new Enemy(50, 200, 100, 0, 0);
	testMob2 = new Enemy(50, 200, 100, 0, 1);

	glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);

}

void DrawLevel()
{

	// Clear the background
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);

	// for transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Set the orthographic viewing transformation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1680,720,0,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DrawLevel2D();

	// Bring the back buffer to the front and vice-versa
	glutSwapBuffers();

}

void DrawLevel2D()
{
	// draw background
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, levelGluintArray[0]); // choose which one before draw
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(0.0,0.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(0.0,720.0);
		glTexCoord2f(1.0, 1.0); glVertex2f(1280.0,720.0);
		glTexCoord2f(1.0, 0.0); glVertex2f(1280.0,0.0);
	glEnd();

	// draw screen | menu line
	glColor4f(0.0,0.0,0.0,1.0);
	glLineWidth(4.0);
	glBegin(GL_LINES);
		glVertex2f(1280.0f,720.0f);
		glVertex2f(1280.0f,0.0f);
	glEnd();

	// draw UI
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, levelGluintArray[1]); // choose which one before draw
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(1280,0);
		glTexCoord2f(0.0, 1.0); glVertex2f(1280,720);
		glTexCoord2f(1.0, 1.0); glVertex2f(1680,720);
		glTexCoord2f(1.0, 0.0); glVertex2f(1680,0);
	glEnd();

	if (towerActive) {
		glColor4f(1.0,1.0,1.0,1.0);
		glBindTexture(GL_TEXTURE_2D, levelGluintArray[2]);
			glPushMatrix();
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0); glVertex2f(towerX, towerY);
					glTexCoord2f(0.0, 1.0); glVertex2f(towerX, 140.0+towerY);
					glTexCoord2f(1.0, 1.0); glVertex2f(130.0+towerX, 140.0+towerY);
					glTexCoord2f(1.0, 0.0); glVertex2f(130.0+towerX, towerY);
				glEnd();
			glPopMatrix();
	}

		// draw enemy
	if (waveActive) {
		testMob1->draw();
		//std::cout << testMob1->xPos <<std::endl;
		//std::cout << testMob1->yPos <<std::endl;

		if (!endLevel) {
			GenPath(testMob1, currentLevel);
			if (testMob1->xMod > 300) {
				testMob2->draw();
				GenPath(testMob2, currentLevel);
			}

			glutPostRedisplay();
		} else {
			delete testMob1;
			delete testMob2;
			endLevel = false;
			waveActive = false;
			Sleep(3000);
			LevelSelectWindow();
		}
	}
}

// This is called when keyboard presses are detected.
void LevelKeyboard(unsigned char Key,int x,int y){
	if (Key == 27) {
		LevelSelectWindow();
	}
}

// This is called when the mouse is clicked.
void LevelOnMouseClick(int button,int state,int x,int y){
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			if(towerX-x+50<50 && towerX-x+50>-50 && towerY-y+50<50 && towerY-y+50>-50){
				g_lmb = true;
				towerX = x-50;
				towerY = y-50;
			}

			// Start button
			if((x < 1460 && x > 1315) && (y < 165 && y > 100)){
				std::cout << "Clicked start "<<std::endl;
				waveActive = true;
			}
			if((x < 1650 && x > 1505) && (y < 165 && y > 100)){
				LevelSelectWindow();
			}
			if((x < 1410 && x > 1280) && (y < 310 && y > 170)){
				towerActive = true;
			}
		} 
		else { // GLUT_UP
			g_lmb = false;
		}
	}

	glutPostRedisplay();
}

void MouseMotion(int x, int y);
