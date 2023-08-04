#pragma once
#include <iostream>
#include <windows.h>
#include <vector>
class Utils
{
public:
	static void exitProgam();
	static int getInt();
	static int getInt(int min, int max);
	static float getFloat();
	static int mainMenu();
	static std::string UUID();
	static std::vector<std::string> split(std::string str, char delimiter);

};

