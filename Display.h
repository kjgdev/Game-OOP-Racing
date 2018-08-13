#ifndef _Display_h_
#define _Display_h_

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "Constants.h"
#include "Console.h"
#include "Obstacle.h"
using namespace std;

extern Point Maps[MAX_Y - MIN_Y + 1][MAX_X - MIN_X + 1];
void DrawABox(char c, int color, int x, int y);
void drawABoxOutMap(char c, int color, int x, int y);
class Obstacle;
class Draw
{
private:
	Obstacle * ob;
	int _temp;
public:
	Draw();
	~Draw();
	void DrawInfo();
	void deleteFramesSL();
	void drawFramesSL();
	void drawFramesLoadSave();
	void deleteFramesLoadSave();
	void drawYesNo();
	void deleteYesNo();
	void drawMenu();
	void ProcessMenu();
	void drawFrameMenu();
	int GetTemp();
	void SetTemp(int temp);
	void DrawSettings();
};
#endif