#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "levelSelect.h"
#include "loadTexture.h"
#include "window.h"


#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

// these are for textures
ILuint *levelSelectIluintArray = new ILuint[3];
GLuint *levelSelectGluintArray = new GLuint[3];

ILuint *levelsIluintArray = new ILuint[3];
GLuint *levelsGluintArray = new GLuint[3];
int currentLevel = 1;

void InitLevelSelect()
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	// Background Image
	const wchar_t* levelSelectImageFile = (const wchar_t*)"Images/LevelSelect/background.jpg";
	loadTexture(levelSelectImageFile, &levelSelectIluintArray[0], &levelSelectGluintArray[0]);

	// Arrow Image
	levelSelectImageFile = (const wchar_t*)"Images/LevelSelect/arrow.png";
	loadTexture(levelSelectImageFile, &levelSelectIluintArray[1], &levelSelectGluintArray[1]);

	// Exit Image
	levelSelectImageFile = (const wchar_t*)"Images/Shared/exitbut.png";
	loadTexture(levelSelectImageFile, &levelSelectIluintArray[2], &levelSelectGluintArray[2]);

	// Level 0 Image
	levelSelectImageFile = (const wchar_t*)"Images/LevelSelect/Level0.png";
	loadTexture(levelSelectImageFile, &levelsIluintArray[0], &levelsGluintArray[0]);

	// Level 1 Image
	levelSelectImageFile = (const wchar_t*)"Images/LevelSelect/Level1.jpg";
	loadTexture(levelSelectImageFile, &levelsIluintArray[1], &levelsGluintArray[1]);

	// Level 2 Image
	levelSelectImageFile = (const wchar_t*)"Images/LevelSelect/Level2.png";
	loadTexture(levelSelectImageFile, &levelsIluintArray[2], &levelsGluintArray[2]);


	glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);

}

void DrawLevelSelect()
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
	glOrtho(0,1280,720,0,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	DrawLevelSelect2D();

	// Bring the back buffer to the front and vice-versa
	glutSwapBuffers();

}

void DrawLevelSelect2D()
{
	// draw background
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, levelSelectGluintArray[0]);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(0.0,0.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(0.0,720.0);
		glTexCoord2f(1.0, 1.0); glVertex2f(1280.0,720.0);
		glTexCoord2f(1.0, 0.0); glVertex2f(1280.0,0.0);
	glEnd();

	// Exit button
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, levelSelectGluintArray[2]);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(1060,600);
		glTexCoord2f(0.0, 1.0); glVertex2f(1060,700);
		glTexCoord2f(1.0, 1.0); glVertex2f(1260,700);
		glTexCoord2f(1.0, 0.0); glVertex2f(1260,600);
	glEnd();

	// Main level selected
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, levelsGluintArray[currentLevel]);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(410,280);
		glTexCoord2f(0.0, 1.0); glVertex2f(410,520);
		glTexCoord2f(1.0, 1.0); glVertex2f(837,520);
		glTexCoord2f(1.0, 0.0); glVertex2f(837,280);

	glEnd();

	// Previous level 
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, levelsGluintArray[currentLevel-1]);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(120,355);
		glTexCoord2f(0.0, 1.0); glVertex2f(120,450);
		glTexCoord2f(1.0, 1.0); glVertex2f(280,450);
		glTexCoord2f(1.0, 0.0); glVertex2f(280,355);

	glEnd();

	// Next level 
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, levelsGluintArray[currentLevel+1]);
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(957,355);
		glTexCoord2f(0.0, 1.0); glVertex2f(957,450);
		glTexCoord2f(1.0, 1.0); glVertex2f(1117,450);
		glTexCoord2f(1.0, 0.0); glVertex2f(1117,355);

	glEnd();

	// Left arrow
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, levelSelectGluintArray[1]);
	glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0, 0.0); glVertex2f(400,300);
		glTexCoord2f(0.0, 1.0); glVertex2f(400,500);
		glTexCoord2f(1.0, 0.0); glVertex2f(300,400);
	glEnd();

	// Right arrow
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, levelSelectGluintArray[1]);
	glBegin(GL_TRIANGLES);
		glTexCoord2f(0.0, 0.0); glVertex2f(847,300);
		glTexCoord2f(0.0, 1.0); glVertex2f(847,500);
		glTexCoord2f(1.0, 0.0); glVertex2f(947,400);
	glEnd();

}

// This is called when keyboard presses are detected.
void LevelSelectKeyboard(unsigned char Key,int x,int y){
	if (Key == 27) {
		MenuWindow();
	}
}

// This is called when the mouse is clicked.
void LevelSelectOnMouseClick(int button,int state,int x,int y){

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {

		// Exit button
		if((x < 1260 && x > 1060) && (y < 700 && y > 600)){
			MenuWindow();
		}

		// Play Level
		if((x < 837 && x > 410) && (y < 520 && y > 280)){
			LevelWindow(currentLevel);
		}

		// Right arrow
		if((x < 947 && x > 847) && (y < 500 && y > 300)){
			if(currentLevel < 2){currentLevel++;}
		}

		// Left arrow
		if((x < 400 && x > 300) && (y < 500 && y > 300)){
			if(currentLevel > 1){currentLevel--;}
		}

	}
	glutPostRedisplay();
}