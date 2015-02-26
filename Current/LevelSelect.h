#include "window.h"
using namespace std;
void InitLevelSelect();
void DrawLevelSelect2D();
void LevelSelectKeyboard(int Key);
void LevelSelectOnMouseClick(int button,int x,int y);
extern int currentLevel;
extern string highScores[10][10][2];