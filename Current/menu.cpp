#include "menu.h"
#include "window.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <filesystem>
#include <Windows.h>
#include <cstdio>
using namespace std;

string profileList[5];
sf::Text profileName[5];
int currentProfile = 0;
int creatingProfileNumber = -1; 
string creatingNewProfileString = "";
int deletePressed = 0;
bool rescourcesLoaded = false;
int levelsUnlocked = 1;
int upgradeMoney = 0;

bool newProfile(string name){
	ofstream newProfileFile ("saves/" + name + ".towerdefence");
	if (newProfileFile.is_open())
	{
		newProfileFile <<  std::to_string(levelsUnlocked) + "\n";
		newProfileFile <<  std::to_string(upgradeMoney) + "\n";
		newProfileFile.close();
		profileList[creatingProfileNumber] = name;
		creatingNewProfileString = "";
		creatingProfileNumber = -1;
		newProfileFile.close();
	}
	else cout << "Error accessing files";


	ofstream profileListFile ("saves/savenames.towerdefenceprofiles");
	if (profileListFile.is_open())
	{
		for(int i = 0; i < 5; i++)
		{
			profileListFile << profileList[i] + "\n";
		}
		profileListFile.close();
	}
	else cout << "Error accessing files";
	return 0;
}

void loadCurrentProfile()
{
	string currentLine;
	ifstream profileFile ("saves/" + profileList[currentProfile] + ".towerdefence");
	if (profileFile.is_open())
	{
		getline (profileFile,currentLine);
		//cout << currentLine;
		levelsUnlocked = stoi(currentLine);

		getline (profileFile,currentLine);
		upgradeMoney = stoi(currentLine);

		profileFile.close();
	}
	else cout << "Unable to open file";
}

void loadProfiles()
{
	string currentLine;
	ifstream profileListFile ("saves/savenames.towerdefenceprofiles");
	for(int i = 0; i < 5; i++)
	{
		profileList[i] = "null";
	}
	if (profileListFile.is_open())
	{
		int i = 0;
		while (getline (profileListFile,currentLine) && i < 5)
		{
			profileList[i] = currentLine;
			i++;
		}
		profileListFile.close();
	}
	else cout << "Unable to open file";
	for(int i = 0; i < 5; i++)
	{
		cout << profileList[i];
	}
}



void deleteProfile(int profileNumber)
{
	cout << "deleting";
	string file = "saves/" + profileList[profileNumber] + ".towerdefence";
	cout << file;
	std::remove(file.c_str());

	profileList[profileNumber] = "null";

	ofstream profileListFile ("saves/savenames.towerdefenceprofiles");
	if (profileListFile.is_open())
	{
		for(int i = 0; i < 5; i++)
		{
			profileListFile << profileList[i] + "\n";
		}
		profileListFile.close();
	}
	else cout << "Error accessing files";
}

void MenuKeyboard(sf::Event e)
{
	if(e.text.unicode == 66 && profileList[currentProfile] != "null" && creatingProfileNumber == -1)
	{
		if(deletePressed == 0)
			deletePressed++;
		else
		{
			deleteProfile(currentProfile);
			deletePressed = 0;
		}
	}
}

void enteringText(sf::Event e){
	if((e.text.unicode >= 65 && e.text.unicode <= 90) ||  (e.text.unicode >= 97 && e.text.unicode <= 122))
	{
		cout << "ayyy lmao";
		if(profileList[currentProfile] == "null"  && creatingNewProfileString.length() < 5)
		{
			creatingProfileNumber = currentProfile;
			creatingNewProfileString += e.text.unicode;
		}
	}
	else if(e.text.unicode == 8 && creatingNewProfileString.length() > 0)
		creatingNewProfileString = creatingNewProfileString.substr(0, creatingNewProfileString.size()-1);
	else if(e.text.unicode == 13 && creatingNewProfileString != "null")
		newProfile(creatingNewProfileString);
	//else if(e.text.unicode == 127 && profileList[currentProfile] != "null" && creatingProfileNumber == -1)
	//{
	//	if(deletePressed == 0)
	//		deletePressed++;
	//	else 
	//		deleteProfile(currentProfile);
	//}
}

void InitMenu()
{
	//newProfile("Jack");#
	if(!rescourcesLoaded)
	{
			font.loadFromFile("SPACEMAN.ttf");
		menubackTexture.loadFromFile("images/Menu/menu.png");
	
		sf::Sprite menuBackSprite;
		menuBackSprite.setTexture(menubackTexture);
		window.draw(menuBackSprite);

		sf::Text loadingText("loading game...", font);
		loadingText.setCharacterSize(80);
		loadingText.setStyle(sf::Text::Regular);
		loadingText.setColor(sf::Color::White);
		sf::FloatRect textRect = loadingText.getLocalBounds();
		loadingText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
		loadingText.setPosition(sf::Vector2f(1280 / 2.0f, 720 / 2.0f));
		window.draw(loadingText);
		window.display();
		loadResources();
		rescourcesLoaded = true;
	}
	if (!menuMusic.openFromFile("audio/Fanfare for Space.ogg"))
		cout << "error loading audio"; // error
	//menuMusic.play();
	//menuMusic.setLoop(true);
	loadProfiles();
}

