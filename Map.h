/*
 * Map.h
 *
 *  Created on: 2 oct. 2017
 *      Author: Valentin
 */

#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include "Entity.h"

class Map
{
private:
	std::vector<Entity*> entityList;

public:
	Map();
	virtual ~Map();
	void update(float delta);
};

#endif /* MAP_H_ */
