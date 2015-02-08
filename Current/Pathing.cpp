#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "pathing.h"
#include <vector>
using namespace std;

void GenPath(Enemy *e, int currentLevel) {

	switch(currentLevel) {
		case 1:
			printf("Pathing 1\n");

			if (e->xPos < 590) {
				e->xPos += 10.0f;
				break;
			} 
			else if (e->yPos < 470) {
				e->yPos += 10.0f;
				break;
			} 
			else if (e->xPos >= 590 && e->xPos < 1100) {
				e->xPos += 10.0f;
				break;
			} 
			else {
				cout << "Enemy reached exit" << endl;
				e->end = true;
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
