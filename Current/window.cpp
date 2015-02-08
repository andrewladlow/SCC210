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
		switch(event.type)
		{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonPressed:
				MenuOnMouseClick(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
				break;
		}
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

void initialiseWindow(int argc,char **argv){
	window.setFramerateLimit(60);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
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
