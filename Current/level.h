#include <GL/glut.h>
#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

void InitLevel(int levelValue);
void DrawLevel();
void DrawLevel2D();
void LevelKeyboard(unsigned char Key,int x,int y);
void LevelOnMouseClick(int button,int state,int x,int y);
void LevelMouseMotion(int x, int y);
void LevelPassiveMouseMotion(int x, int y);
void LevelIdle();

extern bool endLevel;

extern ILuint *levelIluintArray;
extern GLuint *levelGluintArray;

extern ILuint *enemyIluintArray;
extern GLuint *enemyGluintArray;