#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "level.h"
#include "window.h"
#include "pathing.h"
#include "LevelSelect.h"
#include "enemy.h"
#include "bullet.h"
#include "Tower.h"

//#include <vector>
using namespace std;

bool waveActive = false;

int healthAmount = 100;
int currencyAmount = 1000;
int mobAmount = 10;

Enemy* mobArray[10];

Tower* createdTowers[30];
int currentTower = 0;
bool pickedUpTower = false;

Bullet* testBullet;
sf::SoundBuffer levelSoundBuffer;


void InitLevel(int levelValue)
{
	cout << currentLevel << std::endl;
	mobAmount = 10;
	healthAmount = 100;
	for (int i=0; i<30; i++) {
		createdTowers[i] = NULL;
	}
	waveActive = false;
	currentTower=0;

	for (int i=0; i<10; i++) {
		if (currentLevel == 1)
			mobArray[i] = new Enemy(0-(i*200), 190, 1);
		else if (currentLevel == 2)
			mobArray[i] = new Enemy(150, 0-(i*200), 1);
		else if (currentLevel == 3)
			mobArray[i] = new Enemy(0-(i*200), 220, 1);
		else if (currentLevel == 4)
			mobArray[i] = new Enemy(0-(i*200), 220, 1);
		else if (currentLevel == 5)
			mobArray[i] = new Enemy(280-(i*200), 360, 0);
		else if (currentLevel == 6)
			mobArray[i] = new Enemy(1280+(i*200), 80, 0);
		else if (currentLevel == 7)
			mobArray[i] = new Enemy(1280+(i*200), 150, 0);
		else if (currentLevel == 8)
			mobArray[i] = new Enemy(80, 0-(i*200), 1);
		else if (currentLevel == 9)
			mobArray[i] = new Enemy(720, 720+(i*200), 1);
		else if (currentLevel == 10)
			mobArray[i] = new Enemy(220, 0-(i*200), 1);
	}
	if (!levelSoundBuffer.loadFromFile("sound.wav"))
		cout << "error loading sound buffer";
}

