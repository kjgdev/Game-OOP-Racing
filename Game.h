#ifndef _bin_h_
#define _bin_h_

#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include "Constants.h"
#include "Obstacle.h"
#include "Player.h"
#include "Console.h"
#include "Map.h"
#include "Display.h"
#include <time.h>
#include <Windows.h>
#include <Mmsystem.h>
#pragma comment (lib,"winmm.lib")
#include <thread>
using namespace std;

class Game
{
private:
	
	Obstacle **_obstacle;
	Obstacle **_money;
	Map*	_map;
	Draw	_draw;
	bool	_color = true;
	bool	_runGame = true;
	bool	_mode = false;
	bool	**_stTracffic;
	int		_time = 0;
	int		_gameMusic = 0;
	int		_gameRunMusic = 0;
	int		_thread = 0;
public:
	Player	_player;
	Game();
	~Game();
	void	DrawGame();
	void	PrintConsole(bool);
	void	InitObstacle();
	void	InitMap(int);
	Status	KeyGame(int);
	void	ProcessKey(int z);
	void	ResetGame();
	bool	ExitGame();
	void	LoadGame();
	void	SettingsGame();
	void	PauseGame();
	void	SaveGame();
	bool	WinGame();
	void	CloseGame();
	void	RunGame();
	void	UpdatePosObstacle();
	void	ThreadInit();
	void	ThreadMenu();
	bool	GetRunGame();
	int		GetNumberThread();
	void	DrawLights(bool st, int x, int y);
	void	ProcessTrafficLigths();
	void	ThreadMusic();
	void	ThreadDraw();
	void	ThreadRunGame();
	void DrawLoadGame();
};

#endif