#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "LoseScreen.h"

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