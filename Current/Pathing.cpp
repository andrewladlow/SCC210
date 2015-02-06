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



void GenPath(Enemy *e, int currentLevel) {

	switch(currentLevel) {
		case 1:
			printf("Pathing 1\n");

			if (e->xPos < 590) {
				e->xPos += 3.0f;
				break;
			} 
			else if (e->yPos < 470) {
				e->yPos += 3.0f;
				break;
			} 
			else if (e->xPos >= 590 && e->xPos < 1100) {
				e->xPos += 3.0f;
				break;
			} 
			else {
				cout << "Enemy reached exit" << endl;
				endLevel = true;
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
