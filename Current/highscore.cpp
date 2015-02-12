#include <SFML/Network.hpp>
#include "highscore.h"
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
	request.setBody("level=" + std::to_string(level) + "&score=" + std::to_string(score) + "&name=" + name);

	sf::Http::Response response = http.sendRequest(request);
	//send a HS up to the DB
	if (response.getStatus() == sf::Http::Response::Ok)
		return true;
    else
		return false;
}

Highscore getHighScores()
{
	Highscore highScoreInfo;

	sf::Http http("jwoodmansey.com");
	sf::Http::Request request;
	request.setMethod(sf::Http::Request::Get);
	request.setUri("/scc210/getscores");
	request.setHttpVersion(1, 1); // HTTP 1.1
	request.setField("Content-Type", "application/x-www-form-urlencoded");

	sf::Http::Response response = http.sendRequest(request);
	//std::cout << "body: " <<  << std::endl;
	string responseString = response.getBody();

	for(int i = 0; i < 10; i++)
		highScoreInfo.highScoreCount[i] = 0;

	string temp;
	int last = 0; int next = 0;
	int level = 0; int scoreNumber = 0; int field = 0;
	while ((next = responseString.find(',', last)) != string::npos) //this is really disgusting code but works
	{
		temp = responseString.substr(last, next-last);
		if(field == 1 || field == 2)
			highScoreInfo.highScores[level][highScoreInfo.highScoreCount[level]][field-1] = temp;
		if(field == 0) //set the current level we're adding the score to
		{
			level = atoi(temp.c_str());
			field++;
		}
		else if(field == 2)
		{
			highScoreInfo.highScoreCount[level]++;
			if(highScoreInfo.highScoreCount[level] >= 10) //we don't want more than the 10 highest scores for each level (althought the DB shouldn't ever return more - check anyway)
				break;
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

		return highScoreInfo;
	}

	//debug info, not needed

	//for(int i = 0; i < 10; i++)
	//{
	//	for(int j = 0; j < highScoreInfo.highScoreCount[i]; j++)
	//	{
	//		cout << "Level: " + std::to_string(i) + "\tScore Number: "  + std::to_string(j);
	//		for(int k = 0; k < 2; k++)
	//		{
	//			switch(k)
	//			{
	//				case 0:
	//					cout << "\tScore: ";
	//					break;
	//				case 1:
	//					cout << "\tName: ";
	//					break;
	//			}
	//			cout << highScoreInfo.highScores[i][j][k];
	//		}
	//		cout <<  "\n";
	//	}
	//}
	//cout << responseString.substr(last) << endl;

}