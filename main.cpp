#include "Game.h"
Point Maps[MAX_Y - MIN_Y + 1][MAX_X - MIN_X + 1];
Game game;
Draw draw;
void SubThread()
{
	while(1)
		game.ThreadMusic();
}
void main()
{
	game.ThreadInit();
	thread t1(SubThread);
	
	while (1)
	{
		switch (game.GetNumberThread())
		{
		case 0:
		{
			game.ThreadMenu();
			t1.native_handle();
			break;
		}
		case 1:
		{
			game.ThreadRunGame();
			t1.native_handle();
			break;
		}
		case 2:
		{
			game.LoadGame();
			break;
		}
		case 3:
		{
			game.SettingsGame();
			break;
		}
		}
	}
}