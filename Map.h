#ifndef _Map_h_
#define _Map_h_

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "Constants.h"
#include "Display.h"
extern Point Maps[MAX_Y - MIN_Y + 1][MAX_X - MIN_X + 1];
class Map
{
public:
	Map();
	void	SetFile(string);
};
#endif
