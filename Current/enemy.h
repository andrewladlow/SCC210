#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "level.h"
#include "loadTexture.h"
#include "window.h"
#include "pathing.h"
#include "LevelSelect.h"
#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

class Enemy {

public:
	float x;
	float y;
	int healthPoints;
	float speed;
	int type;

	Enemy(float xcoor, float ycoor, int hp, int t);
	void save(int arrayNum);
	void draw(int arrayNum);
};