/*
 * BufferRenderer.h
 *
 *  Created on: 6 oct. 2017
 *      Author: valen
 */

#ifndef INCLUDE_BUFFERRENDERER_H_
#define INCLUDE_BUFFERRENDERER_H_

#include <windows.h>

class BufferRenderer
{
private:
	CHAR_INFO* buffer;
	COORD bufferSize;
	COORD bufferCoords;

public:
	BufferRenderer(int width, int height);
	virtual ~BufferRenderer();

	void setCharAt(int x, int y, CHAR_INFO charInfo);
	CHAR_INFO& getCharAt(int x, int y);

	void renderBuffer(int x, int y, int width, int height);

	void applyBuffer(int dstX, int dstY, int dstW, int dstH, BufferRenderer* subBuffer);

	int getWidth() const
	{
		return bufferSize.X;
	}

	int getHeight() const
	{
		return bufferSize.Y;
	}

	CHAR_INFO* getBuffer() const
	{
		return buffer;
	}

private:
	int flatIndex(int x, int y);
};

#endif /* INCLUDE_BUFFERRENDERER_H_ */
