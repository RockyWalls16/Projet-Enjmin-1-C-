/*
 * GameController.h
 *
 *  Created on: 6 oct. 2017
 *      Author: valen
 */

#ifndef INCLUDE_GAMECONTROLLER_H_
#define INCLUDE_GAMECONTROLLER_H_

#include "map/Map.h"
#include <iostream>

class GameController
{
private:
	bool shallClose;
	Map* currentMap;

public:
	GameController();

	void initGame();

	void loopGame();

	Map* getCurrentMap() const
	{
		return currentMap;
	}

	static GameController& getInstance();
};

#endif /* INCLUDE_GAMECONTROLLER_H_ */
