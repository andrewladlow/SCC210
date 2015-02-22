#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "LoseScreen.h"
#include "LevelSelect.h"

//#include <vector>
using namespace std;

void DrawLose2D() {
	sf::Sprite levelSelectBackgroundSprite;
	levelSelectBackgroundSprite.setTexture(levelSelectBackgroundTexture);
	window.draw(levelSelectBackgroundSprite);

	sf::Text LoseScreen1("You Lose!", font);
	LoseScreen1.setCharacterSize(40);
	LoseScreen1.setStyle(sf::Text::Regular);
	LoseScreen1.setColor(sf::Color::White);
	sf::FloatRect textRect1 = LoseScreen1.getLocalBounds();
	LoseScreen1.setOrigin(textRect1.left + textRect1.width / 2.0f, textRect1.top  + textRect1.height / 2.0f);
	LoseScreen1.setPosition(sf::Vector2f(1280 / 2.0f, 200));
	window.draw(LoseScreen1);

	sf::Text levelTitle("Level" + std::to_string(currentLevel), font);;
	levelTitle.setCharacterSize(40);
	levelTitle.setStyle(sf::Text::Regular);
	levelTitle.setColor(sf::Color::White);
	sf::FloatRect textRect = levelTitle.getLocalBounds();
	levelTitle.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
	levelTitle.setPosition(sf::Vector2f(1280 / 2.0f, 250));
	window.draw(levelTitle);


	sf::Text highScoreTitle("Highscores", font);
	highScoreTitle.setCharacterSize(20);
	highScoreTitle.setStyle(sf::Text::Regular);
	highScoreTitle.setColor(sf::Color::White);
	textRect = highScoreTitle.getLocalBounds();
	highScoreTitle.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
	highScoreTitle.setPosition(sf::Vector2f(1280 / 2.0f, 400));
	window.draw(highScoreTitle);

	sf::Text highScoreText;
	highScoreText.setFont(font);
	highScoreText.setCharacterSize(20);
	highScoreText.setStyle(sf::Text::Regular);
	highScoreText.setColor(sf::Color::White);
	for(int i = 0; i < 10; i++)
	{
		if (atoi(highScores[currentLevel-1][i][0].c_str()) == 0)
			break;
		highScoreText.setString(highScores[currentLevel-1][i][0] + "  " + highScores[currentLevel-1][i][1]);
		textRect = highScoreText.getLocalBounds();
		highScoreText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
		highScoreText.setPosition(sf::Vector2f(1280 / 2.0f, 430 + (i * 20)));
		window.draw(highScoreText);
	}

	sf::Text LoseScreen2("Level Select", font);
	LoseScreen2.setCharacterSize(20);
	LoseScreen2.setStyle(sf::Text::Regular);
	LoseScreen2.setColor(sf::Color::White);
	sf::FloatRect textRect2 = LoseScreen2.getLocalBounds();
	LoseScreen2.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top  + textRect2.height / 2.0f);
	LoseScreen2.setPosition(240, 550);
	window.draw(LoseScreen2);


	sf::Text LoseScreen3("Exit", font);
	LoseScreen3.setCharacterSize(20);
	LoseScreen3.setStyle(sf::Text::Regular);
	LoseScreen3.setColor(sf::Color::White);
	sf::FloatRect textRect3 = LoseScreen3.getLocalBounds();
	LoseScreen3.setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top  + textRect3.height / 2.0f);
	LoseScreen3.setPosition(1040, 550);
	window.draw(LoseScreen3);

}

void LoseOnMouseClick(int button,int x,int y) {
	if(button == sf::Mouse::Left) {
		if((x < 640 && x > 50) && (y < 750 && y > 450)) {
			switchToLevelSelect();
		}
		if((x < 1240 && x > 840) && (y < 750 && y > 450)) {
			exit(0);
		}
	}
}