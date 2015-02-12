#include <SFML/Graphics.hpp>
void initialiseWindow(int argc,char **argv);
void MenuWindow();
void LevelWindow(int levelSelected);
void LevelSelectWindow();
void switchToMenu();
void switchToLevelSelect();
void switchToLevel();
void loadResources();

extern float towerX;
extern float towerY;
extern sf::RenderWindow window;
extern sf::Texture exitButtonLSTexture;
extern sf::Texture levelSelectBackgroundTexture;
extern sf::Texture levelsTextures[13];
extern sf::Font font;
extern sf::Texture menubackTexture;
extern sf::Texture playButtonTexture;
extern sf::Texture exitButtonTexture;
extern sf::Texture sideMenuTexture;
extern sf::Texture levelBackgroundTexture;
extern sf::Texture enemyTexture[3];
extern sf::Texture basicTowerTexture[2];