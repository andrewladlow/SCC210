#include <iostream>
//#include <stdlib.h>
//#include <stdio.h>
#include "menu.h"
#include "level.h"

#include <GL/glut.h>

#include "IL/il.h"
#pragma comment(lib,"DevIL.lib")

#include <vector>
using namespace std;

// global variables -------------------

float g_rectangle_pos_x1 = 0.0f;
float g_rectangle_pos_y1 = 0.0f;
int counter1 = 0;
int counter2 = 0;
bool flag = false;

// is left mouse button (lmb) pressed or not
bool g_lmb1 = false;
float g_lmb1_pos_x = 0.0f;
float g_lmb1_pos_y = 0.0f;

// these are for textures
ILuint *g_img_name1;
GLuint *g_image1;



// This function is called to initialise opengl
void Init1()
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LEQUAL);

//	glEnable(GL_LIGHT0);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// first image from file ----------------
	g_img_name1 = new ILuint[4];
	ilGenImages(4, &g_img_name1[0]);
	ilBindImage(g_img_name1[0]);
	// this is forcing the variable to become (const wchar_t *), which is just a hack for now?
	if (!ilLoadImage((const wchar_t *) "images/example_sprite_00.png")) {
		std::cout << "image file not loaded" << std::endl;
		exit(1);
	}
	ILuint img_width = ilGetInteger(IL_IMAGE_WIDTH);
	ILuint img_height = ilGetInteger(IL_IMAGE_HEIGHT);
	ILenum img_format = ilGetInteger(IL_IMAGE_FORMAT);
	ILenum img_type = ilGetInteger(IL_IMAGE_TYPE);
	ILubyte *img_data = ilGetData();
	//
	g_image1 = new GLuint[4];
	glGenTextures(3, &g_image1[0]);
	glBindTexture(GL_TEXTURE_2D, g_image1[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img_width,
		img_height, 0, img_format, img_type,
		img_data);
	// ilDeleteImages(1, &g_img_name1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
        GL_NEAREST);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// 2nd one just for test purposes ------------------------
	ilBindImage(g_img_name1[1]);
	// this is forcing the variable to become (const wchar_t *), which is just a hack for now?
	if (!ilLoadImage((const wchar_t *) "images/example_sprite_01.png")) {
		std::cout << "image file not loaded" << std::endl;
		exit(1);
	}
	ILuint img1_width = ilGetInteger(IL_IMAGE_WIDTH);
	ILuint img1_height = ilGetInteger(IL_IMAGE_HEIGHT);
	ILenum img1_format = ilGetInteger(IL_IMAGE_FORMAT);
	ILenum img1_type = ilGetInteger(IL_IMAGE_TYPE);
	ILubyte *img1_data = ilGetData();
	//
	glBindTexture(GL_TEXTURE_2D, g_image1[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img1_width,
		img1_height, 0, img1_format, img1_type,
		img1_data);
	// ilDeleteImages(1, &g_img_name1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
        GL_NEAREST);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);


	ilBindImage(g_img_name1[2]);
	// this is forcing the variable to become (const wchar_t *), which is just a hack for now?
	if (!ilLoadImage((const wchar_t *) "images/background.jpg")) {
		std::cout << "image file not loaded" << std::endl;
		exit(1);
	}
	ILuint img2_width = ilGetInteger(IL_IMAGE_WIDTH);
	ILuint img2_height = ilGetInteger(IL_IMAGE_HEIGHT);
	ILenum img2_format = ilGetInteger(IL_IMAGE_FORMAT);
	ILenum img2_type = ilGetInteger(IL_IMAGE_TYPE);
	ILubyte *img2_data = ilGetData();
	//
	glBindTexture(GL_TEXTURE_2D, g_image1[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img2_width,
		img2_height, 0, img2_format, img2_type,
		img2_data);
	// ilDeleteImages(1, &g_img_name1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
        GL_NEAREST);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	ilBindImage(g_img_name1[3]);
	// this is forcing the variable to become (const wchar_t *), which is just a hack for now?
	if (!ilLoadImage((const wchar_t *) "images/StartButton.png")) {
		std::cout << "image file not loaded" << std::endl;
		exit(1);
	}
	ILuint img3_width = ilGetInteger(IL_IMAGE_WIDTH);
	ILuint img3_height = ilGetInteger(IL_IMAGE_HEIGHT);
	ILenum img3_format = ilGetInteger(IL_IMAGE_FORMAT);
	ILenum img3_type = ilGetInteger(IL_IMAGE_TYPE);
	ILubyte *img3_data = ilGetData();
	//
	glBindTexture(GL_TEXTURE_2D, g_image1[3]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img3_width,
		img3_height, 0, img3_format, img3_type,
		img3_data);
	// ilDeleteImages(1, &g_img_name1);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
        GL_NEAREST);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT);
}

