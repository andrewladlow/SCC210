#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <GL/glut.h>
#include "level.h"
#include "loadTexture.h"
#include "window.h"
#include "Pathing.h"
#include "LevelSelect.h"
#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;



void GenPath(int currentLevel) {

	switch(currentLevel) {
		case 1:
			printf("Pathing 1\n");
			if (xPos < 540) {
				xPos += 2.0f;
				break;
			} else if (yPos < 270) {
				yPos += 2.0f;
				break;
			} else if (xPos >= 540 && xPos < 1100) {
				xPos += 2.0f;
				break;
			} else {
				cout << "Enemy reached exit" << endl;
				endLevel = 1;
				break;
			}
		case 2:
			printf("Pathing 2\n");
			break;
		case 3:
			printf("Pathing 3\n");
			break;
	}
}
