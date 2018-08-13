#ifndef _Obstacle_h_
#define _Obstacle_h_

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "Constants.h"
#include "Player.h"
using namespace std;

class Vehicle
{
private:
	Oxy		_run;
	Oxy		_start;
	Oxy		_finish;
	bool	_direction;
	int		_step_x;
	int		_step_y;
	friend	class Player;
public:
	Vehicle();
	void	InitVehicle(int run_x, int run_y);
	void	SettingVehicle
		(int start_x, int start_y,int finish_x, int finish_y, int distance,
		 bool direction, int step_x, int step_y);
	bool	Move(Oxy runPlayer);
	bool	Move1(Player _player, Oxy &runPlayer);
	void	SetFile(fstream &);
	void	GetFile(fstream &);
	int		GetRun_x();
	int		GetRun_y();
	void	deleteOb();
	~Vehicle();
};

class Car : public Vehicle
{
private:
	int		_color;
	char	_char;
public:
	Car();
	void	CopyAttributes(Car);
	void	InitCar(int run_x,int run_y, char c, int color);
	void	SettingCar
		(int start_x, int start_y,int finish_x, int finish_y, int distance,
			bool direction,	int step_x, int step_y,int color);
	bool	Move(Oxy runPlayer);
	bool	Move1(Player _player, Oxy &runPlayer);
	Oxy		GetPointRun();
	void	Display();
	void	DisplayOutMap();
	void	deleteOb();
};

class Obstacle
{
private:
	Car**	_obstacle;
	int		_countChar;
public:
	Obstacle();
	~Obstacle();
	void	GetFile(string Path, int amountObstacle);
	bool	GetMove(int amountObstacle,Oxy runPlayer);
	void	GetMove1(int amountObstacle,Oxy runPlayer);
	bool	GetMove2(int amountObstacle, Player _player, Oxy &runPlayer);
	Car*	GetObstacle(int amountObstacle);
	int		GetCountChar();
	void	SettingObstacle(int start_x, int start_y, int finish_x, int finish_y, bool direction, int step_x, int step_y,int sumObstacle,int color);
	void	Display(int amountObstacle);
	void	DisplayOutMap();
	void	SetFileSave(int amountObstacle, fstream &);
	void	GetFileSave(int amountObstacle, fstream &);
	void	deleteOb();
};

#endif