#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "level.h"
#include "window.h"
#include "pathing.h"
#include "LevelSelect.h"
#include "enemy.h"
#include "Tower.h"
#include "bomb.h"
#include "highscore.h"
#include "menu.h"
#include <sstream>
//#include <vector>
using namespace std;

bool waveActive = false;

int healthAmount = 100;
int currencyAmount = 100;
int mobAmount = 20;
int waveNum = 0;

Enemy* mobArray[4][20];
Bomb* bomb;

Tower* createdTowers[30];
int currentTower = 0;
bool pickedUpTower = false;
bool pickedUpBomb = false;

sf::SoundBuffer levelSoundBuffer;

void InitLevel(int levelValue)
{
	cout << currentLevel << std::endl;
	mobAmount = 20;
	healthAmount = 100;
	for (int i=0; i<30; i++) {
		createdTowers[i] = NULL;
	}
	waveActive = false;
	currentTower=0;
	for (int i=0; i<4; i++) {
		for (int j=0; j<mobAmount; j++) {
			if (currentLevel == 1)
				mobArray[i][j] = new Enemy(0-(j*200), 190, Random(1,3));
			else if (currentLevel == 2)
				mobArray[i][j] = new Enemy(150, 0-(j*200), Random(1,3));
			else if (currentLevel == 3)
				mobArray[i][j] = new Enemy(0-(j*200), 220, Random(1,3));
			else if (currentLevel == 4)
				mobArray[i][j] = new Enemy(0-(j*200), 220, Random(1,3));
			else if (currentLevel == 5)
				mobArray[i][j] = new Enemy(280-(j*200), 360, 0);
			else if (currentLevel == 6)
				mobArray[i][j] = new Enemy(1280+(j*200), 80, 0);
			else if (currentLevel == 7)
				mobArray[i][j] = new Enemy(1280+(j*200), 150, 0);
			else if (currentLevel == 8)
				mobArray[i][j] = new Enemy(80, 0-(j*200), Random(1,3));
			else if (currentLevel == 9)
				mobArray[i][j] = new Enemy(720, 720+(j*200), Random(1,3));
			else if (currentLevel == 10)
				mobArray[i][j] = new Enemy(220, 0-(j*200), Random(1,3));
		}
	}
	if (!levelSoundBuffer.loadFromFile("sound.wav"))
		cout << "error loading sound buffer";
	waveNum = 0;
	bomb = new Bomb(1350.0f, 600.0f,0);
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
			if(mobArray[waveNum][i] != NULL) {
				if (mobArray[waveNum][i]->xPos >= 280 && mobArray[waveNum][i]->yPos == 360 && mobArray[waveNum][i]->type == 0) {
					mobArray[waveNum][i]->setProperties(Random(1,3));
					mobArray[waveNum][i]->draw();
				}
			}
		}
	}

	if (currentLevel == 6) {
		for (int i=0; i<mobAmount; i++) {
			if(mobArray[waveNum][i] != NULL) {
				if (mobArray[waveNum][i]->xPos <= 1240 && mobArray[waveNum][i]->yPos == 80 && mobArray[waveNum][i]->type == 0) {
					mobArray[waveNum][i]->setProperties(Random(1,3));
					mobArray[waveNum][i]->draw();
				}
			}
		}
	}

	if (currentLevel == 7) {
		for (int i=0; i<mobAmount; i++) {
			if(mobArray[waveNum][i] != NULL) {
				if (mobArray[waveNum][i]->xPos <= 1240 && mobArray[waveNum][i]->yPos == 150 && mobArray[waveNum][i]->type == 0) {
					mobArray[waveNum][i]->setProperties(Random(1,3));
					mobArray[waveNum][i]->draw();
				}
			}
		}
	}

		//bomb handling 
	if(pickedUpBomb)
	{
		bomb->setPos(towerX, towerY);
		bomb->DrawBomb();
	}
	else if(bomb->timerStarted)
	{
		bomb->DrawBomb();
	}

	bool exploded = false;
	if (bomb->timerStarted) {
		sf::Time elapsed1 = bomb->timer.getElapsedTime();
		if (elapsed1.asSeconds() > 1.5) { //bomb explodes after one second
			bomb->timer.restart();
			exploded = true;
			bomb->timerStarted = false;
		}
	}

	// draw enemy
	if (waveActive) {
		for (int i=0; i<mobAmount; i++) {
			if(mobArray[waveNum][i] != NULL){
				if (mobArray[waveNum][i]->type != 0 ) {
					if(mobArray[waveNum][i]->timerStarted == false){
						mobArray[waveNum][i]->timer.restart();
						mobArray[waveNum][i]->timerStarted = true;
					}
					mobArray[waveNum][i]->draw();
				}

				if(exploded)  //bomb exploded - deal damage to enemies in range
					bomb->enemyInRange(mobArray[waveNum][i]);

				for(int j=0; j<30; j++){
					if(createdTowers[j] != NULL){
						createdTowers[j]->enemyInRange(mobArray[waveNum][i]);
					}
				}
				if(mobArray[waveNum][i]->healthPoints < 1){
					currencyAmount += 10;
					mobAmount--;
					for (int k=i; k<mobAmount; k++) {
						mobArray[waveNum][k] = mobArray[waveNum][k+1];
					}				
				}
			}
		}
		if (waveNum != 3 && mobAmount == 0 && healthAmount != 0) { // one wave cleared, player still alive
			waveActive = false;
			mobAmount = 20;
		} else if (waveNum == 3 && mobAmount == 0 && healthAmount != 0) { // all waves cleared, player still alive
			currencyAmount = 100;
			window.close();
			window.create(sf::VideoMode(1280, 720), "Space Tower Defence", sf::Style::Close);
			window.setFramerateLimit(60);
			//submitHighScore(currentLevel, healthAmount + currencyAmount, profileList[currentProfile]);
			if(currentLevel == levelsUnlocked)
			{
				levelsUnlocked = levelsUnlocked + 1;
				newProfile(profileList[currentProfile]);
			}
			switchToWinScreen();

		} else if (healthAmount != 0) { // keep enemies moving until health = 0
			for (int i=0; i<mobAmount; i++) {
				if(mobArray[waveNum][i] != NULL){
					GenPath(mobArray[waveNum][i], currentLevel);
					if (mobArray[waveNum][i]->end) {
						healthAmount -= 10;
						//delete mobArray[waveNum][i];
						mobAmount--;
						for (int k=i; k<mobAmount; k++) {
							mobArray[waveNum][k] = mobArray[waveNum][k+1];
						}
					}
				}
			}
		} else {
			window.close();
			window.create(sf::VideoMode(1280, 720), "Space Tower Defence", sf::Style::Close);
			window.setFramerateLimit(60);
			//submitHighScore(currentLevel, healthAmount + currencyAmount, profileList[currentProfile]);
			switchToLoseScreen();
		}
	}

	//draw health amount
	sf::Text healthText(std::to_string(healthAmount), font, 20);
	healthText.setPosition(1450, 10);
	healthText.setStyle(sf::Text::Regular);
	healthText.setColor(sf::Color::Black);
	window.draw(healthText);

	//draw currency
	sf::Text currencyText(std::to_string(currencyAmount), font, 20);
	currencyText.setPosition(1450, 50);
	currencyText.setStyle(sf::Text::Regular);
	currencyText.setColor(sf::Color::Black);
	window.draw(currencyText);

	//draw wave number
	std::stringstream waveTextResult;
	int waveTextTemp1 = waveNum;
	string waveTextTemp2 = "Current wave: ";
	waveTextResult << waveTextTemp2 << waveTextTemp1;
	string waveTextTemp3 = waveTextResult.str();
	sf::Text waveText(waveTextTemp3, font, 20);
	waveText.setPosition(10, 685);
	waveText.setStyle(sf::Text::Regular);
	waveText.setColor(sf::Color::Black);
	window.draw(waveText);

	//draw wave status
	std::stringstream waveActiveResult;
	string waveActiveTemp1;
	if (waveActive) waveActiveTemp1 = "Wave active: true";
	else waveActiveTemp1 = "Wave active: false";
	sf::Text waveActiveText(waveActiveTemp1, font, 20);
	waveActiveText.setPosition(10, 655);
	waveActiveText.setStyle(sf::Text::Regular);
	waveActiveText.setColor(sf::Color::Black);
	window.draw(waveActiveText);




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
			if(pickedUpTower && createdTowers[currentTower]->checkPlacement(currentLevel)){
					pickedUpTower = false;
					towerX = 1350;
					towerY = 240;
					currentTower++;
			}

			if(pickedUpBomb && x < 1280)
			{
				//Bomb logic 
				if(bomb->timerStarted == false){
					pickedUpBomb = false;
					bomb->timer.restart();
					bomb->timerStarted = true;
				}
			}

			// Start button
			if((x < 1460 && x > 1315) && (y < 165 && y > 100)){
				//cout << "Clicked start "<<std::endl;
				if (!waveActive) {
					waveNum++;
					waveActive = true;
					mobAmount = 20;
				}
			}

			// Exit button
			if((x < 1650 && x > 1505) && (y < 165 && y > 100)){

				currencyAmount = 100;
				window.close();
				window.create(sf::VideoMode(1280, 720), "Space Tower Defence", sf::Style::Close);
				window.setFramerateLimit(60);
				switchToLevelSelect();
			}

			// Basic Tower button
			if((x < 1410 && x > 1280) && (y < 310 && y > 170) && currencyAmount >= 50){
				if(!pickedUpBomb && !pickedUpTower){
					currencyAmount -= 50;
					createdTowers[currentTower] = new Tower(1350.0f, 240.0f,1);
					createdTowers[currentTower]->DrawTower();
					pickedUpTower = true;
				}
			}

			// Long range Tower button
			if((x < 1555 && x > 1430) && (y < 310 && y > 170) && currencyAmount >= 100){
				if(!pickedUpBomb && !pickedUpTower){
					currencyAmount -= 100;
					createdTowers[currentTower] = new Tower(1350.0f, 240.0f,2);
					createdTowers[currentTower]->DrawTower();
					pickedUpTower = true;
				}
			}

			// Slowing Tower button
			if((x < 1680 && x > 1556) && (y < 310 && y > 170) && currencyAmount >= 150){
				if(!pickedUpBomb && !pickedUpTower){
					currencyAmount -= 150;
					createdTowers[currentTower] = new Tower(1350.0f, 240.0f,3);
					createdTowers[currentTower]->DrawTower();
					pickedUpTower = true;
				}
			}

			// Bomb button
			if((x < 1410 && x > 1280) && (y < 720 && y > 550) && currencyAmount >= 50){
				if(!pickedUpBomb && !pickedUpTower && bomb->timerStarted == false){
					currencyAmount -= 50;
					bomb->DrawBomb();
					pickedUpBomb = true;
				}
			}
		}
	}
}

void MouseMotion(int x, int y)
{
	if (pickedUpTower || pickedUpBomb) {
		towerX = x;
		towerY = y;
	}

}

int Random(int min, int max)
{
   static bool first = true;
   if ( first ) 
   {  
      srand(time(NULL)); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (max - min + 1);
}