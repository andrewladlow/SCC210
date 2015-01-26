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

// for moving rectangle
float g_rectangle_pos_x = 0.0f;
float g_rectangle_pos_y = 0.0f;

// is left mouse button (lmb) pressed or not
bool g_lmb = false;
float g_lmb_pos_x = 0.0f;
float g_lmb_pos_y = 0.0f;

// these are for textures
ILuint *g_img_name;
GLuint *g_image;


// This function is called to initialise opengl
void Init()
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
//    glDepthFunc(GL_LEQUAL);

//	glEnable(GL_LIGHT0);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	g_img_name = new ILuint[4];
	ilGenImages(4, &g_img_name[0]);

	// first image from file ----------------
	ilBindImage(g_img_name[0]);
	// this is forcing the variable to become (const wchar_t *), which is just a hack for now?
	if (!ilLoadImage((const wchar_t *) "Images/menu.jpg")) {
		std::cout << "image file not loaded" << std::endl;
		exit(1);
	}
	ILuint img_width = ilGetInteger(IL_IMAGE_WIDTH);
	ILuint img_height = ilGetInteger(IL_IMAGE_HEIGHT);
	ILenum img_format = ilGetInteger(IL_IMAGE_FORMAT);
	ILenum img_type = ilGetInteger(IL_IMAGE_TYPE);
	ILubyte *img_data = ilGetData();
	//
	g_image = new GLuint[4];
	glGenTextures(2, &g_image[0]);
	glBindTexture(GL_TEXTURE_2D, g_image[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img_width,
		img_height, 0, img_format, img_type,
		img_data);
	// ilDeleteImages(1, &g_img_name);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
        GL_NEAREST);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

// ------------------------------------Play Button --------------------------------------------------
	ilBindImage(g_img_name[1]);
	// this is forcing the variable to become (const wchar_t *), which is just a hack for now?
	if (!ilLoadImage((const wchar_t *) "images/playbut.png")) {
		std::cout << "image file not loaded" << std::endl;
		exit(1);
	}
	ILuint playButtonWidth = ilGetInteger(IL_IMAGE_WIDTH);
	ILuint playButtonHeight = ilGetInteger(IL_IMAGE_HEIGHT);
	ILenum playButtonFormat = ilGetInteger(IL_IMAGE_FORMAT);
	ILenum playButtonType = ilGetInteger(IL_IMAGE_TYPE);
	ILubyte *playButtonData = ilGetData();
	//
	glBindTexture(GL_TEXTURE_2D, g_image[1]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, playButtonWidth,
		playButtonHeight, 0, playButtonFormat, playButtonType,
		playButtonData);
	// ilDeleteImages(1, &g_img_name);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
        GL_NEAREST);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// --------------------------------------Exit button ------------------------
	ilBindImage(g_img_name[2]);
	// this is forcing the variable to become (const wchar_t *), which is just a hack for now?
	if (!ilLoadImage((const wchar_t *) "images/exitbut.png")) {
		std::cout << "image file not loaded" << std::endl;
		exit(1);
	}
	ILuint exitButtonWidth = ilGetInteger(IL_IMAGE_WIDTH);
	ILuint exitButtonHeight = ilGetInteger(IL_IMAGE_HEIGHT);
	ILenum exitButtonFormat = ilGetInteger(IL_IMAGE_FORMAT);
	ILenum exitButtonType = ilGetInteger(IL_IMAGE_TYPE);
	ILubyte *exitButtonData = ilGetData();
	//
	glBindTexture(GL_TEXTURE_2D, g_image[2]);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, exitButtonWidth,
		exitButtonHeight, 0, exitButtonFormat, exitButtonType,
		exitButtonData);
	// ilDeleteImages(1, &g_img_name);
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

