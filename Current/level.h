#include <GL/glut.h>
#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")


void InitLevel(int levelValue);
void DrawLevel();
void DrawLevel2D();
void LevelKeyboard(unsigned char Key,int x,int y);
void LevelOnMouseClick(int button,int state,int x,int y);

extern float xPos;
extern float yPos;
extern int endLevel;
extern ILuint *levelIluintArray;
extern GLuint *levelGluintArray;