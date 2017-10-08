/*
 * GUI.h
 *
 *  Created on: 7 oct. 2017
 *      Author: valen
 */

#ifndef INCLUDE_GUI_GUI_H_
#define INCLUDE_GUI_GUI_H_

#include "BufferRenderer.h"

class GUI
{
public:
	virtual ~GUI();
	virtual void renderGUI(BufferRenderer* renderBuffer) {};
	void open();
	void close();
};

#endif /* INCLUDE_GUI_GUI_H_ */
