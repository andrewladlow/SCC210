#include <SFML/Network.hpp>
#include "highscore.h"
#include "LevelSelect.h"
using namespace std;

bool submitHighScore(int level, int score, string name)
{
	sf::Http http("jwoodmansey.com");
	sf::Http::Request request;
	request.setMethod(sf::Http::Request::Post);
	request.setUri("/scc210/sendscore");
	request.setHttpVersion(1, 1); // HTTP 1.1
	request.setField("From", "me");
	request.setField("Content-Type", "application/x-www-form-urlencoded");
	request.setBody("level=" + std::to_string(level - 1) + "&score=" + std::to_string(score) + "&name=" + name);

	sf::Http::Response response = http.sendRequest(request);
	//send a HS up to the DB
	if (response.getStatus() == sf::Http::Response::Ok)
		return true;
    else
		return false;
}

void getHighScores()
{
	int highScoreCount[10];

	sf::Http http("jwoodmansey.com");
	sf::Http::Request request;
	request.setMethod(sf::Http::Request::Get);
	request.setUri("/scc210/getscores");
	request.setHttpVersion(1, 1); // HTTP 1.1
	request.setField("Content-Type", "application/x-www-form-urlencoded");

	sf::Http::Response response = http.sendRequest(request);
	string responseString = response.getBody();

	for(int i = 0; i < 10; i++)
		highScoreCount[i] = 0;

	string temp;
	int last = 0; int next = 0;
	int level = 0; int scoreNumber = 0; int field = 0;
	while ((next = responseString.find(',', last)) != string::npos)
	{
		temp = responseString.substr(last, next-last);
		if(field == 1 || field == 2)
			highScores[level][highScoreCount[level]][field-1] = temp;
		if(field == 0) //set the current level we're adding the score to
		{
			level = atoi(temp.c_str());
			field++;
		}
		else if(field == 2)
		{
			highScoreCount[level]++;
			field = 0;
		}
		else 
		{
			field++;
		}
		last = next + 1;
		if(level >= 10)
		{
			break;
		}
	}
}