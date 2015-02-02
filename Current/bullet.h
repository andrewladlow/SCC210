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

class Bullet {
public:
      float* originX;
      float* originY;
	  float* targetX;
	  float* targetY;
	  Bullet(float*, float*, float*, float*);
	  void draw();
};