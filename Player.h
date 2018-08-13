#ifndef _Player_h_
#define _Player_h_

#include <iostream>
#include <string>
#include <fstream>
#include "Constants.h"
#include "Display.h"
using namespace std;

extern Point Maps[MAX_Y - MIN_Y + 1][MAX_X - MIN_X + 1];
class Player
{
private:
	char	_char;
	int		_color;
	Oxy		_run;
	Oxy		_save;
	int		_lv;
	int		_score;
public:
	Player();
	Player(char c, int color, int x, int y);
	void	Move(Status);
	void	Move2();
	void	SetFile(fstream &);
	void	GetFile(fstream &);
	void	Display();
	void	ResetPlayer();
	int		GetScore();
	int		GetLV();
	int		GetRun_X();
	int		GetRun_Y();
	Oxy		GetRunPlayer();
	void	SetLV(int);
	void	SetScore(int);
	void	SetRun(int,int);
	~Player();
};

#endif