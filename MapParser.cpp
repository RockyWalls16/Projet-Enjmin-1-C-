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
#include <algorithm>

#define MAP_PATH "./Maps/"
#define TILE_OFFSET 20

std::map<std::string, WORD> MapParser::objectColorTypes;

bool MapParser::loadMap(std::string name)
{
	std::cout << "Loading map...";

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
	int mapWidth, mapHeight;
	mapRoot->QueryIntAttribute("width", &mapWidth);
	mapRoot->QueryIntAttribute("height", &mapHeight);
	Map::getMap().initMapBackground(mapWidth, mapHeight);
	Map::getMap().setMapSize(mapWidth, mapHeight);

	//Decode map background
	tinyxml2::XMLElement* data = layer->FirstChildElement("data");
	if(!data)
	{
		return false;
	}

	std::vector<int> tiles;
	csvAsTileVector(data->GetText(), tiles);

	for(unsigned int i = 0; i < tiles.size(); i++)
	{
		int dataId = tiles[i];
		char tileId = dataId < 0 ? ' ' : dataId;

		Map::getMap().getMapBackground()[i].Attributes = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN;
		Map::getMap().getMapBackground()[i].Char.AsciiChar = tileId;
	}

	// Read objects layers
	tinyxml2::XMLElement* objectLayers = mapRoot->FirstChildElement("objectgroup");
	while(objectLayers != nullptr)
	{

		// Read objects inside layers
		tinyxml2::XMLElement* objects = objectLayers->FirstChildElement("object");
		while(objects != nullptr)
		{
			// Fetch object type
			const char* type = objects->Attribute("type");

			// Fetch object position
			int xPos = 0, yPos = 0, width = 0, height = 0;

			objects->QueryIntAttribute("x", &xPos);
			objects->QueryIntAttribute("y", &yPos);
			objects->QueryIntAttribute("width", &width);
			objects->QueryIntAttribute("height", &height);

			//Convert pixel position to tile position
			xPos /= 8;
			yPos /= 16;
			width /= 8;
			height /= 16;

			WORD objectAttribute;
			std::vector<int> filters;

			// If object is color
			if(type && objectColorTypes.find(type) != objectColorTypes.end())
			{
				objectAttribute = objectColorTypes[type];
			}

			//Object contains custom properties ?
			tinyxml2::XMLElement* customProperties = objects->FirstChildElement("properties");
			if(customProperties)
			{
				tinyxml2::XMLElement* customProperty = customProperties->FirstChildElement("property");

				while(customProperty != nullptr)
				{
					const char* propertyName = customProperty->Attribute("name");
					const char* propertyType = customProperty->Attribute("type");

					//Is string property
					if(!propertyType)
					{
						//Is filter
						if(strcmp(propertyName, "filter") == 0)
						{
							csvAsTileVector(customProperty->Attribute("value"), filters);
						}

					}//Is boolean property ?
					else if(strcmp(propertyType, "bool") == 0)
					{
						bool value = false;
						customProperty->QueryBoolAttribute("value", &value);
						applyColorForProperty(propertyName, objectAttribute, !value);
					}

					// Next property
					customProperty = customProperty->NextSiblingElement("property");
				}
			}


			// Apply color changes
			for(int x = xPos; x < xPos + width; x++)
			{
				for(int y = yPos; y < yPos + height; y++)
				{
					int tile = tiles[x + y * mapWidth] - 1;

					// Check filter is not set or if is set and contains correct tile
					if(filters.size() == 0 || std::find(filters.begin(), filters.end(), tile) != filters.end())
					{
						Map::getMap().getMapBackground()[Map::getMap().getBufferFlatIndex(x, y)].Attributes = objectAttribute;
					}
				}
			}

			// Next object
			objects = objects->NextSiblingElement("object");
		}

		// Next object layer
		objectLayers = objectLayers->NextSiblingElement("objectgroup");
	}

	std::cout << "DONE" << std::endl;

	return true;
}

bool MapParser::loadColorObjectTypes()
{
	std::cout << "Loading colors...";

	// Load and check XML state
	tinyxml2::XMLDocument objTypesXML;

	tinyxml2::XMLError eResult = objTypesXML.LoadFile((MAP_PATH + std::string("objecttypes.xml")).c_str());
	if (eResult != tinyxml2::XML_SUCCESS)
	{
		return false;
	}

	tinyxml2::XMLNode* root = objTypesXML.FirstChild();
	if (root == nullptr)
	{
		return false;
	}

	//Skip first line
	tinyxml2::XMLElement* objectsRoot = (tinyxml2::XMLElement*) root->NextSibling();

	// Read all objects
	tinyxml2::XMLElement* objects = objectsRoot->FirstChildElement("objecttype");
	while(objects != nullptr)
	{

		// Read object properties
		WORD attribute = 0;
		const char* objectName = objects->Attribute("name");
		tinyxml2::XMLElement* properties = objects->FirstChildElement("property");


		while(properties != nullptr)
		{
			const char* propertyName = properties->Attribute("name");
			bool value = false;
			properties->QueryBoolAttribute("default", &value);

			if(value)
			{
				applyColorForProperty(propertyName, attribute);
			}

			// Next property
			properties = properties->NextSiblingElement("property");
		}

		// Add object type to object type list
		objectColorTypes[objectName] = attribute;

		// Next object
		objects = objects->NextSiblingElement("objecttype");
	}

	std::cout << "DONE" << std::endl;

	return true;
}

bool MapParser::applyColorForProperty(const char* propertyName, WORD& attribute, bool removeProperty)
{
	if(strcmp(propertyName, "background-intense") == 0)
	{
		attribute = removeProperty ? attribute & ~BACKGROUND_INTENSITY : attribute | BACKGROUND_INTENSITY;
	}
	else if(strcmp(propertyName, "background-red") == 0)
	{
		attribute = removeProperty ? attribute & ~BACKGROUND_RED : attribute | BACKGROUND_RED;
	}
	else if(strcmp(propertyName, "background-green") == 0)
	{
		attribute = removeProperty ? attribute & ~BACKGROUND_GREEN : attribute | BACKGROUND_GREEN;
	}
	else if(strcmp(propertyName, "background-blue") == 0)
	{
		attribute = removeProperty ? attribute & ~BACKGROUND_BLUE : attribute | BACKGROUND_BLUE;
	}
	else if(strcmp(propertyName, "intense") == 0)
	{
		attribute = removeProperty ? attribute & ~FOREGROUND_INTENSITY : attribute | FOREGROUND_INTENSITY;
	}
	else if(strcmp(propertyName, "red") == 0)
	{
		attribute = removeProperty ? attribute & ~FOREGROUND_RED : attribute | FOREGROUND_RED;
	}
	else if(strcmp(propertyName, "green") == 0)
	{
		attribute = removeProperty ? attribute & ~FOREGROUND_GREEN : attribute | FOREGROUND_GREEN;
	}
	else if(strcmp(propertyName, "blue") == 0)
	{
		attribute = removeProperty ? attribute & ~FOREGROUND_BLUE : attribute | FOREGROUND_BLUE;
	}
	else
	{
		return false;
	}

	return true;
}

void MapParser::csvAsTileVector(std::string csvData, std::vector<int>& output)
{
	std::vector<string> tokens;
	split(tokens, csvData, ',');
	output.reserve(tokens.size());

	for(unsigned int i = 0; i < tokens.size(); i++)
	{
		int dataId = atoi(tokens[i].c_str()) - TILE_OFFSET;
		output.push_back(dataId);
	}

}
