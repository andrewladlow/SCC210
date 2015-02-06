#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "menu.h"
#include "level.h"
#include "LevelSelect.h"
#include "wglext.h"
#include <GL/glut.h>
#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

// 	This function is called when the window is resized.
void Resize(int w, int h) {
	glutReshapeWindow(1280, 720);
}

void ResizeLevel(int w, int h) {
	glutReshapeWindow(1680, 720);
}

void MouseMotion(int x, int y)
{
	glutPostRedisplay();
}

void initialiseWindow(int argc,char **argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Space Tower Defence");

	PFNWGLSWAPINTERVALEXTPROC       wglSwapIntervalEXT = NULL;
	PFNWGLGETSWAPINTERVALEXTPROC    wglGetSwapIntervalEXT = NULL;

	// init pointers
	wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)wglGetProcAddress("wglSwapIntervalEXT");
	wglSwapIntervalEXT (1);

	glutDisplayFunc(DrawMenu);
	glutReshapeFunc(Resize);
	glutMouseFunc(MenuOnMouseClick);
	glutMotionFunc(MouseMotion);

	glutKeyboardFunc(MenuKeyboard);

	ilInit();
	InitMenu();

	glutMainLoop();

}

void MenuWindow() {

	glutDisplayFunc(DrawMenu);
	glutMouseFunc(MenuOnMouseClick);
	glutKeyboardFunc(MenuKeyboard);

	InitMenu();

	glutPostRedisplay();

}

void LevelWindow(int levelSelected) {
	glutReshapeWindow(1680, 720);
	glViewport(0, 0, (GLsizei)1680, (GLsizei)720);
	glutDisplayFunc(DrawLevel);
	glutMouseFunc(LevelOnMouseClick);
	glutMotionFunc(LevelMouseMotion);
	glutPassiveMotionFunc(LevelPassiveMouseMotion);
	glutKeyboardFunc(LevelKeyboard);
	glutIdleFunc(LevelIdle);

	InitLevel(levelSelected);

	glutPostRedisplay();
}

void LevelSelectWindow() {
	glutReshapeWindow(1280, 720);
	glViewport(0, 0, (GLsizei)1280, (GLsizei)720);
	glutDisplayFunc(DrawLevelSelect);
	glutMouseFunc(LevelSelectOnMouseClick);
	glutKeyboardFunc(LevelSelectKeyboard);
	glutMotionFunc(LevelMouseMotion);

	InitLevelSelect();

	glutPostRedisplay();
}

// displays string on screen
void renderBitmapString(float x, float y, void *font, string str) {
  glRasterPos2f(x,y);
  for (string::iterator c = (&str)->begin(); c != (&str)->end(); ++c) {
    glutBitmapCharacter(font, *c);
  }
}