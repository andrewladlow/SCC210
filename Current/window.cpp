#include <iostream>
#include "menu.h"
#include "level.h"
#include "LevelSelect.h"
#include "winscreen.h"
#include "losescreen.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
using namespace std;
sf::RenderWindow window(sf::VideoMode(1280, 720), "Space Tower Defence", sf::Style::Close);
int screen = 0;

sf::Texture exitButtonLSTexture;
sf::Texture levelSelectBackgroundTexture;
sf::Texture levelsTextures[13];
sf::Font font;
sf::Texture menubackTexture;
sf::Texture playButtonTexture;
sf::Texture exitButtonTexture;
sf::Texture upgradeBoxTexture;
sf::Texture upgradeMenuTexture;
sf::Texture soldTexture;
sf::Texture sideMenuTexture;
sf::Texture levelBackgroundTexture;
sf::Texture enemyTexture[4][4];
sf::Texture basicTowerTexture[2];
sf::Texture longRangeTowerTexture[2];
sf::Texture slowingTowerTexture[2];
sf::Texture economyTowerTexture;
sf::Texture bombTexture[2];
sf::Texture padLockTexture;
sf::Texture iceTexture;
sf::Music menuMusic;

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
void switchToWinScreen() {
	screen = 3;
}
void switchToLoseScreen() {
	screen = 4;
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
			case sf::Event::KeyPressed:
				LevelSelectKeyboard(event.key.code);
				break;
			case sf::Event::MouseButtonPressed:
				LevelSelectOnMouseClick(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
				break;
			case sf::Event::Closed:
				window.close();
				break;
		}
	}
	window.clear();
	DrawLevelSelect2D();
}

void WinWindow() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				//LevelSelectKeyboard(event.key.code);
				break;
			case sf::Event::MouseButtonPressed:
				WinOnMouseClick(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
				break;
		}
	}
	window.clear();
	DrawWin2D();
}

void LoseWindow() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch(event.type)
		{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				//LevelSelectKeyboard(event.key.code);
				break;
			case sf::Event::MouseButtonPressed:
				LoseOnMouseClick(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
				break;
		}
	}
	window.clear();
	DrawLose2D();
}

void loadResources()
{
	playButtonTexture.loadFromFile("images/Shared/playbut.png");
	exitButtonTexture.loadFromFile("images/Shared/exitbut.png");
	levelSelectBackgroundTexture.loadFromFile("Images/LevelSelect/background.png");
	exitButtonLSTexture.loadFromFile("images/Shared/exitbut.png");
	upgradeBoxTexture.loadFromFile("images/LevelSelect/upgradesBut.png");
	upgradeMenuTexture.loadFromFile("images/LevelSelect/upgrades/upgradeMenu.png");
	soldTexture.loadFromFile("images/LevelSelect/upgrades/sold.png");
	for(int i = 0; i < 12; i++)
		levelsTextures[i].loadFromFile("Images/LevelSelect/Level" + std::to_string(i) + ".png");
	sideMenuTexture.loadFromFile("Images/Levels/UI/LevelUI.png");
	//levelBackgroundTexture.loadFromFile("Images/LevelSelect/Level" + std::to_string(currentLevel) + ".png");
	enemyTexture[0][0].loadFromFile("Images/Blank.png");
	enemyTexture[0][1].loadFromFile("Images/Blank.png");
	enemyTexture[0][2].loadFromFile("Images/Blank.png");
	enemyTexture[0][3].loadFromFile("Images/Blank.png");
	enemyTexture[1][0].loadFromFile("Images/enemy/standard enemy/1.png");
	enemyTexture[1][1].loadFromFile("Images/enemy/standard enemy/2.png");
	enemyTexture[1][2].loadFromFile("Images/enemy/standard enemy/3.png");
	enemyTexture[1][3].loadFromFile("Images/enemy/standard enemy/4.png");
	enemyTexture[2][0].loadFromFile("Images/enemy/fast enemy/1.png");
	enemyTexture[2][1].loadFromFile("Images/enemy/fast enemy/2.png");
	enemyTexture[2][2].loadFromFile("Images/enemy/fast enemy/3.png");
	enemyTexture[2][3].loadFromFile("Images/enemy/fast enemy/4.png");
	enemyTexture[3][0].loadFromFile("Images/enemy/slow enemy/1.png");
	enemyTexture[3][1].loadFromFile("Images/enemy/slow enemy/2.png");
	enemyTexture[3][2].loadFromFile("Images/enemy/slow enemy/3.png");
	enemyTexture[3][3].loadFromFile("Images/enemy/slow enemy/4.png");
	basicTowerTexture[0].loadFromFile("images/Towers/Basic tower/basicTowerBase.png");
	basicTowerTexture[1].loadFromFile("images/Towers/Basic tower/basicTowerTop.png");
	longRangeTowerTexture[0].loadFromFile("images/Towers/Long Distance tower/longDistanceBase.png");
	longRangeTowerTexture[1].loadFromFile("images/Towers/Long Distance tower/longDistanceTop.png");
	slowingTowerTexture[0].loadFromFile("images/Towers/slow tower/slow tower base.png");
	slowingTowerTexture[1].loadFromFile("images/Towers/slow tower/slow tower r.png");
	economyTowerTexture.loadFromFile("images/Towers/econmy tower/econTower.png");
	padLockTexture.loadFromFile("images/LevelSelect/padlock-hi.png");
	bombTexture[0].loadFromFile("images/bomb/bomb.png");
	bombTexture[1].loadFromFile("images/bomb/bomb_ice.png");
	iceTexture.loadFromFile("images/bomb/ice.png");
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
			case 3:
				WinWindow();
				break;
			case 4:
				LoseWindow();
				break;
		}
		window.display();
    }
}
