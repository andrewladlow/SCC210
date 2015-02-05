#ifndef TOWER_H
#define TOWER_H

class Tower {
   public:
      float x;
      float y;
	  float direction;
	  int type;

	  ILuint *towerIluintArray;
	  GLuint *towerGluintArray;

	  Tower(float, float, int);
};

#endif