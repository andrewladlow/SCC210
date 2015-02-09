#include "bullet.h";

Bullet::Bullet(float* originX, float* originY, float* targetX, float* targetY)
{
	this->originX = originX;
	this->originY = originY;
	this->targetX = targetX;
	this->targetY = targetY;

}

void Bullet::draw()
{
	//Bullet sprite and bullet textures need sorting in the actual level
	//bulletSprite.setTexture(&bulletTexture[type]);
	//bulletSprite.setSize(sf::Vector2f(50, 50));
	//bulletSprite.setPosition(xPos, yPos);
	//window.draw(bulletSprite);
}
