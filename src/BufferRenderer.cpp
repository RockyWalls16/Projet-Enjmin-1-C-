/*
 * BufferRenderer.cpp
 *
 *  Created on: 6 oct. 2017
 *      Author: valen
 */
#include <iostream>
#include "BufferRenderer.h"
#include "GameRenderer.h"
#include "utils/Utils.h"

BufferRenderer::BufferRenderer(int width, int height)
{
	buffer = new CHAR_INFO[width * height];
	bufferSize = { (short) width, (short) height};
	bufferCoords = {0, 0};
}

BufferRenderer::~BufferRenderer()
{
	delete (buffer);
}

void BufferRenderer::setCharAt(int x, int y, CHAR_INFO charInfo)
{
	buffer[flatIndex(x, y)] = charInfo;
}

CHAR_INFO& BufferRenderer::getCharAt(int x, int y)
{
	return buffer[flatIndex(x, y)];
}

void BufferRenderer::renderBuffer(int x, int y, int width, int height)
{
	SMALL_RECT bufferRegion = { (short) x, (short) y, (short) (width - 1), (short) (height - 1) };
	WriteConsoleOutput(GameRenderer::getInstance().getConsoleHandle(), buffer, bufferSize, bufferCoords, &bufferRegion);
}

void BufferRenderer::applyBuffer(int dstX, int dstY, int dstW, int dstH, BufferRenderer* subBuffer)
{
	if(dstX > getWidth() || dstY > getHeight() || dstY + dstH < 0)
	{
		return;
	}

	//Check no width height overflow (crop)
	int dstFinalWidth = dstX + dstW < getWidth() ? dstW : getWidth() - dstX;
	int dstFinalHeight = dstY + dstH < getHeight() ? dstH : getHeight() - dstY;

	if(dstX < 0)
	{
		dstFinalWidth += dstX;
	}

	//Same line size : unique copy
	if(getWidth() == subBuffer->getWidth() && getWidth() == dstFinalWidth)
	{
		int dstStartIndex = flatIndex(dstX, dstY < 0 ? 0 : dstY);
		if(dstY < 0)
		{
			dstFinalHeight += dstY;
		}

		memcpy(&buffer[dstStartIndex], &subBuffer->buffer[subBuffer->flatIndex(0, -dstY)], dstFinalWidth * dstFinalHeight * sizeof(CHAR_INFO));
	}
	else // Different line size : line copy
	{
		int i = dstY < 0 ? 0 : dstY;
		int lastRow = dstY + dstFinalHeight;

		for(; i < lastRow; i++)
		{
			memcpy(&buffer[flatIndex(dstX < 0 ? 0 : dstX, i)], &subBuffer->buffer[subBuffer->flatIndex(dstX < 0 ? -dstX : 0, dstY < 0 ? i - dstY : i)], dstFinalWidth * sizeof(CHAR_INFO));
		}
	}
}

int BufferRenderer::flatIndex(int x, int y)
{
	int index = x + y * bufferSize.X;
	return index < 0 || index >= bufferSize.X * bufferSize.Y ? 0 : index;
}
