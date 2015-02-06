#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
   public:
      float xPos;
      float yPos;
	  int healthPoints;
	  float speed;
	  int type;
	  int arrayNum;
	  bool spawned;
	  bool end;
	  Enemy(float, float, int, int, int);
	  void draw(int);
};

#endif