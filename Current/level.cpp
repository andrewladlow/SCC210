#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "level.h"
#include "loadTexture.h"
#include "window.h"


#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

// these are for textures
ILuint *levelIluintArray = new ILuint[1];
GLuint *levelGluintArray = new GLuint[1];

void InitLevel(int levelValue)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	const wchar_t* levelImageFile;
	switch(levelValue)
	{
	case 1:
		levelImageFile = (const wchar_t*)"Images/Levels/Level1.png";
		break;

	case 2:
		levelImageFile = (const wchar_t*)"Images/Levels/Level2.png";
		break;
	}
	loadTexture(levelImageFile, &levelIluintArray[0], &levelGluintArray[0]);

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
	glOrtho(0,1280,720,0,-1,1);
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

}

// This is called when keyboard presses are detected.
void LevelKeyboard(unsigned char Key,int x,int y){
	if (Key == 27) {
		LevelSelectWindow();
	}
}

// This is called when the mouse is clicked.
void LevelOnMouseClick(int button,int state,int x,int y){

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {

		//std::cout << "Clicked that mouse button "<<std::endl;

	}
	glutPostRedisplay();
}