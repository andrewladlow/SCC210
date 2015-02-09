#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "levelSelect.h"
#include "window.h"
#include <vector>
using namespace std;
int currentLevel = 1;

sf::Texture levelSelectBackgroundTexture;
sf::Texture exitButtonLSTexture;
sf::Texture levelsTextures[3];

void InitLevelSelect()
{
	levelSelectBackgroundTexture.loadFromFile("Images/LevelSelect/background.png");
	exitButtonLSTexture.loadFromFile("images/Shared/exitbut.png");
	for(int i = 0; i < 3; i++)
		levelsTextures[i].loadFromFile("Images/LevelSelect/Level" + std::to_string(i) + ".png");
}
void DrawLevelSelect2D()
{
	sf::Sprite levelSelectBackgroundSprite;
	levelSelectBackgroundSprite.setTexture(levelSelectBackgroundTexture);
	window.draw(levelSelectBackgroundSprite);

	sf::Sprite exitButtonSprite;
	exitButtonSprite.setTexture(exitButtonLSTexture);
	exitButtonSprite.setPosition(sf::Vector2f(1060, 600));
	window.draw(exitButtonSprite);

	//Current Level
	sf::RectangleShape levelSprites[3];
	levelSprites[0].setSize(sf::Vector2f(427, 240));
	levelSprites[0].setPosition(410, 280);
	levelSprites[0].setTexture(&levelsTextures[currentLevel]);
	window.draw(levelSprites[0]);

	//Previous Level
	levelSprites[1].setSize(sf::Vector2f(160, 95));
	levelSprites[1].setPosition(120, 355);
	levelSprites[1].setTexture(&levelsTextures[currentLevel-1]);
	window.draw(levelSprites[1]);

	// Next level 
	levelSprites[2].setSize(sf::Vector2f(160, 95));
	levelSprites[2].setPosition(957, 355);
	levelSprites[2].setTexture(&levelsTextures[currentLevel+1]);
	window.draw(levelSprites[2]);

	sf::CircleShape leftArrow(50, 3);
	leftArrow.setPosition(sf::Vector2f(300, 450));
	leftArrow.setOutlineColor(sf::Color::Black);
	leftArrow.setOutlineThickness(3);
	leftArrow.setFillColor(sf::Color::Green);
	leftArrow.rotate(-90);
	window.draw(leftArrow);

	sf::CircleShape rightArrow(50, 3);
	rightArrow.setPosition(sf::Vector2f(940, 350));
	rightArrow.setOutlineColor(sf::Color::Black);
	rightArrow.setOutlineThickness(3);
	rightArrow.setFillColor(sf::Color::Green);
	rightArrow.rotate(90);
	window.draw(rightArrow);
}

// This is called when keyboard presses are detected.
void LevelSelectKeyboard(int Key){
	if (Key == sf::Keyboard::Escape) {
		switchToMenu();
	}
}
//
// This is called when the mouse is clicked.
void LevelSelectOnMouseClick(int button,int x,int y){
	if(button == sf::Mouse::Left)
	{
		// Exit button
		if((x < 1260 && x > 1060) && (y < 700 && y > 600)){
			switchToMenu();
		}

		// Play Level
		if((x < 837 && x > 410) && (y < 520 && y > 280)){
			switchToLevel();
		}

		// Right arrow
		if((x < 947 && x > 847) && (y < 500 && y > 300)){
			if(currentLevel < 2){currentLevel++;}
		}

		// Left arrow
		if((x < 400 && x > 300) && (y < 500 && y > 300)){
			if(currentLevel > 1){currentLevel--;}
		}

	}
}