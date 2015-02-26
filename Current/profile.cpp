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

		getline (profileFile,currentLine);
		t1l1 = stoi(currentLine);
		
		getline (profileFile,currentLine);
		t2l1 = stoi(currentLine);

		getline (profileFile,currentLine);
		t3l1 = stoi(currentLine);

		getline (profileFile,currentLine);
		t1l2 = stoi(currentLine);
		
		getline (profileFile,currentLine);
		t2l2 = stoi(currentLine);

		getline (profileFile,currentLine);
		t3l2 = stoi(currentLine);
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
		newProfileFile <<  std::to_string(t1l1) + "\n";
		newProfileFile <<  std::to_string(t2l1) + "\n";
		newProfileFile <<  std::to_string(t3l1) + "\n";
		newProfileFile <<  std::to_string(t1l2) + "\n";
		newProfileFile <<  std::to_string(t2l2) + "\n";
		newProfileFile <<  std::to_string(t3l2) + "\n";
		newProfileFile.close();
	}
	else cout << "Error accessing files";
}