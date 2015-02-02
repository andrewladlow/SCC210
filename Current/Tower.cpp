#include <GL/glut.h>
#include "loadTexture.h"
#include "IL/il.h"

class Tower
{
   public:
      float x;
      float y;
	  float direction;
	  int type;

	  // Towers
	  ILuint *towerIluintArray;
	  GLuint *towerGluintArray;

	  Tower(float, float, int);
};

Tower::Tower(float theX, float theY, int theType)
{
	x = theX;
	y = theY;
	direction = 0;
	type = theType;

	towerIluintArray = new ILuint[2];
	towerGluintArray = new GLuint[2];

	switch(type)
	{
	case 1:
		loadTexture((const wchar_t*)"Images/Towers/Basic tower/basicTowerBase.png", &towerIluintArray[0], &towerGluintArray[0]);
		loadTexture((const wchar_t*)"Images/Towers/Basic tower/basicTowerTop.png", &towerIluintArray[0], &towerGluintArray[0]);
		break;
	}

}

void 