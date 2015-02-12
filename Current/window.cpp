#include <iostream>
#include "menu.h"
#include "level.h"
#include "LevelSelect.h"
#include <SFML/Graphics.hpp>

#include <vector>
using namespace std;
sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Tower Defence", sf::Style::Close);
float towerX = 1280.0f;
float towerY = 170.0f;
int screen = 0;
//
sf::Texture exitButtonLSTexture;
sf::Texture levelSelectBackgroundTexture;
sf::Texture levelsTextures[13];
sf::Font font;
sf::Texture menubackTexture;
sf::Texture playButtonTexture;
sf::Texture exitButtonTexture;
sf::Texture sideMenuTexture;
sf::Texture levelBackgroundTexture;
sf::Texture enemyTexture[3];
sf::Texture basicTowerTexture[2];

//we call this function when switching screens, it will initialise whatever screen we are calling
void switchToMenu()
{
	InitMenu();
	screen = 0;
}
void switchToLevelSelect()
{
	InitLevelSelect();
	screen = 1;
}
void switchToLevel()
{
	InitLevel(0);
	window.close();
	window.create(sf::VideoMode(1680, 720), "Space Tower Defence", sf::Style::Close);
	window.setFramerateLimit(60);
	screen = 2;
}


void MenuWindow(){
	sf::Event event;
	while (window.pollEvent(event))
	{
			if (event.type == sf::Event::Closed)
				window.close();
			else if(event.type == sf::Event::MouseButtonPressed)
				MenuOnMouseClick(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
			else if(event.type == sf::Event::TextEntered)
				enteringText(event);
			else if(event.type == sf::Event::KeyPressed)
				MenuKeyboard(event);
	}
	window.clear();
	DrawMenu2D();
}
void LevelWindow(){
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch(event.type)
		{			
			case sf::Event::KeyPressed:
				LevelKeyboard(event.key.code);
				break;
			case sf::Event::MouseMoved:
				MouseMotion(event.mouseMove.x, event.mouseMove.y);
				break;
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				LevelOnMouseClick(event.mouseButton.button, event.type, event.mouseButton.x, event.mouseButton.y);
				break;
		}
	}
	window.clear();
	DrawLevel2D();
}

void LevelSelectWindow(){
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				LevelSelectKeyboard(event.key.code);
				break;
			case sf::Event::MouseButtonPressed:
				LevelSelectOnMouseClick(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
				break;
		}
	}
	window.clear();
	DrawLevelSelect2D();
}

void loadResources()
{
	playButtonTexture.loadFromFile("images/Shared/playbut.png");
	exitButtonTexture.loadFromFile("images/Shared/exitbut.png");
	levelSelectBackgroundTexture.loadFromFile("Images/LevelSelect/background.png");
	exitButtonLSTexture.loadFromFile("images/Shared/exitbut.png");
	for(int i = 0; i < 12; i++)
		levelsTextures[i].loadFromFile("Images/LevelSelect/Level" + std::to_string(i) + ".png");
	sideMenuTexture.loadFromFile("Images/Levels/UI/LevelUI.png");
	//levelBackgroundTexture.loadFromFile("Images/LevelSelect/Level" + std::to_string(currentLevel) + ".png");
	enemyTexture[0].loadFromFile("Images/megaman.png");
	enemyTexture[1].loadFromFile("Images/Blank.png");
	basicTowerTexture[0].loadFromFile("images/Towers/Basic tower/basicTowerBase.png");
	basicTowerTexture[1].loadFromFile("images/Towers/Basic tower/basicTowerTop.png");
}

void initialiseWindow(int argc,char **argv){
	window.setFramerateLimit(60);
	switchToMenu();
    while (window.isOpen())
    {
		//we need to do the logic for the current part of the game that the user is in
		switch(screen)
		{
			case 0:
				MenuWindow();
				break;
			case 1:
				LevelSelectWindow();
				break;
			case 2:
				LevelWindow();
				break;
		}
		window.display();
    }
}
