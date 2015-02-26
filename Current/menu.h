#include "window.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Profile.h"
using namespace std;
void InitMenu();
void DrawMenu2D();
void MenuOnMouseClick(int button,int x,int y);
void MenuKeyboard(sf::Event e);
void enteringText(sf::Event e);
bool newProfile(string name);
extern string profileList[5];
extern int currentProfile;
extern Profile * profile;