void DrawMenu2D()
{
	//background
	sf::Sprite menuBackSprite;
	menuBackSprite.setTexture(menubackTexture);
	window.draw(menuBackSprite);

	sf::Sprite playButtonSprite;
	playButtonSprite.setTexture(playButtonTexture);
	playButtonSprite.setPosition(sf::Vector2f(340, 350));
	window.draw(playButtonSprite);

	sf::Sprite exitButtonSprite;
	exitButtonSprite.setTexture(exitButtonTexture);
	exitButtonSprite.setPosition(sf::Vector2f(740, 350));
	window.draw(exitButtonSprite);

	sf::Text profileTitle("Select A Profile:", font);
	profileTitle.setCharacterSize(20);
	profileTitle.setStyle(sf::Text::Regular);
	profileTitle.setColor(sf::Color::White);
	sf::FloatRect textRect = profileTitle.getLocalBounds();
	profileTitle.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
	profileTitle.setPosition(sf::Vector2f(1280 / 2.0f, 200));
	window.draw(profileTitle);

	for(int i = 0; i < 5; i++)
	{
		profileName[i].setFont(font);
		profileName[i].setStyle(sf::Text::Regular);
		if(currentProfile != i)
		{
			profileName[i].setColor(sf::Color::White);
			profileName[i].setCharacterSize(20);
		}
		else 
		{
			profileName[i].setColor(sf::Color::Red);
			profileName[i].setCharacterSize(30);
		}
		if(creatingProfileNumber == i)
		{
			profileName[i].setString(creatingNewProfileString);
		}
		else
		{
			if(profileList[i] == "null")
				profileName[i].setString("Empty");
			else
				profileName[i].setString(profileList[i]);
		}
		textRect = profileName[i].getLocalBounds();
		profileName[i].setOrigin(textRect.left + textRect.width / 2.0f, 0);
		profileName[i].setPosition(sf::Vector2f((1280 / 4.0f) + i * (1280 / 8.0f) , 250));
		window.draw(profileName[i]);
	}
	if(creatingProfileNumber != -1)
	{
		sf::Text profileInstructions("Press enter to finish creating a new profile:", font);
		profileInstructions.setCharacterSize(15);
		profileInstructions.setStyle(sf::Text::Regular);
		profileInstructions.setColor(sf::Color::White);
		sf::FloatRect textRect = profileInstructions.getLocalBounds();
		profileInstructions.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
		profileInstructions.setPosition(sf::Vector2f(1280 / 2.0f, 240));
		window.draw(profileInstructions);
	}
	else if(profileList[currentProfile] == "null")
	{
		sf::Text profileInstructions("Start typing to create a new profile:", font);
		profileInstructions.setCharacterSize(15);
		profileInstructions.setStyle(sf::Text::Regular);
		profileInstructions.setColor(sf::Color::White);
		sf::FloatRect textRect = profileInstructions.getLocalBounds();
		profileInstructions.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
		profileInstructions.setPosition(sf::Vector2f(1280 / 2.0f, 240));
		window.draw(profileInstructions);
	}
	else if(deletePressed == 1)
	{
		sf::Text profileInstructions("Press delete again to delete the profile \"" + profileList[currentProfile] + "\":", font);
		profileInstructions.setCharacterSize(15);
		profileInstructions.setStyle(sf::Text::Regular);
		profileInstructions.setColor(sf::Color::White);
		sf::FloatRect textRect = profileInstructions.getLocalBounds();
		profileInstructions.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top  + textRect.height / 2.0f);
		profileInstructions.setPosition(sf::Vector2f(1280 / 2.0f, 240));
		window.draw(profileInstructions);
	}
}

void MenuOnMouseClick(int button,int x,int y)
{
	if(button == sf::Mouse::Left)
	{
		if((x < 540 && x > 340) && (y < 450 && y > 350) && profileList[currentProfile] != "null"){
			loadCurrentProfile();
			menuMusic.stop();
			switchToLevelSelect();
		}
		if((x < 940 && x > 740) && (y < 450 && y > 350)){
			exit(0);
		} 
		sf::FloatRect profileNameRects[5];
		for(int i = 0; i < 5; i++)
		{
			profileNameRects[i] = profileName[i].getLocalBounds();
			if((x < profileName[i].getPosition().x + (profileNameRects[i].width / 2)  && x > (profileName[i].getPosition().x - (profileNameRects[i].width / 2))) && (y < profileName[i].getPosition().y + profileNameRects[i].height && y > profileName[i].getPosition().y))
			{
				currentProfile = i;
				creatingProfileNumber = -1;
				creatingNewProfileString = "";
			}
		}
	}
}