void Draw2D1()
{
	glColor4f(0.5,0.5,0.5,1.0);
	glPointSize(8);
	glBegin(GL_POINTS);
		glVertex2f(g_lmb1_pos_x,240.0f);
	glEnd();

	glColor4f(0.2,0.8,0.2,1.0);
	glPointSize(32);
	glBegin(GL_POINTS);
		glVertex2f(480.0f,240.0f);
	glEnd();

	glColor4f(0.0,0.0,0.0,1.0);
	glLineWidth(2.0);
	glPushMatrix();
		//glTranslatef(g_rectangle_pos_x, g_rectangle_pos_y, 0.0f);
		// there's also glRotatef() if needed
		glBegin(GL_LINE_LOOP);
			glVertex2f(300.0f, 200.0f);
			glVertex2f(400.0f, 200.0f);
			glVertex2f(400.0f, 150.0f);
			glVertex2f(300.0f, 150.0f);
		glEnd();
	glPopMatrix();

	glColor4f(0.0,0.0,0.0,1.0);
	glLineWidth(4.0);
	glBegin(GL_LINES);
		//glVertex2f(200.0f,640.0f);
		glVertex2f(1280.0f-250.0f,720.0f);
		//glVertex2f(200.0f,0.0f);
		glVertex2f(1280.0f-250.0f,0.0f);
	glEnd();

	glColor4f(1.0,0.0,0.0,0.9);
	glBegin(GL_TRIANGLES);
		glVertex2f(300.0f,300.0f);
		glVertex2f(400.0f,300.0f);
		glVertex2f(400.0f,350.0f);
	glEnd();

	// draw texture
	glColor4f(1.0,1.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, g_image1[0]); // choose which one before draw
	glPushMatrix();
		glTranslatef(g_rectangle_pos_x1, g_rectangle_pos_y1, 0.0f);
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex2f(0.0,300.0);
			glTexCoord2f(0.0, 1.0); glVertex2f(0.0,350.0);
			glTexCoord2f(1.0, 1.0); glVertex2f(50.0,350.0);
			glTexCoord2f(1.0, 0.0); glVertex2f(50.0,300.0);
		glEnd();
	glPopMatrix();

	// draw texture
	glColor4f(1.0,1.0,1.0,1.0);
	glBindTexture(GL_TEXTURE_2D, g_image1[1]); // choose which one before draw
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex2f(850.0,550.0);
			glTexCoord2f(0.0, 1.0); glVertex2f(850.0,600.0);
			glTexCoord2f(1.0, 1.0); glVertex2f(900.0,600.0);
			glTexCoord2f(1.0, 0.0); glVertex2f(900.0,550.0);
			//glTexCoord2f(0.0, 0.0); glVertex2f(100.0, 0.0);
			//glTexCoord2f(0.0, 1.0); glVertex2f(100.0, 440.0);
			//glTexCoord2f(1.0, 1.0); glVertex2f(760.0, 540.0);
			//glTexCoord2f(1.0, 0.0); glVertex2f(890.0,560.0);
		glEnd();
	glPopMatrix();

	glColor4f(1.0,1.0,1.0,0.5);
	glBindTexture(GL_TEXTURE_2D, g_image1[2]);
	glPushMatrix();
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex2f(0.0,0.0);
			glTexCoord2f(0.0, 1.0); glVertex2f(0.0,720.0);
			glTexCoord2f(1.0, 1.0); glVertex2f(1030.0,720.0);
			glTexCoord2f(1.0, 0.0); glVertex2f(1030.0,0.0);
		glEnd();
	glPopMatrix();

	//glColor4f(1.0,1.0,1.0,1.0);
	//glBegin(GL_TRIANGLES);
	//	glTexCoord2f(0.0, 0.0); glVertex2f(100.0f,400.0f);
	//	glTexCoord2f(1.0, 0.0); glVertex2f(500.0f,400.0f);
	//	glTexCoord2f(1.0, 1.0); glVertex2f(500.0f,550.0f);
	//	//glTexCoord2f(1.0, 0.0);
	//glEnd();

		// draw texture
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, g_image1[3]); // choose which one before draw
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(1040.0,520.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(1040.0,710.0);
		glTexCoord2f(1.0, 1.0); glVertex2f(1270.0,710.0);
		glTexCoord2f(1.0, 0.0); glVertex2f(1270.0,520.0);
	glEnd();

	if (flag) {
		glColor4f(1.0,1.0,1.0,1.0);
		glBindTexture(GL_TEXTURE_2D, g_image1[0]); // choose which one before draw
		glPushMatrix();
			if (counter2 >= 1000) {
				g_rectangle_pos_x1 += 0.2f;
			} else if (counter1 >= 1000) {
				g_rectangle_pos_y1 += 0.2f;
				counter2++;
			} else {
				g_rectangle_pos_x1 += 0.2f;
				counter1++;
			}
			glTranslatef(g_rectangle_pos_x1, g_rectangle_pos_y1, 0.0f);
			//glBegin(GL_QUADS);
			//	glTexCoord2f(0.0, 0.0); glVertex2f(0.0,300.0);
			//	glTexCoord2f(0.0, 1.0); glVertex2f(0.0,350.0);
			//	glTexCoord2f(1.0, 1.0); glVertex2f(50.0,350.0);
			//	glTexCoord2f(1.0, 0.0); glVertex2f(50.0,300.0);
			//glEnd();
		glPopMatrix();

		glutPostRedisplay();
	}

}



