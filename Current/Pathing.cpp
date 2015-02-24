#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "pathing.h"
#include <vector>
using namespace std;


void GenPath(Enemy *e, int currentLevel) {

	if(e->isSlowed)
		e->speed = e->originalSpeed - 2.0;
	else if(!e->isSlowed)
		e->speed = e->originalSpeed;

	if(e->isFrozen)
		e->speed = 0.0;


	switch(currentLevel) {
		case 1:
			if (e->xPos < 590) {
				e->xPos += e->speed;
				break;
			} 
			else if (e->yPos < 470) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
				}
				e->yPos += e->speed;
				break;
			} 
			else if (e->xPos >= 590 && e->xPos < 1100) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
				}
				e->xPos += e->speed;
				break;
			} 
			else {
				//cout << "Enemy reached exit" << endl;
				e->rotateFlagS = false;
				e->rotateFlagE = false;
				e->end = true;
				break;
			}
		case 2:
			if (e->yPos < 510 && e->xPos == 150) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 510 && e->xPos < 510) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 510 && e->xPos < 600 && e->yPos > 220) {
				if (!e->rotateFlagN) {
					e->enemyRect.setOrigin(50,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagN = true;
					e->rotateFlagE = false;
				}
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos <= 220 && e->xPos >= 510 && e->xPos < 860) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->yPos < 510 && e->xPos >= 860) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 510 && e->xPos >= 860 && e->xPos < 1100) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else {
				e->rotateFlagN = false;
				e->rotateFlagE = false;
				e->rotateFlagS = false;
				e->rotateFlagW = false;
				e->end = true;
				break;
			}
		case 3:
			if (e->yPos == 220 && e->xPos < 230) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 230 && e->xPos <= 260 && e->yPos < 505) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 505 && e->xPos < 1080) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 1080 && e->yPos > 220) {
				if (!e->rotateFlagN) {
					e->enemyRect.setOrigin(50,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagN = true;
					e->rotateFlagE = false;
				}
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos <= 220 && e->xPos >= 440) {
				if (!e->rotateFlagW) {
					e->enemyRect.setOrigin(50,50);
					e->enemyRect.rotate(-90);
					e->rotateFlagW = true;
					e->rotateFlagN = false;
				}
				e->xPos -= e->speed;
				break;
			}
			else if (e->yPos <= 320 && e->xPos <= 440) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(-90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else {
				e->rotateFlagN = false;
				e->rotateFlagE = false;
				e->rotateFlagS = false;
				e->rotateFlagW = false;
				e->end = true;
				break;
			}
		case 4:
			if (e->yPos == 220 && e->xPos < 1070) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 1070 && e->yPos < 510) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 510 && e->xPos > 100) {
				if (!e->rotateFlagW) {
					e->enemyRect.setOrigin(50,50);
					e->enemyRect.rotate(90);
					e->rotateFlagW = true;
					e->rotateFlagN = false;
				}
				e->xPos -= e->speed;
				break;
			}
			else {
				e->rotateFlagN = false;
				e->rotateFlagE = false;
				e->rotateFlagS = false;
				e->rotateFlagW = false;
				e->end = true;
				break;
			}
		case 6:
			if (e->yPos == 80 && e->xPos > 150) {
				if (!e->rotateFlagW) {
					e->enemyRect.setOrigin(50,50);
					e->enemyRect.rotate(180);
					e->rotateFlagW = true;
					e->rotateFlagN = false;
				}
				e->xPos -= e->speed;
				break;
			}
			else if (e->xPos <= 150 && e->yPos < 365) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(-90);
					e->rotateFlagS = true;
					e->rotateFlagW = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 365 && e->yPos < 420 && e->xPos < 1075) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 1075 && e->yPos < 580) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 580 && e->xPos > 150) {
				if (!e->rotateFlagW) {
					e->enemyRect.setOrigin(50,50);
					e->enemyRect.rotate(90);
					e->rotateFlagW = true;
					e->rotateFlagS = false;
				}
				e->xPos -= e->speed;
				break;
			}
			else {
				e->rotateFlagN = false;
				e->rotateFlagE = false;
				e->rotateFlagS = false;
				e->rotateFlagW = false;
				e->end = true;
				break;
			}
		case 7:
			if (e->yPos == 150 && e->xPos > 150) {
				if (!e->rotateFlagW) {
					e->enemyRect.setOrigin(50,50);
					e->enemyRect.rotate(180);
					e->rotateFlagW = true;
					e->rotateFlagN = false;
				}
				e->xPos -= e->speed;
				break;
			}
			else if (e->xPos <= 150 && e->yPos < 505) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(-90);
					e->rotateFlagS = true;
					e->rotateFlagW = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 505 && e->xPos < 1050) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else {
				e->rotateFlagN = false;
				e->rotateFlagE = false;
				e->rotateFlagS = false;
				e->rotateFlagW = false;
				e->end = true;
				break;
			}
		case 8:
			if (e->xPos == 80 && e->yPos < 290) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagW = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 290 && e->xPos < 370) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 370 && e->xPos < 400 && e->yPos < 575) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 575 && e->xPos < 650) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 650 && e->xPos < 700 && e->yPos > 80) {
				if (!e->rotateFlagN) {
					e->enemyRect.setOrigin(50,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagN = true;
					e->rotateFlagE = false;
				}
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos >= 80 && e->xPos < 930) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(90);
					e->rotateFlagE = true;
					e->rotateFlagN = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 930 && e->xPos < 960 && e->yPos < 580) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 580 && e->xPos < 1150) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 1150 && e->yPos > 80) {
				if (!e->rotateFlagN) {
					e->enemyRect.setOrigin(50,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagN = true;
					e->rotateFlagE = false;
				}
				e->yPos -= e->speed;
				break;
			}
			else {
				e->rotateFlagN = false;
				e->rotateFlagE = false;
				e->rotateFlagS = false;
				e->rotateFlagW = false;
				e->end = true;
				break;
			}
		case 9:
			if (e->xPos == 720 && e->yPos > 505) {
				if (!e->rotateFlagN) {
					e->enemyRect.setOrigin(50,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagN = true;
					e->rotateFlagE = false;
				}
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos <= 505 && e->yPos > 480 && e->xPos < 1145 && e->xPos >= 720) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(90);
					e->rotateFlagE = true;
					e->rotateFlagN = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 1145 && e->yPos > 75) {
				if (!e->rotateFlagN) {
					e->enemyRect.setOrigin(50,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagN = true;
					e->rotateFlagE = false;
				}
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos <= 75 && e->xPos > 80) {
				if (!e->rotateFlagW) {
					e->enemyRect.setOrigin(50,50);
					e->enemyRect.rotate(-90);
					e->rotateFlagW = true;
					e->rotateFlagN = false;
				}
				e->xPos -= e->speed;
				break;
			}
			else if (e->xPos >= 80 && e->yPos < 505) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(-90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 505 && e->xPos < 505) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 505 && e->yPos < 650) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else {
				e->rotateFlagN = false;
				e->rotateFlagE = false;
				e->rotateFlagS = false;
				e->rotateFlagW = false;
				e->end = true;
				break;
			}
		case 10:
			if (e->xPos == 220 && e->yPos < 150) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 150 && e->yPos < 250 && e->xPos > 75 && e->xPos < 400) {
				if (!e->rotateFlagW) {
					e->enemyRect.setOrigin(50,50);
					e->enemyRect.rotate(90);
					e->rotateFlagW = true;
					e->rotateFlagS = false;
				}
				e->xPos -= e->speed;
				break;
			}
			else if (e->xPos <= 75 && e->yPos < 290) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(-90);
					e->rotateFlagS = true;
					e->rotateFlagW = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 290 && e->xPos < 365) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 365 && e->xPos < 400 && e->yPos < 580) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 580 && e->xPos < 650) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 650 && e->xPos < 700 && e->yPos > 155) {
				if (!e->rotateFlagN) {
					e->enemyRect.setOrigin(50,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagN = true;
					e->rotateFlagE = false;
				}
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos <= 155 && e->xPos < 860) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(90);
					e->rotateFlagE = true;
					e->rotateFlagN = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 860 && e->xPos < 900 && e->yPos < 580) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(90);
					e->rotateFlagS = true;
					e->rotateFlagE = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos >= 580 && e->xPos >= 860 && e->xPos < 1150) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos >= 1150 && e->yPos > 100) {
				if (!e->rotateFlagN) {
					e->enemyRect.setOrigin(50,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagN = true;
					e->rotateFlagE = false;
				}
				e->yPos -= e->speed;
				break;
			}
			else {
				e->rotateFlagN = false;
				e->rotateFlagE = false;
				e->rotateFlagS = false;
				e->rotateFlagW = false;
				e->end = true;
				break;
			}
		case 5:
			if (e->yPos >= 510 && e->xPos < 1140) {
				if (!e->rotateFlagE) {
					e->enemyRect.setOrigin(0,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagE = true;
					e->rotateFlagS = false;
				}
				e->xPos += e->speed;
				break;
			}
			else if (e->yPos >= 360 && e->xPos < 280 && e->type == 0) {
				e->xPos += e->speed;
			}
			else if (e->yPos >= 360 && e->xPos < 1000 && e->xPos >= 280 && e->type >= 1) {
				e->xPos += e->speed;
			}
			else if (e->xPos >= 1000 && e->yPos > 150) {
				if (!e->rotateFlagN) {
					e->enemyRect.setOrigin(50,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagN = true;
					e->rotateFlagE = false;
				}
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos <= 150 && e->xPos > 150 && e->xPos < 1050) {
				if (!e->rotateFlagW) {
					e->enemyRect.setOrigin(50,50);
					e->enemyRect.rotate(-90);
					e->rotateFlagW = true;
					e->rotateFlagN = false;
				}
				e->xPos -= e->speed;
				break;
			}
			else if (e->xPos <= 150 && e->yPos < 510 && e->type >= 1 && e->xPos < 1050) {
				if (!e->rotateFlagS) {
					e->enemyRect.setOrigin(0,50);
					e->enemyRect.rotate(-90);
					e->rotateFlagS = true;
					e->rotateFlagW = false;
				}
				e->yPos += e->speed;
				break;
			}
			else if (e->xPos >= 1140 && e-> yPos >= 180) {
				if (!e->rotateFlagN) {
					e->enemyRect.setOrigin(50,0);
					e->enemyRect.rotate(-90);
					e->rotateFlagN = true;
					e->rotateFlagE = false;
				}
				e->yPos -= e->speed;
				break;
			}
			else {
				e->rotateFlagN = false;
				e->rotateFlagE = false;
				e->rotateFlagS = false;
				e->rotateFlagW = false;
				e->end = true;
				break;
			}
	}
}
