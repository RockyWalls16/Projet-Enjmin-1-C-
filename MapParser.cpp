/*
 * MapParser.cpp
 *
 *  Created on: 3 oct. 2017
 *      Author: Valentin
 */

#include "MapParser.h"
#include "tinyxml2.h"
#include "Map.h"
#include "Utils.h"
#include <iostream>
#include <string>
#include <stdio.h>

#define MAP_PATH "./Maps/"

bool MapParser::loadMap(std::string name)
{
	// Load and check XML state
	tinyxml2::XMLDocument mapXML;

	tinyxml2::XMLError eResult = mapXML.LoadFile((MAP_PATH + name).c_str());
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		return false;
	}

	tinyxml2::XMLNode* root = mapXML.FirstChild();
	if (root == nullptr)
	{
		return false;
	}

	//Skip first line
	tinyxml2::XMLElement* mapRoot = (tinyxml2::XMLElement*) root->NextSibling();

	//Load data layer
	tinyxml2::XMLElement* layer = mapRoot->FirstChildElement("layer");
	if(!layer)
	{
		return false;
	}

	// Retrieves map size
	int width, height;
	mapRoot->QueryIntAttribute("width", &width);
	mapRoot->QueryIntAttribute("width", &height);
	Map::getMap().initMapBackground(width, height);
	Map::getMap().setMapSize(width, height);

	//Decode map background
	tinyxml2::XMLElement* data = layer->FirstChildElement("data");
	if(!data)
	{
		return false;
	}

	std::string mapData = data->GetText();
	std::vector<string> tokens;
	split(tokens, mapData, ',');

	for(unsigned int i = 0; i < tokens.size(); i++)
	{
		int dataId = atoi(tokens[i].c_str()) - 20;
		char tileId = dataId < 0 ? ' ' : dataId;
		std::cout << tileId;
		if((i + 1) % 80 == 0 && i > 20)
		{
			std::cout << endl;
		}

		Map::getMap().getMapBackground()[i].Attributes = FOREGROUND_INTENSITY | FOREGROUND_RED;
		Map::getMap().getMapBackground()[i].Char.AsciiChar = tileId;
	}

	return true;
}
