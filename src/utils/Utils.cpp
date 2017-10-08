/*
 * Utils.cpp
 *
 *  Created on: 5 oct. 2017
 *      Author: Valentin
 */

#include "utils/Utils.h"

int split(vector<string>& tokens, string str, char separator)
{
	tokens.clear();

	string::size_type stTemp = str.find(separator);

	while (stTemp != string::npos)
	{
		tokens.push_back(str.substr(0, stTemp));
		str = str.substr(stTemp + 1);
		stTemp = str.find(separator);
	}

	tokens.push_back(str);

	return tokens.size();
}

void setLogLine(int y)
{
	COORD coord;
	coord.X = 0;
	coord.Y = y + 30;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
