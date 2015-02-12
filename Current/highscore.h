#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
typedef struct{
	int highScoreCount[10];
	string highScores[10][10][2];
}Highscore;

bool submitHighScore(int level, int score, string name);
Highscore getHighScores();