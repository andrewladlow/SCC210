#include <stdlib.h>
#include "IL/il.h"
#include <GL/glut.h>
#include <iostream>

void loadTexture(const wchar_t* imageFile, ILuint* iluintArray, GLuint* gluintArray){

	ilGenImages(1, iluintArray);

	ilBindImage(*iluintArray);

	if (!ilLoadImage(imageFile)) {
		std::cout << "image file not loaded" << std::endl;
		exit(1);
	}
	ILuint img_width = ilGetInteger(IL_IMAGE_WIDTH);
	ILuint img_height = ilGetInteger(IL_IMAGE_HEIGHT);
	ILenum img_format = ilGetInteger(IL_IMAGE_FORMAT);
	ILenum img_type = ilGetInteger(IL_IMAGE_TYPE);
	ILubyte *img_data = ilGetData();

	glGenTextures(1, gluintArray);
	glBindTexture(GL_TEXTURE_2D, *gluintArray);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, img_width,
		img_height, 0, img_format, img_type,
		img_data);
	// ilDeleteImages(1, &iluintArray);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, 
        GL_NEAREST);
//	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	
}