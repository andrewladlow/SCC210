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
#include "tower.h"
#include "IL/il.h"
#include <Windows.h>
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

// UI stuff
ILuint *levelIluintArray = new ILuint[5];
GLuint *levelGluintArray = new GLuint[5];

// Enemies
ILuint *enemyIluintArray = new ILuint[10];
GLuint *enemyGluintArray = new GLuint[10];

float towerX = 1280.0f;
float towerY = 170.0f;

bool waveActive = false;
bool towerActive = false;
bool endLevel = false;
bool clicked = false;
bool towerPlaced = false;

int towersPlaced = 0;
int frame=0, time, timebase=0;
int healthAmount = 100;
int currencyAmount = 1000;

char fpsBuffer[256];
char healthBuffer[256];
char currencyBuffer[256];

Enemy* testMobArray[10];
Tower* testTower;
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

	for (int i=0; i<10; i++) {
		testMobArray[i] = new Enemy(50-(i*200), 200, 100, 0, i);
	}
	testTower = new Tower(0, 0, 1);

	glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);
}

void DrawLevel()
{

	// Clear the background
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	//glEnable(GL_TEXTURE_2D);
 //   glShadeModel(GL_FLAT);

	//// for transparency
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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

	// draw tower
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

	// draw enemies
	if (waveActive) {
		for (int i=0; i<10; i++) {
			testMobArray[i]->draw();
		}
		if (!endLevel) { // keep enemies moving until one hits end
			for (int i=0; i<10; i++) {
				GenPath(testMobArray[i], currentLevel);
			} 
			glutPostRedisplay();
		} 
		else {
			for (int i=0; i<10; i++) {
				delete testMobArray[i];
			}

			endLevel = false;
			waveActive = false;

			Sleep(2000);
			LevelSelectWindow();
		}
	}

	// draw fps
	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) {
		sprintf_s(fpsBuffer,"FPS:%4.2f",
			frame*1000.0/(time-timebase));
		timebase = time;
		frame = 0;
	}

	glColor3f(0.0f,0.0f,0.0f);
	glPushMatrix();
		glLoadIdentity();
		renderBitmapString(30,35,GLUT_BITMAP_TIMES_ROMAN_24,fpsBuffer);
	glPopMatrix();

	// draw health
	glColor3f(0.0f,0.0f,0.0f);
	sprintf_s(healthBuffer,"%d",healthAmount);
	renderBitmapString(1450,32.5,GLUT_BITMAP_TIMES_ROMAN_24,healthBuffer);

	// draw currency
	glColor3f(0.0f,0.0f,0.0f);
	sprintf_s(currencyBuffer,"%d",currencyAmount);
	renderBitmapString(1450,70,GLUT_BITMAP_TIMES_ROMAN_24,currencyBuffer);
}

// This is called when keyboard presses are detected.
void LevelKeyboard(unsigned char Key,int x,int y){
	if (Key == 27) {
		LevelSelectWindow();
		endLevel = false;
		waveActive = false;
	}
}

// This is called when the mouse is clicked.
void LevelOnMouseClick(int button,int state,int x,int y){
	if (button == GLUT_LEFT_BUTTON && !clicked) {
		// tower 1 button
		if((x < 1410 && x > 1280) && (y < 310 && y > 170)){
			clicked = true;
			towerActive = true;
		}
		if(towerX-x+50<50 && towerX-x+50>-50 && towerY-y+50<50 && towerY-y+50>-50 && !towerPlaced){
			towerX = x-50;
			towerY = y-50;
		}

		// Start button
		if((x < 1460 && x > 1315) && (y < 165 && y > 100)){
			std::cout << "Clicked start "<<std::endl;
			waveActive = true;
		}
		// quit button
		if((x < 1650 && x > 1505) && (y < 165 && y > 100)){
			endLevel = false;
			waveActive = false;
			LevelSelectWindow();
		}
	}
	if (button == GLUT_RIGHT_BUTTON && clicked) {
		towersPlaced++;
		clicked = false;
		towerPlaced = true;
	}
	glutPostRedisplay();
}

void LevelMouseMotion(int x, int y) {
	glutPostRedisplay();
}

void LevelPassiveMouseMotion(int x, int y) {
	if (clicked && !towerPlaced) {
		towerX = x-50;
		towerY = y-50;
	}
	glutPostRedisplay();
}

// forces screen redraw
void LevelIdle() {
	glutPostRedisplay();
}