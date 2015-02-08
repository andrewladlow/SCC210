#include <SFML/Graphics.hpp>
void initialiseWindow(int argc,char **argv);
void MenuWindow();
void LevelWindow(int levelSelected);
void LevelSelectWindow();
void switchToMenu();
void switchToLevelSelect();
void switchToLevel();

extern float towerX;
extern float towerY;
extern sf::RenderWindow window;