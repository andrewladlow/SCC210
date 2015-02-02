#include <iostream>
#include "menu.h"
#include "level.h"
#include "LevelSelect.h"

#include <GL/glut.h>

#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

float g_lmb_pos_x = 0;
float g_lmb_pos_y = 0;
int desc;
bool g_lmb;
float square_pos_x = 500.0f;
float square_pos_y = 500.0f;



// 	This function is called when the window is resized.
void Resize(int w, int h){
	glutReshapeWindow(1280, 720);
}

void ResizeLevel(int w, int h){
	glutReshapeWindow(1680, 720);
}

// This is called when the mouse is moved.
//void MouseMotion(int x, int y)
//{
//	g_lmb_pos_x = x;
//	g_lmb_pos_y = y;
//}

void MouseMotion(int x, int y)
{
	if (g_lmb) {
		g_lmb_pos_x = x-50;
		g_lmb_pos_y = y-50;
		square_pos_x=g_lmb_pos_x;
		square_pos_y=g_lmb_pos_y;

	}

	glutPostRedisplay();
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
	glutMotionFunc(MouseMotion);
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





