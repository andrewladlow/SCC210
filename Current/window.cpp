#include <iostream>
#include "menu.h"
#include "level.h"
#include "LevelSelect.h"

#include <GL/glut.h>

#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

bool g_lmb;
float towerX = 1280.0f;
float towerY = 170.0f;



// 	This function is called when the window is resized.
void Resize(int w, int h) {
	glutReshapeWindow(1280, 720);
}

void ResizeLevel(int w, int h) {
	glutReshapeWindow(1680, 720);
}

void MouseMotion(int x, int y)
{
	if (g_lmb) {
		towerX = x-50;
		towerY = y-50;
	}

	glutPostRedisplay();
}



void initialiseWindow(int argc,char **argv) {

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Space Tower Defence");

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
	glutKeyboardFunc(LevelKeyboard);

	InitLevel(levelSelected);

	glutPostRedisplay();
}

void LevelSelectWindow() {
	glutReshapeWindow(1280, 720);
	glViewport(0, 0, (GLsizei)1280, (GLsizei)720);
	glutDisplayFunc(DrawLevelSelect);
	glutMouseFunc(LevelSelectOnMouseClick);
	glutKeyboardFunc(LevelSelectKeyboard);

	InitLevelSelect();

	glutPostRedisplay();
}