void Draw2D()
{
	/*glColor4f(0.5,0.5,0.5,0.8);
	glPointSize(8);
	glBegin(GL_POINTS);
		glVertex2f(g_lmb_pos_x,240.0f);
	glEnd();*/

	/*glColor4f(0.2,0.8,0.2,0.5);
	glPointSize(16);
	glBegin(GL_POINTS);
		glVertex2f(480.0f,240.0f);
	glEnd();*/

	/*glColor4f(0.0,0.0,0.0,1.0);
	glLineWidth(2.0);
	glPushMatrix();
		glTranslatef(g_rectangle_pos_x, g_rectangle_pos_y, 0.0f);
		// there's also glRotatef() if needed
		glBegin(GL_LINE_LOOP);
			glVertex2f(100.0f, 200.0f);
			glVertex2f(200.0f, 200.0f);
			glVertex2f(200.0f, 150.0f);
			glVertex2f(100.0f, 150.0f);
		glEnd();
	glPopMatrix();*/

	/*glColor4f(0.0,0.0,1.0,1.0);
	glLineWidth(4.0);
	glBegin(GL_LINES);
		glVertex2f(150.0f,300.0f);
		glVertex2f(150.0f,400.0f);
	glEnd();*/

	/*glColor4f(1.0,0.0,0.0,0.5);
	glBegin(GL_TRIANGLES);
		glVertex2f(300.0f,300.0f);
		glVertex2f(400.0f,300.0f);
		glVertex2f(400.0f,350.0f);
	glEnd();*/

	// draw texture
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, g_image[0]); // choose which one before draw
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(0.0,0.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(0.0,720.0);
		glTexCoord2f(1.0, 1.0); glVertex2f(1280.0,720.0);
		glTexCoord2f(1.0, 0.0); glVertex2f(1280.0,0.0);
	glEnd();

	// draw texture
	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, g_image[1]); // choose which one before draw
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(340.0,350.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(340.0,450.0);
		glTexCoord2f(1.0, 1.0); glVertex2f(540.0,450.0);
		glTexCoord2f(1.0, 0.0); glVertex2f(540.0,350.0);
	glEnd();


	glColor4f(1.0,1.0,1.0,1);
	glBindTexture(GL_TEXTURE_2D, g_image[2]); // choose which one before draw
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0); glVertex2f(740.0,350.0);
		glTexCoord2f(0.0, 1.0); glVertex2f(740.0,450.0);
		glTexCoord2f(1.0, 1.0); glVertex2f(940.0,450.0);
		glTexCoord2f(1.0, 0.0); glVertex2f(940.0,350.0);
	glEnd();



}

// This is the main display callback function.
// It sets up an orthographic projection and calls Draw2D().
void Draw()
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

	Draw2D();

	// Bring the back buffer to the front and vice-versa
	glutSwapBuffers();
}

// 	This function is called when the window is resized.
void Resize(int w, int h);

// This is called when the mouse is clicked.
void OnMouseClick(int button,int state,int x,int y)
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			// Play button
			if((x < 540 && x > 340) && (y < 450 && y > 350)){
				std::cout << "Clicked that Play button "<<std::endl;
				main1(0, 0);
			}

			// Exit button
			if((x < 940 && x > 740) && (y < 450 && y > 350)){
				exit(0);
			}

			g_lmb = true;
			g_lmb_pos_x = x;
			g_lmb_pos_y = y;
		} else { // GLUT_UP
			g_lmb = false;
		}
	}

	glutPostRedisplay();
}

// This is called when the mouse is moved.
void MouseMotion(int x, int y)
{
	if (g_lmb) {
		g_lmb_pos_x = x;
		g_lmb_pos_y = y;
	}

	glutPostRedisplay();
}

// This is called when keyboard presses are detected.
void Keyboard(unsigned char Key,int x,int y)
{
	if (Key == 'a') {
		g_rectangle_pos_x -= 2.0f;
	}
	if (Key == 'd') {
		g_rectangle_pos_x += 2.0f;
	}
	if (Key == 'w') {
		g_rectangle_pos_y -= 2.0f;
	}
	if (Key == 's') {
		g_rectangle_pos_y += 2.0f;
	}

	if (Key == 'p') {
		std::cout << "print something on the screen..." << std::endl;
	}

	glutPostRedisplay();
}

const char* Instructions = " a - move left\n d - move right\n";

int main(int argc,char **argv)
{
	printf(Instructions);

	glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH|GLUT_DOUBLE);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(200,200);
	glutCreateWindow("Space Tower Defence");

	glutDisplayFunc(Draw);
	glutReshapeFunc(Resize);
	glutMouseFunc(OnMouseClick);
	glutMotionFunc(MouseMotion);
	glutKeyboardFunc(Keyboard);

	ilInit();
	Init();

	glutMainLoop();
	return 0;
}
