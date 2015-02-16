#include <SFML/Graphics.hpp>
#include "window.h"
void InitLevel(int levelValue);
void DrawLevel2D();
void LevelKeyboard(int Key);
void MouseMotion(int x, int y);
void LevelOnMouseClick(int button,int type,int x,int y);
int Random(int min, int max);

extern bool endLevel;