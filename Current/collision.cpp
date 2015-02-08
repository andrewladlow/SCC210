#include "collision.h"
bool collisionCheck(Enemy enemy, Bullet bullet) {
	if (enemy.xPos < bullet.xPos + 50 &&
		enemy.xPos + 50 > bullet.xPos &&
		enemy.yPos < bullet.yPos + 50 &&
		enemy.yPos + 50 > bullet.yPos)
		return true;
	return false;
}