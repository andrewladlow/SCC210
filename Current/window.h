#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
void initialiseWindow(int argc,char **argv);
void MenuWindow();
void LevelWindow(int levelSelected);
void LevelSelectWindow();
void WinWindow();
void LoseWindow();
void switchToMenu();
void switchToLevelSelect();
void switchToLevel();
void switchToWinScreen();
void switchToLoseScreen();
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
extern sf::Texture enemyTexture[4][4];
extern sf::Texture basicTowerTexture[2];
extern sf::Texture longRangeTowerTexture[2];
extern sf::Music menuMusic;
extern sf::Texture padLockTexture;
extern sf::Texture bombTexture[2];
extern sf::Texture slowingTowerTexture[2];
extern sf::Texture economyTowerTexture;