// This is the main display callback function.
// It sets up an orthographic projection and calls Draw2D().
void Draw1()
{
	// Clear the background
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

//    glShadeModel(GL_SMOOTH);

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);

	glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_FLAT); // not really needed?

	// for transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Set the orthographic viewing transformation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1280,720,0,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	Draw2D1();

	// Bring the back buffer to the front and vice-versa
	glutSwapBuffers();


}

// 	This function is called when the window is resized.
void Resize(int w, int h)
{
	// Allow drawing in full region of the screen
	glViewport(0,0,w,h);

	glutReshapeWindow(1280, 720);
}

// This is called when the mouse is clicked.
void OnMouseClick1(int button,int state,int x,int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			// Start button
			if((x < 1270 && x > 1040) && (y < 710 && y > 520)){
				std::cout << "Clicked start "<<std::endl;
				counter1 = 0;
				counter2 = 0;
				flag = true;
			}

			g_lmb1 = true;
			g_lmb1_pos_x = x;
			g_lmb1_pos_y = y;
		} else { // GLUT_UP
			g_lmb1 = false;
		}
	}

	glutPostRedisplay();
}


// This is called when the mouse is moved.
void MouseMotion1(int x, int y)
{
	if (g_lmb1) {
		g_lmb1_pos_x = x;
		g_lmb1_pos_y = y;
	}

	glutPostRedisplay();
}

// This is called when keyboard presses are detected.
void Keyboard1(unsigned char Key,int x,int y)
{
	if (Key == 'a') {
		g_rectangle_pos_x1 -= 2.0f;
	}
	if (Key == 'd') {
		g_rectangle_pos_x1 += 2.0f;
	}
	if (Key == 'w') {
		g_rectangle_pos_y1 -= 2.0f;
	}
	if (Key == 's') {
		g_rectangle_pos_y1 += 2.0f;
	}

	if (Key == 'p') {
		std::cout << "print something on the screen..." << std::endl;
	}

	glutPostRedisplay();
}


//const char* Instructions = " a - move left\n d - move right\n";

int main1(int argc,char **argv)
{
	//printf(Instructions);
	printf("Entered level\n");
	//glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(200,100);

	//glutCreateWindow("2D_example_screen");
	glutDisplayFunc(Draw1);
	glutReshapeFunc(Resize);
	glutMouseFunc(OnMouseClick1);
	glutMotionFunc(MouseMotion1);
	glutKeyboardFunc(Keyboard1);

	ilInit();
	Init1();

	glutMainLoop();
	return 0;
}
