/*
 * GameRenderer.h
 *
 *  Created on: 6 oct. 2017
 *      Author: valen
 */

#ifndef INCLUDE_GAMERENDERER_H_
#define INCLUDE_GAMERENDERER_H_

#include <windows.h>
#include "BufferRenderer.h"

class GameRenderer
{
private:
	HANDLE consoleHandle;
	BufferRenderer* renderBuffer;
	BufferRenderer* backgroundBuffer;
	BufferRenderer* emptyBuffer;

public:
	GameRenderer();

	void renderGame();

	void initRenderBuffer(int width, int height);

	void replaceBackgroundBuffer(BufferRenderer* newBackground);

	HANDLE getConsoleHandle() const
	{
		return consoleHandle;
	}

	static GameRenderer& getInstance();
};

#endif /* INCLUDE_GAMERENDERER_H_ */
