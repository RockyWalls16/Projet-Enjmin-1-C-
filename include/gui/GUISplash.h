/*
 * GUISplash.h
 *
 *  Created on: 7 oct. 2017
 *      Author: valen
 */

#ifndef INCLUDE_GUI_GUISPLASH_H_
#define INCLUDE_GUI_GUISPLASH_H_

#include "gui/GUI.h"
class BufferRenderer;

class GUISplash : public GUI
{
private:
	BufferRenderer* logo;
	double animationTime;

public:
	GUISplash();
	virtual ~GUISplash();
	virtual void renderGUI(BufferRenderer* renderBuffer) override;
};

#endif /* INCLUDE_GUI_GUISPLASH_H_ */
