#include <iostream>
#include "menu.h"
#include "level.h"
#include "LevelSelect.h"

#include <GL/glut.h>

#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

int g_lmb_pos_x = 0;
int g_lmb_pos_y = 0;
bool g_lmb = 0;

// 	This function is called when the window is resized.
void Resize(int w, int h){
	glutReshapeWindow(1280, 720);
}

void ResizeLevel(int w, int h){
	glutReshapeWindow(1680, 720);
}

// This is called when the mouse is moved.
void MouseMotion(int x, int y)
{
	g_lmb_pos_x = x;
	g_lmb_pos_y = y;
}

void initialiseWindow(int argc,char **argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Space Tower Defence");

	glutDisplayFunc(DrawMenu);
	glutReshapeFunc(Resize);
	glutMouseFunc(MenuOnMouseClick);
	glutPassiveMotionFunc(MouseMotion);
	glutKeyboardFunc(MenuKeyboard);

	ilInit();
	InitMenu();

	glutMainLoop();

}

void MenuWindow(){

	glutDisplayFunc(DrawMenu);
	glutMouseFunc(MenuOnMouseClick);
	glutKeyboardFunc(MenuKeyboard);

	InitMenu();

	glutPostRedisplay();

}

void LevelWindow(int levelSelected){
	glutReshapeWindow(1680, 720);
	glViewport(0, 0, (GLsizei)1680, (GLsizei)720);
	glutDisplayFunc(DrawLevel);
	glutMouseFunc(LevelOnMouseClick);
	glutKeyboardFunc(LevelKeyboard);

	InitLevel(levelSelected);

	glutPostRedisplay();
}

void LevelSelectWindow(){
	glutReshapeWindow(1280, 720);
	glViewport(0, 0, (GLsizei)1280, (GLsizei)720);
	glutDisplayFunc(DrawLevelSelect);
	glutMouseFunc(LevelSelectOnMouseClick);
	glutKeyboardFunc(LevelSelectKeyboard);

	InitLevelSelect();

	glutPostRedisplay();
}




