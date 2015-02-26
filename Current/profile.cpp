#include "Profile.h"

Profile::Profile(string name)
{
	this->name = name;

	string currentLine;
	ifstream profileFile ("saves/" + name + ".towerdefence");
	if (profileFile.is_open())
	{
		getline (profileFile,currentLine);
		levelsUnlocked = stoi(currentLine);

		getline (profileFile,currentLine);
		upgradeMoney = stoi(currentLine);

		profileFile.close();
	}
	else cout << "Unable to open file";
}

void Profile::writeProfile(){
	ofstream newProfileFile ("saves/" + name + ".towerdefence");
	if (newProfileFile.is_open())
	{
		newProfileFile <<  std::to_string(levelsUnlocked) + "\n";
		newProfileFile <<  std::to_string(upgradeMoney) + "\n";
		newProfileFile.close();
	}
	else cout << "Error accessing files";
}