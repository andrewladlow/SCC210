#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "pathing.h"
#include <vector>
using namespace std;

int temp = 0;

void GenPath(Enemy *e, int currentLevel) {
	switch(currentLevel) {
		case 1:
			if (e->xPos < 590) {
				e->xPos += e->speed;
				break;
			} 
			else if (e->yPos < 470) {
				e->yPos += e->speed;
				break;
			} 
			else if (e->xPos >= 590 && e->xPos < 1100) {
				e->xPos += e->speed;
				break;
			} 
			else {
				//cout << "Enemy reached exit" << endl;
				e->end = true;
				break;
			}
		case 2:
			if (e->yPos < 510 && e->xPos == 150) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 510 && e->xPos < 510) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 510 && e->yPos > 220) {
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos == 220 && e->xPos >= 510 && e->xPos < 860) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 860 && e->yPos >= 220 && e->yPos < 510) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 510 && e->xPos >= 860 && e->xPos < 1100) {
				e->xPos += e->speed;
				break;
			}
			else {
				e->end = true;
				break;
			}
		case 3:
			if (e->xPos < 230) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 230 && e->yPos < 505) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 505 && e->xPos < 1080) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 1080 && e->yPos > 220) {
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos == 220 && e->xPos <= 1080 && e->xPos >= 440) {
				e->xPos -= e->speed;
				break;
			}
			else if (e->yPos < 320) {
				e->yPos += e->speed;
			}
			else {
				e->end = true;
				break;
			}
		case 4:
			if (e->yPos == 220 && e->xPos < 1070) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 1070 && e->yPos < 510) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 510 && e->xPos > 100) {
				e->xPos -= e->speed;
				break;
			}
			else {
				e->end = true;
				break;
			}
		case 6:
			if (e->yPos == 80 && e->xPos > 150) {
				e->xPos -= e->speed;
				break;
			}
			else if (e->xPos == 150 && e->yPos < 365) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 365 && e->xPos < 1075) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 1075 && e->yPos < 580) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 580 && e->xPos > 150) {
				e->xPos -= e->speed;
				break;
			}
			else {
				e->end = true;
				break;
			}
		case 7:
			if (e->yPos == 150 && e->xPos > 150) {
				e->xPos -= e->speed;
				break;
			}
			else if (e->xPos == 150 && e->yPos < 505) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 505 && e->xPos < 1050) {
				e->xPos += e->speed;
				break;
			}
			else {
				e->end = true;
				break;
			}
		case 8:
			if (e->xPos == 80 && e->yPos < 290) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 290 && e->xPos < 370) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 370 && e->yPos < 575) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 575 && e->xPos < 650) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 650 && e->yPos > 80) {
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos == 80 && e->xPos < 930) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 930 && e->yPos < 580) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 580 && e->xPos < 1150) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 1150 && e->yPos > 80) {
				e->yPos -= e->speed;
				break;
			}
			else {
				e->end = true;
				break;
			}
		case 9:
			if (e->xPos == 720 && e->yPos > 505) {
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos == 505 && e->xPos < 1145 && e->xPos >= 720) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 1145 && e->yPos > 75) {
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos == 75 && e->xPos > 80) {
				e->xPos -= e->speed;
				break;
			}
			else if (e->xPos == 80 && e->yPos < 505) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 505 && e->xPos < 505) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 505 && e->yPos < 650) {
				e->yPos += e->speed;
				break;
			}
			else {
				e->end = true;
				break;
			}
		case 10:
			if (e->xPos == 220 && e->yPos < 150) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 150 && e->xPos > 75 && e->xPos < 400) {
				e->xPos -= e->speed;
				break;
			}
			else if (e->xPos == 75 && e->yPos < 290) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 290 && e->xPos < 365) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 365 && e->yPos < 580) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 580 && e->xPos < 650) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 650 && e->yPos > 155) {
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos == 155 && e->xPos < 860) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 860 && e->yPos < 580) {
				e->yPos += e->speed;
				break;
			}
			else if (e->yPos == 580 && e->xPos >= 860 && e->xPos < 1150) {
				e->xPos += e->speed;
				break;
			}
			else if (e->xPos == 1150 && e->yPos > 100) {
				e->yPos -= e->speed;
				break;
			}
			else {
				e->end = true;
				break;
			}
		case 5:
			if (e->yPos == 510 && e->xPos < 1140) {
				e->xPos += e->speed;
				break;
			}
			else if (e->yPos == 360 && e->xPos < 280 && e->type == 0) {
				e->xPos += e->speed;
			}
			else if (e->yPos == 360 && e->xPos < 1000 && e->xPos >= 280 && e->type == 1) {
				e->xPos += e->speed;
			}
			else if (e->xPos == 1000 && e->yPos > 150) {
				e->yPos -= e->speed;
				break;
			}
			else if (e->yPos == 150 && e->xPos > 150) {
				e->xPos -= e->speed;
				break;
			}
			else if (e->xPos == 150 && e->yPos < 510 && e->type == 1) {
				e->yPos += e->speed;
				break;
			}
			else if (e->xPos == 1140 && e-> yPos > 180) {
				e->yPos -= e->speed;
				break;
			}
			else {
				e->end = true;
				break;
			}
	}
}