void DrawLevel2D()
{	

	sf::RectangleShape background(sf::Vector2f(1680, 720));
	background.setFillColor(sf::Color(255, 255, 255));
	window.draw(background);

	sf::RectangleShape levelBackgroundSprite(sf::Vector2f(1280, 720));

	levelBackgroundSprite.setTexture(&levelsTextures[currentLevel]);
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
	//testMob1->draw();

	// Follow mouse is tower picked up
	if(pickedUpTower){
		createdTowers[currentTower]->setPos(towerX,towerY);
	}


	// draw towers
	for(int i=0; i<30; i++){
		if(createdTowers[i] != NULL){
			createdTowers[i]->DrawTower();
		}
	}

	// handle enemy movement with certain map spawn points
	if (currentLevel == 5) {
		for (int i=0; i<mobAmount; i++) {
			if(mobArray[i] != NULL) {
				if (mobArray[i]->xPos == 280 && mobArray[i]->yPos == 360 && mobArray[i]->type == 0) {
					mobArray[i]->setProperties(1);
					mobArray[i]->draw();
				}
			}
		}
	}

	if (currentLevel == 6) {
		for (int i=0; i<mobAmount; i++) {
			if(mobArray[i] != NULL) {
				if (mobArray[i]->xPos == 1240 && mobArray[i]->yPos == 80 && mobArray[i]->type == 0) {
					mobArray[i]->setProperties(1);
					mobArray[i]->draw();
				}
			}
		}
	}

	if (currentLevel == 7) {
		for (int i=0; i<mobAmount; i++) {
			if(mobArray[i] != NULL) {
				if (mobArray[i]->xPos == 1240 && mobArray[i]->yPos == 150 && mobArray[i]->type == 0) {
					mobArray[i]->setProperties(1);
					mobArray[i]->draw();
				}
			}
		}
	}

	if (currentLevel == 8) {
		for (int i=0; i<mobAmount; i++) {
			if(mobArray[i] != NULL) {
				if (mobArray[i]->xPos == 80 && mobArray[i]->yPos == 0 && mobArray[i]->type == 0) {
					mobArray[i]->setProperties(1);
					mobArray[i]->draw();
				}
			}
		}
	}

	if (currentLevel == 9) {
		for (int i=0; i<mobAmount; i++) {
			if(mobArray[i] != NULL) {
				if (mobArray[i]->xPos == 720 && mobArray[i]->yPos == 720 && mobArray[i]->type == 0) {
					mobArray[i]->setProperties(1);
					mobArray[i]->draw();
				}
			}
		}
	}

	if (currentLevel == 10) {
		for (int i=0; i<mobAmount; i++) {
			if(mobArray[i] != NULL) {
				if (mobArray[i]->xPos == 220 && mobArray[i]->yPos == 0 && mobArray[i]->type == 0) {
					mobArray[i]->setProperties(1);
					mobArray[i]->draw();
				}
			}
		}
	}

	// draw enemy
	if (waveActive) {
		for (int i=0; i<mobAmount; i++) {
			if(mobArray[i] != NULL){
				mobArray[i]->draw();
				for(int j=0; j<30; j++){
					if(createdTowers[j] != NULL){
						createdTowers[j]->enemyInRange(mobArray[i]);
					}
				}
				if(mobArray[i]->healthPoints < 1){
					currencyAmount += 20;
					mobAmount--;
					for (int i=0; i<mobAmount; i++) {
						mobArray[i] = mobArray[i+1];
					}				
				}
			}
		}
		if (mobAmount == 0 && healthAmount != 0) { // all enemies dead, player still alive
			window.close();
			window.create(sf::VideoMode(1280, 720), "Space Tower Defence", sf::Style::Close);
			window.setFramerateLimit(60);
			switchToWinScreen();

		} else if (healthAmount != 0) { // keep enemies moving until health = 0
			for (int i=0; i<mobAmount; i++) {
				if(mobArray[i] != NULL){
					GenPath(mobArray[i], currentLevel);
					if (mobArray[i]->end) {
						healthAmount -= 10;
						//delete mobArray[i];
						mobAmount--;
						for (int i=0; i<mobAmount; i++) {
							mobArray[i] = mobArray[i+1];
						}
					}
				}
			}
		} else {
			window.close();
			window.create(sf::VideoMode(1280, 720), "Space Tower Defence", sf::Style::Close);
			window.setFramerateLimit(60);
			switchToLoseScreen();
		}
	}

	//draw health amount
	sf::Text healthText(std::to_string(healthAmount), font);
	healthText.setPosition(1450, 10);
	healthText.setCharacterSize(20);
	healthText.setStyle(sf::Text::Regular);
	healthText.setColor(sf::Color::Black);
	window.draw(healthText);

	//draw currency
	sf::Text currencyText(std::to_string(currencyAmount), font);
	currencyText.setPosition(1450, 50);
	currencyText.setCharacterSize(20);
	currencyText.setStyle(sf::Text::Regular);
	currencyText.setColor(sf::Color::Black);
	window.draw(currencyText);



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
		//cout << "LMB clicked "<<std::endl;
		if(type == sf::Event::MouseButtonPressed)
		{
			// In process of placing tower
			if(pickedUpTower && createdTowers[currentTower]->checkPlacement()){
					pickedUpTower = false;
					towerX = 1350;
					towerY = 240;
					currentTower++;
			}

			// Start button
			if((x < 1460 && x > 1315) && (y < 165 && y > 100)){
				//cout << "Clicked start "<<std::endl;
				waveActive = true;
			}

			// Exit button
			if((x < 1650 && x > 1505) && (y < 165 && y > 100)){

				window.close();
				window.create(sf::VideoMode(1280, 720), "Space Tower Defence", sf::Style::Close);
				window.setFramerateLimit(60);
				switchToLevelSelect();
			}

			// Basic Tower button
			if((x < 1410 && x > 1280) && (y < 310 && y > 170) && currencyAmount >= 100){
				if(!pickedUpTower){
					currencyAmount -= 100;
					createdTowers[currentTower] = new Tower(1350.0f, 240.0f,1);
					createdTowers[currentTower]->DrawTower();
					pickedUpTower = true;
				}
			}
		}
	}
}

void MouseMotion(int x, int y)
{
	if (pickedUpTower) {
		towerX = x;
		towerY = y;
	}

}