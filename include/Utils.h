/*
 * Utils.c
 *
 *  Created on: 3 oct. 2017
 *      Author: Valentin
 */

#ifndef INCLUDE_UTILS_H_
#define INCLUDE_UTILS_H_

#include <string>
#include <vector>

using namespace std;

int split(vector<string>& tokens, string str, char separator)
{
	tokens.clear();

	string::size_type stTemp = str.find(separator);

	while(stTemp != string::npos)
	{
		tokens.push_back(str.substr(0, stTemp));
		str = str.substr(stTemp + 1);
		stTemp = str.find(separator);
	}

	tokens.push_back(str);

	return tokens.size();
}



#endif /* INCLUDE_UTILS_H_ */
