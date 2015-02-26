#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <filesystem>
#include <Windows.h>
#include <cstdio>
#include "level.h"
using namespace std;

#ifndef PROFILE_H
#define PROFILE_H

class Profile {
	public:
		Profile(string);
		string name;
		int levelsUnlocked;
		int upgradeMoney;
		bool t1l1;
		bool t2l1;
		bool t3l1;
		bool t1l2;
		bool t2l2;
		bool t3l2;
		void writeProfile();
};

#endif