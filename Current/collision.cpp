#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "level.h"
#include "loadTexture.h"
#include "window.h"
#include "pathing.h"
#include "LevelSelect.h"
#include "enemy.h"
#include "bullet.h"

#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

/*bool collisionCheck(Enemy enemy, Bullet bullet) {
	if (enemy.x < bullet.x + 50 &&
		enemy.x + 50 > bullet.x &&
		enemy.y < bullet.y + 50 &&
		enemy.y + 50 > bullet.y)
		return true;
	return false;
}*/