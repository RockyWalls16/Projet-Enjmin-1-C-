/*
 * Colors.cpp
 *
 *  Created on: 6 oct. 2017
 *      Author: Valentin
 */

#include "utils/Colors.h"

namespace wcolors
{
WORD fgColors[] =
{ WHITE, CYAN, MAGENTA, YELLOW, LIGHT_GRAY, RED, GREEN, BLUE, DARK_YELLOW,
		PURPLE, DARK_CYAN, DARK_GRAY, DARK_GREEN, DARK_BLUE, DARK_RED, BLACK };
WORD bgColors[] =
{ BG_WHITE, BG_CYAN, BG_MAGENTA, BG_YELLOW, BG_LIGHT_GRAY, BG_RED, BG_GREEN,
		BG_BLUE, BG_DARK_YELLOW, BG_PURPLE, BG_DARK_CYAN, BG_DARK_GRAY,
		BG_DARK_GREEN, BG_DARK_BLUE, BG_DARK_RED, BG_BLACK };

WORD getColorAttribute(char foreground, char background)
{
	return foreground | background;
}

WORD addForeground(char foreground)
{
	return foreground;
}

WORD addBackground(char background)
{
	return background;
}

WORD getForegroundColor(CHAR_INFO charInfo)
{
	return charInfo.Attributes & 15;
}

WORD getBackgroundColor(CHAR_INFO charInfo)
{
	return charInfo.Attributes & 240;
}
}
;
