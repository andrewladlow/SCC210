#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "levelSelect.h"
#include "window.h"
#include <vector>
#include <SFML/Network.hpp>
#include "highscore.h"
using namespace std;
int currentLevel = 1;

//string * highScores[10][10][2];
string highScores[10][10][2];
sf::Music levelMusic;
sf::SoundBuffer lsSoundBuffer;
sf::Sound sound;
//int highScoreCount[10]; //we use this to store the number of highscore that were loaded for each level

void InitLevelSelect()
{
	if (!levelMusic.openFromFile("audio/Space 1990.ogg"))
		cout << "error loading audio"; // error
	levelMusic.play();
	levelMusic.setLoop(true);
	getHighScores();

	if (!lsSoundBuffer.loadFromFile("audio/laser_1.ogg"))
		cout << "error loading audio"; // error
	sound.setBuffer(lsSoundBuffer);
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
	sf::FloatRect spritesRect = levelSprites[0].getLocalBounds();
	levelSprites[0].setOrigin(spritesRect.left + spritesRect.width / 2.0f, spritesRect.top  + spritesRect.height / 2.0f);
	levelSprites[0].setPosition(sf::Vector2f(1280 / 2.0f, 390));
	levelSprites[0].setTexture(&levelsTextures[currentLevel]);
	window.draw(levelSprites[0]);

	//Previous Level
	levelSprites[1].setSize(sf::Vector2f(160, 95));
	levelSprites[1].setPosition(140, 355);
	levelSprites[1].setTexture(&levelsTextures[currentLevel-1]);
	window.draw(levelSprites[1]);

	// Next level 
	levelSprites[2].setSize(sf::Vector2f(160, 95));
	levelSprites[2].setPosition(977, 355);
	levelSprites[2].setTexture(&levelsTextures[currentLevel+1]);
	window.draw(levelSprites[2]);

	sf::CircleShape leftArrow(50, 3);
	leftArrow.setPosition(sf::Vector2f(320, 450));
	leftArrow.setOutlineColor(sf::Color::Black);
	leftArrow.setOutlineThickness(3);
	leftArrow.setFillColor(sf::Color::Green);
	leftArrow.rotate(-90);
	window.draw(leftArrow);

	sf::CircleShape rightArrow(50, 3);
	rightArrow.setPosition(sf::Vector2f(960, 350));
	rightArrow.setOutlineColor(sf::Color::Black);
	rightArrow.setOutlineThickness(3);
	rightArrow.setFillColor(sf::Color::Green);
	rightArrow.rotate(90);
	window.draw(rightArrow);

	//Highscores Drawing Stuff
	//draw currency

	sf::Text levelTitle("Level" + std::to_string(currentLevel), font);;
	levelTitle.setCharacterSize(40);
	levelTitle.setStyle(sf::Text::Regular);
	levelTitle.setColor(sf::Color::White);
	sf::FloatRect textRect = levelTitle.getLocalBounds();
	levelTitle.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
	levelTitle.setPosition(sf::Vector2f(1280 / 2.0f, 50));
	window.draw(levelTitle);


	sf::Text highScoreTitle("Highscores", font);
	highScoreTitle.setCharacterSize(20);
	highScoreTitle.setStyle(sf::Text::Regular);
	highScoreTitle.setColor(sf::Color::White);
	textRect = highScoreTitle.getLocalBounds();
	highScoreTitle.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
	highScoreTitle.setPosition(sf::Vector2f(1280 / 2.0f, 100));
	window.draw(highScoreTitle);

	sf::Text highScoreText;
	highScoreText.setFont(font);
	highScoreText.setCharacterSize(20);
	highScoreText.setStyle(sf::Text::Regular);
	highScoreText.setColor(sf::Color::White);
	for(int i = 0; i < 5; i++)
	{
		if (atoi(highScores[currentLevel-1][i][0].c_str()) == 0)
			break;
		highScoreText.setString(highScores[currentLevel-1][i][0] + "  " + highScores[currentLevel-1][i][1]);
		textRect = highScoreText.getLocalBounds();
		highScoreText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
		highScoreText.setPosition(sf::Vector2f(1280 / 2.0f, 130 + (i * 20)));
		window.draw(highScoreText);
	}

	//submitScore(0, 9999, "Jack");
}

// This is called when keyboard presses are detected.
void LevelSelectKeyboard(int Key){
	if (Key == sf::Keyboard::Escape) {
		levelMusic.stop();
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
			levelMusic.stop();
			switchToMenu();
		}

		// Play Level
		if((x < 837 && x > 410) && (y < 520 && y > 280)){
			switchToLevel();
		}

		// Right arrow
		if((x < 947 && x > 847) && (y < 500 && y > 300)){
			if(currentLevel < 10){
				currentLevel++;
				sound.play();
			}
		}

		// Left arrow
		if((x < 400 && x > 300) && (y < 500 && y > 300)){
			if(currentLevel > 1){
				currentLevel--;
				sound.play();
			}
		}

	}
}