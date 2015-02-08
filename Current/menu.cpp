#include "menu.h"

sf::Texture menubackTexture;
sf::Texture playButtonTexture;
sf::Texture exitButtonTexture;
using namespace std;

void InitMenu()
{
	menubackTexture.loadFromFile("images/Menu/menu.png");
	playButtonTexture.loadFromFile("images/Shared/playbut.png");
	exitButtonTexture.loadFromFile("images/Shared/exitbut.png");
}

void DrawMenu2D()
{
	//background
	sf::Sprite menuBackSprite;
	menuBackSprite.setTexture(menubackTexture);
	window.draw(menuBackSprite);

	sf::Sprite playButtonSprite;
	playButtonSprite.setTexture(playButtonTexture);
	playButtonSprite.setPosition(sf::Vector2f(340, 350));
	window.draw(playButtonSprite);

	sf::Sprite exitButtonSprite;
	exitButtonSprite.setTexture(exitButtonTexture);
	exitButtonSprite.setPosition(sf::Vector2f(740, 350));
	window.draw(exitButtonSprite);
}

void MenuOnMouseClick(int button,int x,int y)
{
	if(button == sf::Mouse::Left)
	{
		if((x < 540 && x > 340) && (y < 450 && y > 350)){
			switchToLevelSelect();
		}
		if((x < 940 && x > 740) && (y < 450 && y > 350)){
			exit(0);
		} 
	}
}