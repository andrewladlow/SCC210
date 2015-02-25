#include "window.h"
using namespace std;
void InitLevelSelect();
void DrawLevelSelect2D();
void LevelSelectKeyboard(int Key);
void LevelSelectOnMouseClick(int button,int x,int y);
extern int currentLevel;
extern string highScores[10][10][2];
extern bool t1l1;
extern bool t2l1;
extern bool t3l1;
extern bool t1l2;
extern bool t2l2;
extern bool t3l2;