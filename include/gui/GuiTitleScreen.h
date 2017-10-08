/*
 * GuiTitleScreen.h
 *
 *  Created on: 8 oct. 2017
 *      Author: valen
 */

#ifndef INCLUDE_GUI_GUITITLESCREEN_H_
#define INCLUDE_GUI_GUITITLESCREEN_H_

#include <gui/GUI.h>

class GuiTitleScreen: public GUI
{
private:
	BufferRenderer* titleBuffer;
	float timer;
	int playerChoice;

public:
	GuiTitleScreen();
	virtual ~GuiTitleScreen();
	virtual void renderGUI(BufferRenderer* renderBuffer) override;

};

#endif /* INCLUDE_GUI_GUITITLESCREEN_H_ */
