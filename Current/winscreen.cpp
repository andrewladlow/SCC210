#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "window.h"

//#include <vector>
using namespace std;

void DrawWin2D() {
	sf::Sprite levelSelectBackgroundSprite;
	levelSelectBackgroundSprite.setTexture(levelSelectBackgroundTexture);
	window.draw(levelSelectBackgroundSprite);

	sf::Text WinScreen1("YOU WIN!", font);
	WinScreen1.setCharacterSize(40);
	WinScreen1.setStyle(sf::Text::Regular);
	WinScreen1.setColor(sf::Color::White);
	sf::FloatRect textRect1 = WinScreen1.getLocalBounds();
	WinScreen1.setOrigin(textRect1.left + textRect1.width / 2.0f, textRect1.top  + textRect1.height / 2.0f);
	WinScreen1.setPosition(sf::Vector2f(1280 / 2.0f, 200));
	window.draw(WinScreen1);


	sf::Text WinScreen2("Level Select", font);
	WinScreen2.setCharacterSize(20);
	WinScreen2.setStyle(sf::Text::Regular);
	WinScreen2.setColor(sf::Color::White);
	sf::FloatRect textRect2 = WinScreen2.getLocalBounds();
	WinScreen2.setOrigin(textRect2.left + textRect2.width / 2.0f, textRect2.top  + textRect2.height / 2.0f);
	WinScreen2.setPosition(240, 550);
	window.draw(WinScreen2);


	sf::Text WinScreen3("Exit", font);
	WinScreen3.setCharacterSize(20);
	WinScreen3.setStyle(sf::Text::Regular);
	WinScreen3.setColor(sf::Color::White);
	sf::FloatRect textRect3 = WinScreen3.getLocalBounds();
	WinScreen3.setOrigin(textRect3.left + textRect3.width / 2.0f, textRect3.top  + textRect3.height / 2.0f);
	WinScreen3.setPosition(1040, 550);
	window.draw(WinScreen3);

}

void WinOnMouseClick(int button,int x,int y) {
	if(button == sf::Mouse::Left) {
		if((x < 640 && x > 140) && (y < 750 && y > 450)) {
			switchToLevelSelect();
		}
		if((x < 1240 && x > 1040) && (y < 650 && y > 550)) {
			exit(0);
		}
	}
}