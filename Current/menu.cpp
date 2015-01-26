#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "menu.h"
#include "window.h"
#include "loadTexture.h"
#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

// these are for textures
ILuint *menuIluintArray = new ILuint[3];
GLuint *menuGluintArray = new GLuint[3];


// This function is called to initialise opengl
void InitMenu()
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
//  glDepthFunc(GL_LEQUAL);

//	glEnable(GL_LIGHT0);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	
	const wchar_t* menuImageFile = (const wchar_t*)"Images/Menu/menu.jpg";
	loadTexture(menuImageFile, &menuIluintArray[0], &menuGluintArray[0]);

	menuImageFile = (const wchar_t*)"Images/Shared/playbut.png";
	loadTexture(menuImageFile, &menuIluintArray[1], &menuGluintArray[1]);

	menuImageFile = (const wchar_t*)"Images/Shared/exitbut.png";
	loadTexture(menuImageFile, &menuIluintArray[2], &menuGluintArray[2]);

	glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);

}

void DrawMenu()
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

	DrawMenu2D();

	// Bring the back buffer to the front and vice-versa
	glutSwapBuffers();

}

void DrawMenu2D()
{
	// draw background
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, menuGluintArray[0]); // choose which one before draw
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(0.0,0.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(0.0,720.0);
		glTexCoord2f(1.0, 1.0); glVertex2f(1280.0,720.0);
		glTexCoord2f(1.0, 0.0); glVertex2f(1280.0,0.0);
	glEnd();

	// draw play button
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, menuGluintArray[1]); // choose which one before draw
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(340.0,350.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(340.0,450.0);
		glTexCoord2f(1.0, 1.0); glVertex2f(540.0,450.0);
		glTexCoord2f(1.0, 0.0); glVertex2f(540.0,350.0);
	glEnd();

	// draw exit button
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, menuGluintArray[2]); // choose which one before draw
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(740.0,350.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(740.0,450.0);
		glTexCoord2f(1.0, 1.0); glVertex2f(940.0,450.0);
		glTexCoord2f(1.0, 0.0); glVertex2f(940.0,350.0);
	glEnd();
}


// This is called when keyboard presses are detected.
void MenuKeyboard(unsigned char Key,int x,int y){}

// This is called when the mouse is clicked.
void MenuOnMouseClick(int button,int state,int x,int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
			// Play button
			if((x < 540 && x > 340) && (y < 450 && y > 350)){
				//std::cout << "Clicked that Play button "<<std::endl;
				LevelSelectWindow();
			}

			// Exit button
			if((x < 940 && x > 740) && (y < 450 && y > 350)){
				exit(0);
			} 
	}
	glutPostRedisplay();
}