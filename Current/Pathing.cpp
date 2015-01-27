#include <stdlib.h>
#include "IL/il.h"
#include <GL/glut.h>
#include <iostream>

void Pathing(int currentLevel) {
	switch(currentLevel) {
		case 1:
			;
			break;
		case 2:
			;
			break;
		case 3:
			;
			break;
	}
}




//
//float g_rectangle_pos_x1 = 0.0f;
//float g_rectangle_pos_y1 = 0.0f;
//int counter1 = 0;
//int counter2 = 0;
//bool flag = false;
//
//if (flag) {
//		glColor4f(1.0,1.0,1.0,1.0);
//		//glBindTexture(GL_TEXTURE_2D, g_image1[0]); // choose which one before draw
//		//glPushMatrix();
//			if (counter2 >= 1000) {
//				g_rectangle_pos_x1 += 0.2f;
//			} else if (counter1 >= 1000) {
//				g_rectangle_pos_y1 += 0.2f;
//				counter2++;
//			} else {
//				g_rectangle_pos_x1 += 0.2f;
//				counter1++;
//			}
//
//		glutPostRedisplay();
//	}
//
//
//if (button == GLUT_LEFT_BUTTON) {
//		if (state == GLUT_DOWN) {
//			// Start button
//			if((x < 1270 && x > 1040) && (y < 710 && y > 520)){
//				std::cout << "Clicked start "<<std::endl;
//				counter1 = 0;
//				counter2 = 0;
//				flag = true;
//			}