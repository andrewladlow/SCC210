#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "level.h"
#include "window.h"
#include "pathing.h"
#include "LevelSelect.h"
#include "enemy.h"
#include "bullet.h"

//#include <vector>
using namespace std;

int towersPlaced = 0;

bool waveActive = false;
bool towerActive = false;
bool tower_being_moved = false;

bool endLevel = false;

Enemy* testMob1;
Enemy* testMob2;
Bullet* testBullet;
sf::Texture sideMenuTexture;
sf::Texture levelBackgroundTexture;
sf::Texture enemyTexture[3];
sf::Texture basicTowerTexture;

void InitLevel(int levelValue)
{
	sideMenuTexture.loadFromFile("Images/Levels/UI/LevelUI.png");
	levelBackgroundTexture.loadFromFile("Images/LevelSelect/Level" + std::to_string(currentLevel) + ".png");
	enemyTexture[0].loadFromFile("Images/megaman.png");
	basicTowerTexture.loadFromFile("images/Towers/Basic tower/basicTowerFull.png");

	testMob1 = new Enemy(50, 200, 100, 0, 0);
	testMob2 = new Enemy(50, 200, 100, 0, 1);
}

void DrawLevel2D()
{
	sf::RectangleShape background(sf::Vector2f(1680, 720));
	background.setFillColor(sf::Color(255, 255, 255));
	window.draw(background);

	sf::RectangleShape levelBackgroundSprite(sf::Vector2f(1280, 720));

	levelBackgroundSprite.setTexture(&levelBackgroundTexture);
	window.draw(levelBackgroundSprite);

	// draw screen | menu line
	sf::RectangleShape line(sf::Vector2f(720, 4));
	line.setFillColor(sf::Color(0, 0, 0));
	line.setPosition(sf::Vector2f(1280, 0));
	line.rotate(90);
	window.draw(line);

	// draw UI
	sf::Sprite sideMenu;
	sideMenu.setTexture(sideMenuTexture);
	sideMenu.setPosition(1280, 0);
	window.draw(sideMenu);
	testMob1->draw();

	if (towerActive) {
		sf::RectangleShape tower(sf::Vector2f(towerX, towerY));
		tower.setPosition(towerX, towerY);
		tower.setTexture(&basicTowerTexture);
		tower.setSize(sf::Vector2f(130, 140));
		window.draw(tower);
	}
	// draw enemy
	if (waveActive) {
		testMob1->draw();
		std::cout << testMob1->xPos <<std::endl;
		std::cout << testMob1->yPos <<std::endl;

		if (!endLevel) {
			GenPath(testMob1, currentLevel);
			if (testMob1->xMod > 300) {
				testMob2->draw();
				GenPath(testMob2, currentLevel);
			}
		} else {
			delete testMob1;
			delete testMob2;
			endLevel = false;
			waveActive = false;
		}
	}
}
//
//// This is called when keyboard presses are detected.
void LevelKeyboard(int Key){
	if (Key == sf::Keyboard::Escape) {
		window.close();
		window.create(sf::VideoMode(1280, 720), "Space Tower Defence", sf::Style::Close);
		window.setFramerateLimit(60);
		switchToLevelSelect();
	}
}

// This is called when the mouse is clicked.
void LevelOnMouseClick(int button, int type, int x, int y){
	if(button == sf::Mouse::Left)
	{
		cout << "PRESSSSSSSSSS";
		if(type == sf::Event::MouseButtonPressed)
		{
			if(tower_being_moved)
			{
				tower_being_moved = false;
			}
			else if(towerX-x+50<50 && towerX-x+50>-50 && towerY-y+50<50 && towerY-y+50>-50){
				tower_being_moved = true;
				towerX = x-50;
				towerY = y-50;
			}

			// Start button
			if((x < 1460 && x > 1315) && (y < 165 && y > 100)){
				cout << "Clicked start "<<std::endl;
				waveActive = true;
			}
			if((x < 1650 && x > 1505) && (y < 165 && y > 100)){
				window.close();
				window.create(sf::VideoMode(1280, 720), "Space Tower Defence", sf::Style::Close);
				window.setFramerateLimit(60);
				switchToLevelSelect();
			}
			if((x < 1410 && x > 1280) && (y < 310 && y > 170)){
				towerActive = true;
			}
		}
	}
}

void MouseMotion(int x, int y)
{
	if (tower_being_moved) {
		towerX = x-50;
		towerY = y-50;
	}

}