#include "Game.h"

Game::Game()
{
	_obstacle = new Obstacle*[11];
	for (int i = 0; i < 11; ++i)
	{
		_obstacle[i] = new Obstacle[11];
	}
	_map = new Map[PLAYER_MAXLV];
	_stTracffic = new bool*[10];
	for (int i = 0; i < 10; ++i)
	{
		_stTracffic[i] = new bool[10];
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			_stTracffic[i][j] = true;
		}
	}
	_money = new Obstacle*[11];
	for (int i = 0; i < 11; ++i)
	{
		_money[i] = new Obstacle[11];
	}
}

Game::~Game()
{
	delete[]_obstacle;
	delete[]_map;
	delete[]_stTracffic;
}

void Game::DrawGame()
{
	switch (_player.GetLV())
	{
	case 1:
	{
		for (int i = 0; i < sumLanes_1; ++i)
		{
			_obstacle[0][i].Display(sumObstacle_1);
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < sumLanes_2; ++i)
		{
			_obstacle[1][i].Display(sumObstacle_2);
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < sumLanes_3; ++i)
		{
			_obstacle[2][i].Display(sumObstacle_3);
		}
		break;
	}
	case 4: {
		for (int i = 0; i < sumLanes_4; ++i)
		{
			_obstacle[3][i].Display(sumObstacle_4);
		}
		break;
	}
	case 5:
	{
		for (int i = 0; i < sumLanes_5; ++i)
		{
			_obstacle[4][i].Display(sumObstacle_5);
		}
		break;
	}
	case 6:
	{
		for (int i = 0; i < sumLanes_6; ++i)
		{
			_obstacle[5][i].Display(sumObstacle_6);
		}
		break;
	}
	case 7: {
		for (int i = 0; i < sumLanes_7; ++i)
		{
			_obstacle[6][i].Display(sumObstacle_7);
		}
		break;
	}
	case 8:
	{
		for (int i = 0; i < sumLanes_8; ++i)
		{
			_obstacle[7][i].Display(sumObstacle_8);
		}
		break;
	}
	case 9:
	{
		for (int i = 0; i < sumLanes_9; ++i)
		{
			_obstacle[8][i].Display(sumObstacle_9);
		}
		break;
	}
	case 10:
	{
		for (int i = 0; i < sumLanes_10; ++i)
		{
			_obstacle[9][i].Display(sumObstacle_10);
		}
		break;
	}
	}
	for (int i = 0; i < 5; i++)
	{
		_money[_player.GetLV() - 1][i].Display(1);
	}
	_player.Display();
}

void Game::PrintConsole(bool color)
{
	gotoXY(0, 0);
	if (color == false) {

		TextColor(7);
		for (int i = 0; i < MAX_Y - MIN_Y + 1; ++i)
		{
			gotoXY(0, i);
			char s[MAX_X - MIN_X + 1];
			for (int j = 0; j < MAX_X - MIN_X + 1; ++j)
			{
				Maps[i][j]._char = ' ';
			}
			printf_s("%s", s);
		}
	}
	else {
		for (int i = 0; i < MAX_Y - MIN_Y + 1; ++i)
		{
			for (int j = 0; j < MAX_X - MIN_X + 1; ++j)
			{
				TextColor(Maps[i][j]._color);
				putchar(Maps[i][j]._char);
				Maps[i][j]._char = ' ';
				Maps[i][j]._color = 0;
			}
			if (i < MAX_X) putchar('\n');
		}
	}
}

void Game::InitObstacle()
{
	//--------------- Initalize Obstacle Lv 1 ----------------------------
	for (int i = 0; i < sumLanes_1; ++i)
	{
		// Read file text path intalize obstacle map lv 1
		_obstacle[0][i].GetFile(PATH_OBSTACLE_MAP_1[i], sumObstacle_1);
	}

	for (int i = 0; i < sumLanes_1; ++i)
	{
		if (i % 2 == 0)
			_obstacle[0][i].SettingObstacle(MIN_X + 4, 11 + i * 5, MAX_X - 2, 11 + i * 5, true, 1, 0, sumObstacle_1, color_obstacle_map_1[i]);
		else
			_obstacle[0][i].SettingObstacle(MIN_X + 4, 11 + i * 5, MAX_X - 2, 11 + i * 5, false, 1, 0, sumObstacle_1, color_obstacle_map_1[i]);
	}

	//--------------- Initalize Obstacle Lv 2 ----------------------------
	for (int i = 0; i < sumLanes_2; ++i)
	{
		// Read file text path intalize obstacle map lv 2
		_obstacle[1][i].GetFile(PATH_OBSTACLE_MAP_2[i], sumObstacle_2);
	}

	for (int i = 0; i < sumLanes_2; ++i)
	{
		if (i % 2 == 0)
			_obstacle[1][i].SettingObstacle(MIN_X + 4, 12 + i * 4, MAX_X - 2, 12 + i * 4, true, 1, 0, sumObstacle_2, color_obstacle_map_2[i]);
		else
			_obstacle[1][i].SettingObstacle(MIN_X + 4, 12 + i * 4, MAX_X - 2, 12 + i * 4, false, 1, 0, sumObstacle_2, color_obstacle_map_2[i]);
	}


	//--------------- Initalize Obstacle Lv 3 ----------------------------
	for (int i = 0; i < sumLanes_3; ++i)
	{
		// Read file text path intalize obstacle map lv 3
		_obstacle[2][i].GetFile(PATH_OBSTACLE_MAP_3[i], sumObstacle_3);
	}

	for (int i = 0; i < sumLanes_3 - 2; ++i)
	{
		if (i % 2 == 0)
			_obstacle[2][i].SettingObstacle(MIN_X + 4, 5 + i * 4, MAX_X - 2, 5 + i * 4, true, 1, 0, sumObstacle_3, color_obstacle_map_3[i]);
		else
			_obstacle[2][i].SettingObstacle(MIN_X + 4, 5 + i * 4, MAX_X - 2, 5 + i * 4, false, 1, 0, sumObstacle_3, color_obstacle_map_3[i]);
	}
	for (int i = sumLanes_3 - 2; i < sumLanes_3; ++i)
	{
		if (i % 2 == 0)
			_obstacle[2][i].SettingObstacle(MIN_X + 4, 8 + i * 4, MAX_X - 2, 8 + i * 4, true, 1, 0, sumObstacle_3, color_obstacle_map_3[i]);
		else
			_obstacle[2][i].SettingObstacle(MIN_X + 4, 8 + i * 4, MAX_X - 2, 8 + i * 4, false, 1, 0, sumObstacle_3, color_obstacle_map_3[i]);
	}
	//--------------- Initalize Obstacle Lv 4 ----------------------------
	for (int i = 0; i < sumLanes_4; ++i)
	{
		// Read file text path intalize obstacle map lv 4
		_obstacle[3][i].GetFile(PATH_OBSTACLE_MAP_4[i], sumObstacle_4);
	}

	for (int i = 0; i < sumLanes_4; ++i)
	{
		if (i % 2 == 0)
			_obstacle[3][i].SettingObstacle(MIN_X + 4, 10 + i * 5, MAX_X - 2, 10 + i * 5, true, 1, 0, sumObstacle_4, color_obstacle_map_4[i]);
		else
			_obstacle[3][i].SettingObstacle(MIN_X + 4, 10 + i * 5, MAX_X - 2, 10 + i * 5, false, 1, 0, sumObstacle_4, color_obstacle_map_4[i]);
	}
	//--------------- Initalize Obstacle Lv 5 ----------------------------
	for (int i = 0; i < sumLanes_5; ++i)
	{
		// Read file text path intalize obstacle map lv 5
		_obstacle[4][i].GetFile(PATH_OBSTACLE_MAP_5[i], sumObstacle_5);
	}

	for (int i = 0; i < sumLanes_5 - 2; ++i)
	{
		if (i % 2 == 0)
			_obstacle[4][i].SettingObstacle(MIN_X + 4, 8 + i * 3, MAX_X - 2, 8 + i * 3, true, 1, 0, sumObstacle_5, color_obstacle_map_5[i]);
		else
			_obstacle[4][i].SettingObstacle(MIN_X + 4, 8 + i * 3, MAX_X - 2, 8 + i * 3, false, 1, 0, sumObstacle_5, color_obstacle_map_5[i]);
	}
	for (int i = sumLanes_5 - 2; i < sumLanes_5; ++i)
	{
		if (i % 2 == 0)
			_obstacle[4][i].SettingObstacle(MIN_X + 4, 8 + i * 3 + 2, MAX_X - 2, 8 + i * 3 + 2, true, 1, 0, sumObstacle_5, color_obstacle_map_5[i]);
		else
			_obstacle[4][i].SettingObstacle(MIN_X + 4, 8 + i * 3 + 2, MAX_X - 2, 8 + i * 3 + 2, false, 1, 0, sumObstacle_5, color_obstacle_map_5[i]);
	}
	//--------------- Initalize Obstacle Lv 6 ----------------------------
	for (int i = 0; i < sumLanes_6; ++i)
	{
		// Read file text path intalize obstacle map lv 6
		_obstacle[5][i].GetFile(PATH_OBSTACLE_MAP_6[i], sumObstacle_6);
	}

	for (int i = 0; i < sumLanes_6; ++i)
	{
		if (i % 2 == 0)
			_obstacle[5][i].SettingObstacle(MIN_X + 4, 7 + i * 4, MAX_X - 2, 7 + i * 4, true, 1, 0, sumObstacle_6, color_obstacle_map_6[i]);
		else
			_obstacle[5][i].SettingObstacle(MIN_X + 4, 7 + i * 4, MAX_X - 2, 7 + i * 4, false, 1, 0, sumObstacle_6, color_obstacle_map_6[i]);
	}

	//--------------- Initalize Obstacle Lv 7 ----------------------------
	for (int i = 0; i < sumLanes_7; ++i)
	{
		// Read file text path intalize obstacle map lv 7
		_obstacle[6][i].GetFile(PATH_OBSTACLE_MAP_7[i], sumObstacle_7);
	}

	for (int i = 0; i < sumLanes_7; ++i)
	{
		if (i % 2 == 0)
			_obstacle[6][i].SettingObstacle(MIN_X + 4, 7 + i * 4, MAX_X - 2, 7 + i * 4, true, 1, 0, sumObstacle_7, color_obstacle_map_7[i]);
		else
			_obstacle[6][i].SettingObstacle(MIN_X + 4, 7 + i * 4, MAX_X - 2, 7 + i * 4, false, 1, 0, sumObstacle_7, color_obstacle_map_7[i]);
	}
	//--------------- Initalize Obstacle Lv 8 ----------------------------
	for (int i = 0; i < sumLanes_8; ++i)
	{
		// Read file text path intalize obstacle map lv 8
		_obstacle[7][i].GetFile(PATH_OBSTACLE_MAP_8[i], sumObstacle_8);
	}

	for (int i = 0; i < sumLanes_8; ++i)
	{
		if (i % 2 == 0)
			_obstacle[7][i].SettingObstacle(MIN_X + 4, 6 + i * 4, MAX_X - 2, 6 + i * 4, true, 1, 0, sumObstacle_8, color_obstacle_map_8[i]);
		else
			_obstacle[7][i].SettingObstacle(MIN_X + 4, 6 + i * 4, MAX_X - 2, 6 + i * 4, false, 1, 0, sumObstacle_8, color_obstacle_map_8[i]);
	}

	//--------------- Initalize Obstacle Lv 9 ----------------------------
	for (int i = 0; i < sumLanes_9; ++i)
	{
		// Read file text path intalize obstacle map lv 9
		_obstacle[8][i].GetFile(PATH_OBSTACLE_MAP_9[i], sumObstacle_5);
	}

	_obstacle[8][0].SettingObstacle(MIN_X + 4, 11, MAX_X - 2, 11, true, 1, 0, sumObstacle_9, color_obstacle_map_9[0]);
	_obstacle[8][1].SettingObstacle(MIN_X + 4, 14, MAX_X - 2, 14, false, 1, 0, sumObstacle_9, color_obstacle_map_9[1]);
	_obstacle[8][2].SettingObstacle(MIN_X + 4, 20, MAX_X - 2, 20, true, 1, 0, sumObstacle_9, color_obstacle_map_9[2]);

	//--------------- Initalize Obstacle Lv 10 ----------------------------
	for (int i = 0; i < sumLanes_10; ++i)
	{
		// Read file text path intalize obstacle map lv 10
		_obstacle[9][i].GetFile(PATH_OBSTACLE_MAP_10[i], sumObstacle_10);
	}

	for (int i = 0; i < sumLanes_10; ++i)
	{
		if (i % 2 == 0)
			_obstacle[9][i].SettingObstacle(MIN_X + 4, 10 + i * 5, MAX_X - 2, 10 + i * 5, true, 1, 0, sumObstacle_10, color_obstacle_map_10[i]);
		else
			_obstacle[9][i].SettingObstacle(MIN_X + 4, 10 + i * 5, MAX_X - 2, 10 + i * 5, false, 1, 0, sumObstacle_10, color_obstacle_map_10[i]);
	}
	// ------------------------------------------------
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++) {
			_money[i][j].GetFile("dola.txt", 1);
			int x = 2 + rand() % (98 - 2 + 1);
			int y = 2 + rand() % (28 - 2 + 1);

			_money[i][j].SettingObstacle(x, y, x, y, 1, 0, 0, 1, 14);
		}
	}
}

void Game::InitMap(int lv)
{
	for (int i = 0; i < MAX_Y - MIN_Y + 1; ++i)
	{
		for (int j = 0; j < MAX_X - MIN_X + 1; ++j)
		{
			Maps[i][j]._st = false;
		}
	}
	_map[lv - 1].SetFile(PATH_MAP[lv - 1]);
}

Status Game::KeyGame(int x)
{
	switch (x)
	{
	case 'l':case 'L': { _gameRunMusic = 1; return SAVEGAME; }
	case 't':case 'T': { _gameRunMusic = 1; return LOADGAME; }
	case 'p': { _gameRunMusic = 1; return PAUSEGAME; }
	case 13: { _gameRunMusic = 1; return ENTER; }
	case 'y':case 'Y': { _gameRunMusic = 1; return YES; }
	case 'n':case 'N': { _gameRunMusic = 1; return NO; }
	case '8': {_mode = true; TextColor(4); gotoXY(120, 5); cout << "CHECK"; break; }
	case '9': {_mode = false; gotoXY(120,5); cout << "     "; break; }
	case '3': return NEXTLV;
	case '4':return PRE;
	case '1':return ON;
	case '2':return OFF;
	case 27: return ESC;
	}
	return EXIT;
}

void Game::ProcessKey(int z)
{
	switch (KeyGame(z))
	{
		//case UP:case DOWN: case LEFT:case RIGHT: { _player.Move(KeyGame(z)); break; }
	case LOADGAME: { LoadGame(); break; }
	case PAUSEGAME: { PauseGame(); break; }
	case SAVEGAME: { SaveGame(); break; }
	case NEXTLV: {_player.SetLV(_player.GetLV() + 1); break; }
	case PRE: {_player.SetLV(_player.GetLV() - 1); break; }
	case ESC: 
	{	
		if (_thread == 0)
		{
			exit(0);
			break; 
		}
		_thread = 0;
		_gameRunMusic = 0; 
		ThreadInit();
		_player.ResetPlayer();
		break; 
	}
	case ON:
	{
		_gameMusic = 1;
		_gameRunMusic = 0;
		TextColor(10);
		gotoXY(114, 5);
		cout << "ON "; 
		break; 
	}
	case OFF:
	{
		_gameMusic = 10;
		TextColor(10);
		gotoXY(114, 5);
		cout << "OFF";
		break;
	}
	}
}

void Game::ResetGame()
{
	_player.SetLV(1);
	_player.ResetPlayer();
	_draw.SetTemp(0);
	_runGame = true;
	_gameRunMusic = 0;
}

bool Game::ExitGame()
{
	if (_kbhit())
	{
		int z = _getch();
		if (z == 27) {
			_gameRunMusic = 0;
			return false;
		}
	}
	return true;
}

void Game::LoadGame()
{
et1:
	_draw.drawFramesSL();
	_draw.drawFramesLoadSave();
	TextColor(11);
	gotoXY(8, 32);
	cout << "LOAD GAME";
	gotoXY(21, 32);
	cout << "Path: ";
	gotoXY(26, 32);
	TextColor(15);
	string Path;
	getline(cin, Path);
	fstream inFile;
	inFile.open(Path, ios::in);
	if (inFile.fail())
	{
		TextColor(4);
		gotoXY(26, 32);
		cout << "!! Warning: Can't find file save, Retype ? !!";
		_draw.drawYesNo();
		int z;
		while (1) {
			_kbhit();
			z = _getch();
			if (z == 121 || z == 89)
			{
				goto et1;
			}
			if (z == 110 || z == 78)
			{
				goto et;
				break;
			}
		}
	}
	else
	{
		TextColor(4);
		gotoXY(26, 32);
		cout << "!! Complete !!";
		gotoXY(114, 3);
		cout << _player.GetLV();
	}
	_player.SetFile(inFile);
	switch (_player.GetLV())
	{
	case 1:
	{
		for (int i = 0; i < sumLanes_1; ++i)
		{
			_obstacle[0][i].SetFileSave(sumObstacle_1, inFile);
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < sumLanes_2; ++i)
		{
			_obstacle[1][i].SetFileSave(sumObstacle_2, inFile);
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < sumLanes_3; ++i)
		{
			_obstacle[2][i].SetFileSave(sumObstacle_3, inFile);
		}
		break;
	}
	case 4:
	{
		for (int i = 0; i < sumLanes_4; ++i)
		{
			_obstacle[3][i].SetFileSave(sumObstacle_4, inFile);
		}
		break;
	}
	case 5:
	{
		for (int i = 0; i < sumLanes_5; ++i)
		{
			_obstacle[4][i].SetFileSave(sumObstacle_5, inFile);
		}
		break;
	}
	case 6:
	{
		for (int i = 0; i < sumLanes_6; ++i)
		{
			_obstacle[5][i].SetFileSave(sumObstacle_6, inFile);
		}
		break;
	}
	case 7:
	{
		for (int i = 0; i < sumLanes_7; ++i)
		{
			_obstacle[6][i].SetFileSave(sumObstacle_7, inFile);
		}
		break;
	}
	case 8:
	{
		for (int i = 0; i < sumLanes_8; ++i)
		{
			_obstacle[7][i].SetFileSave(sumObstacle_8, inFile);
		}
		break;
	}
	case 9:
	{
		for (int i = 0; i < sumLanes_9; ++i)
		{
			_obstacle[8][i].SetFileSave(sumObstacle_9, inFile);
		}
		break;
	}
	case 10:
	{
		for (int i = 0; i < sumLanes_10; ++i)
		{
			_obstacle[9][i].SetFileSave(sumObstacle_10, inFile);
		}
		break;
	}
	}
	_draw.drawYesNo();
	int z;
	while (1) {
		_kbhit();
		z = _getch();
		if (z == 121 || z == 89)
		{
			break;
		}
		if (z == 110 || z == 78)
		{
			goto et;
		}
	}
et:
	_draw.deleteFramesSL();
	_draw.deleteYesNo();
	_draw.deleteFramesLoadSave();
	_thread = 0;
}

void Game::SettingsGame()
{
	_draw.DrawSettings();
	while (1)
	{
		_kbhit();
		int z = _getch();
		if (z == '2')
		{
			_gameMusic = 10;
			break;
		}
		else if (z == '1')
		{
			_gameMusic = 1;
			_gameRunMusic = 0;
			ThreadMusic();
			break;

		}
	}

	_thread = 0;
	clrscr();
	_draw.DrawInfo();
	TextColor(10);
	if (_gameMusic != 10)
	{
		gotoXY(114, 5);
		cout << "ON";
	}
	else
	{
		gotoXY(114, 5);
		cout << "OFF";
	}
}

void Game::PauseGame()
{
	_draw.drawFramesSL();
	TextColor(12);
	gotoXY(27, 32);
	cout << "!! Do you want to continue? Yes(Y) or No(N) !!";
	_draw.drawYesNo();
	int z;
	while (1) {
		if (_kbhit()) {
			z = _getch();
			if (z == 121 || z == 89)
			{
				break;
			}
			else if (z == 110 || z == 78)
			{
				SaveGame();
				ResetGame();
				_thread = 0;
				break;
			}
		}
	}
	_draw.deleteFramesSL();
	_draw.deleteYesNo();
}

void Game::SaveGame()
{
et:
	_draw.drawFramesSL();
	_draw.drawFramesLoadSave();
	TextColor(11);
	gotoXY(8, 32);
	cout << "SAVE GAME";
	gotoXY(21, 32);
	cout << "Path: ";
	gotoXY(26, 32);
	TextColor(15);
	string Path;
	getline(cin, Path);
	fstream outFile;
	outFile.open(Path, ios::out);
	_player.GetFile(outFile);
	switch (_player.GetLV())
	{
	case 1:
	{
		for (int i = 0; i < sumLanes_1; ++i)
		{
			_obstacle[0][i].GetFileSave(sumObstacle_1, outFile);
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < sumLanes_2; ++i)
		{
			_obstacle[1][i].GetFileSave(sumObstacle_2, outFile);
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < sumLanes_3; ++i)
		{
			_obstacle[2][i].GetFileSave(sumObstacle_3, outFile);
		}
		break;
	}
	case 4:
	{
		for (int i = 0; i < sumLanes_4; ++i)
		{
			_obstacle[3][i].GetFileSave(sumObstacle_4, outFile);
		}
		break;
	}
	case 5:
	{
		for (int i = 0; i < sumLanes_5; ++i)
		{
			_obstacle[4][i].GetFileSave(sumObstacle_5, outFile);
		}
		break;
	}
	case 6:
	{
		for (int i = 0; i < sumLanes_6; ++i)
		{
			_obstacle[5][i].GetFileSave(sumObstacle_6, outFile);
		}
		break;
	}
	case 7:
	{
		for (int i = 0; i < sumLanes_7; ++i)
		{
			_obstacle[6][i].GetFileSave(sumObstacle_7, outFile);
		}
		break;
	}
	case 8:
	{
		for (int i = 0; i < sumLanes_8; ++i)
		{
			_obstacle[7][i].GetFileSave(sumObstacle_8, outFile);
		}
		break;
	}
	case 9:
	{
		for (int i = 0; i < sumLanes_9; ++i)
		{
			_obstacle[8][i].GetFileSave(sumObstacle_9, outFile);
		}
		break;
	}
	case 10:
	{
		for (int i = 0; i < sumLanes_10; ++i)
		{
			_obstacle[9][i].GetFileSave(sumObstacle_10, outFile);
		}
		break;
	}
	}
	_draw.drawYesNo();
	int z;
	while (1) {
		_kbhit();
		z = _getch();
		if (z == 121 || z == 89)
		{
			break;
		}
		if (z == 110 || z == 78)
		{
			goto et;
		}
	}
	_draw.deleteFramesSL();
	_draw.deleteYesNo();
	_draw.deleteFramesLoadSave();
}

bool Game::WinGame()
{
	for (int i = MIN_X + 35; i <= MIN_X + 65; i++)
		for (int j = 0; j < 3; j++) {
			if (_player.GetRun_X() == i && _player.GetRun_Y() == j)
			{
				if (_player.GetLV() + 1 == 11)
				{
					fstream inFile;
					int c, color, x, y;
					int countChar;
					for (int i = PosGameWin_x - 2; i < PosGameWin_x + 21 * 3 + 2; ++i)
					{
						for (int j = PosGameWin_y - 1; j < PosGameWin_y + 11 + 1; ++j)
						{
							DrawABox(' ', 7, i, j);
						}
					}
					// ------------------- W.txt -----------------------
					inFile.open(PATH_GAMEWIN[0], ios::in);
					inFile >> countChar;
					for (int i = 0; i < countChar; ++i)
					{
						inFile >> c >> color >> x >> y;
						DrawABox(c, Color_GameOver, x + PosGameWin_x, y + PosGameWin_y);
					}
					inFile.close();
					// -------------------- I.txt ----------------------
					inFile.open(PATH_GAMEWIN[1], ios::in);
					inFile >> countChar;
					for (int i = 0; i < countChar; ++i)
					{
						inFile >> c >> color >> x >> y;
						DrawABox(c, Color_GameOver, x + PosGameWin_x + 21, y + PosGameWin_y);
					}
					inFile.close();
					// -------------------- N.txt ----------------------
					inFile.open(PATH_GAMEWIN[2], ios::in);
					inFile >> countChar;
					for (int i = 0; i < countChar; ++i)
					{
						inFile >> c >> color >> x >> y;
						DrawABox(c, Color_GameOver, x + PosGameWin_x + 21 * 2, y + PosGameWin_y);
					}
					inFile.close();
					PrintConsole(color);
					_draw.drawFramesSL();
					TextColor(12);
					gotoXY(27, 32);
					cout << "!! Do you want to continue? Yes(Y) or No(N) !!";

					_draw.drawYesNo();
					int z;
					while (1) {
						if (_kbhit()) {
							z = _getch();
							if (z == 121 || z == 89)
							{
								ResetGame();
								break;
							}
							if (z == 110 || z == 78)
							{
								ResetGame();
								_thread = 0;
								break;
							}
						}
					}
					_draw.deleteFramesSL();
					_draw.deleteYesNo();
				}
				else
				{
					_player.SetLV(_player.GetLV() + 1 == 3 ? 4 : _player.GetLV() + 1);
					_player.ResetPlayer();
					TextColor(4);
					if (_player.GetLV() < 11);
					gotoXY(114, 3);
					cout << _player.GetLV();
					_gameRunMusic = 4;
					Sleep(3000);
				}
				return true;
			}

		}
	return false;
}

void Game::CloseGame()
{
	_obstacle[10][0].GetFile(PATH_OBSTACLE_DEAD[0], 1);
	_obstacle[10][0].SettingObstacle(MIN_X + 1, _player.GetRun_Y(), MAX_X - 2, _player.GetRun_Y(), 1, 2, 0, 1, 7);

	//_obstacle[10][1].SettingObstacle(4, _player.GetRun_Y(), 100, _player.GetRun_Y(), 1, 2, 0, 1, 4);
	int k = 0;
	int d = 4;
	while (k < MAX_X - 10) {
		_obstacle[10][1].GetFile("light.txt", 1);
		if (k % 4 == 0)
			_obstacle[10][1].SettingObstacle(d, _player.GetRun_Y(), 100, _player.GetRun_Y(), 1, 2, 0, 1, 4);
		else
			_obstacle[10][1].SettingObstacle(d, _player.GetRun_Y(), 100, _player.GetRun_Y(), 1, 2, 0, 1, 10);
		InitMap(_player.GetLV());
		DrawGame();
		for (int i = 0; i < 2; i++) {
			_obstacle[10][i].GetMove(1, _player.GetRunPlayer());
			_obstacle[10][i].Display(1);
		}
		PrintConsole(_color);
		k += 2; d += 2;
	}
	DrawGame();
	InitMap(_player.GetLV());
	_draw.drawFramesSL();
	// ------------ game over ------------
	fstream inFile;
	int c, color, x, y;
	int countChar;
	for (int i = PosGameOver_Game_x - 2; i < PosGameOver_Game_x + 21 * 4 + 2; ++i)
	{
		for (int j = PosGameOver_Game_y - 1; j < PosGameOver_Game_y + 11 + 1; ++j)
		{
			DrawABox(' ', 7, i, j);
		}
	}
	for (int i = PosGameOver_Game_x - 2; i < PosGameOver_Game_x + 21 * 4 + 2; ++i)
	{
		for (int j = PosGameOver_Game_y - 1 + 12; j < PosGameOver_Game_y + 11 + 1 + 12; ++j)
		{
			DrawABox(' ', 7, i, j);
		}
	}
	// -------------------- G.txt ----------------------
	inFile.open(PATH_GAMEOVER[0], ios::in);
	inFile >> countChar;
	for (int i = 0; i < countChar; ++i)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, Color_GameOver, x + PosGameOver_Game_x, y + PosGameOver_Game_y);
	}
	inFile.close();
	// -------------------- A.txt ----------------------
	inFile.open(PATH_GAMEOVER[1], ios::in);
	inFile >> countChar;
	for (int i = 0; i < countChar; ++i)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, Color_GameOver, x + PosGameOver_Game_x + 21, y + PosGameOver_Game_y);
	}
	inFile.close();
	// -------------------- M.txt ----------------------
	inFile.open(PATH_GAMEOVER[2], ios::in);
	inFile >> countChar;
	for (int i = 0; i < countChar; ++i)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, Color_GameOver, x + PosGameOver_Game_x + 21 * 2, y + PosGameOver_Game_y);
	}
	inFile.close();
	// -------------------- E.txt ----------------------
	inFile.open(PATH_GAMEOVER[3], ios::in);
	inFile >> countChar;
	for (int i = 0; i < countChar; ++i)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, Color_GameOver, x + PosGameOver_Game_x + 21 * 3, y + PosGameOver_Game_y);
	}
	inFile.close();

	// -------------------- O.txt ----------------------
	inFile.open(PATH_GAMEOVER[4], ios::in);
	inFile >> countChar;
	for (int i = 0; i < countChar; ++i)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, Color_GameOver, x + PosGameOver_Game_x, y + PosGameOver_Game_y + 12);
	}
	inFile.close();
	// -------------------- V.txt ----------------------
	inFile.open(PATH_GAMEOVER[5], ios::in);
	inFile >> countChar;
	for (int i = 0; i < countChar; ++i)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, Color_GameOver, x + PosGameOver_Game_x + 21 * 1, y + PosGameOver_Game_y + 12);
	}
	inFile.close();
	// -------------------- E.txt ----------------------
	inFile.open(PATH_GAMEOVER[6], ios::in);
	inFile >> countChar;
	for (int i = 0; i < countChar; ++i)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, Color_GameOver, x + PosGameOver_Game_x + 21 * 2, y + PosGameOver_Game_y + 12);
	}
	inFile.close();
	// -------------------- R.txt ----------------------
	inFile.open(PATH_GAMEOVER[7], ios::in);
	inFile >> countChar;
	for (int i = 0; i < countChar; ++i)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, Color_GameOver, x + PosGameOver_Game_x + 21 * 3, y + PosGameOver_Game_y + 12);
	}
	inFile.close();
	PrintConsole(color);
	//------------------------------------
	TextColor(12);
	gotoXY(27, 32);
	cout << "!! Do you want to continue? Yes(Y) or No(N) !!";
	_draw.drawYesNo();
	int z;
	while (1) {
		if (_kbhit()) {
			z = _getch();
			if (z == 121 || z == 89)
			{
				ResetGame();
				break;
			}
			if (z == 110 || z == 78)
			{
				ResetGame();
				_thread = 0;
				break;
			}
		}
	}
	_draw.deleteFramesSL();
	_draw.deleteYesNo();
}

void Game::RunGame()
{
	resizeConsole(1000, 600);
	FixConsoleWindow();
	Nocursortype();
	_draw.DrawInfo();
	InitObstacle();
menu:
	while (1)
	{
		_draw.drawMenu();
		_draw.ProcessMenu();
		PrintConsole(true);
		if (_kbhit())
		{
			int z = _getch();
			if (z == 13) { PlaySound(PATH_MP3_CLICK, NULL, SND_LOOP | SND_SYNC); goto rungame; }
		}
	}
rungame:
	switch (_draw.GetTemp() + 1)
	{
	case 1:
	{
		while (_runGame)
		{
			_player.Move2();
			WinGame();
			if (_kbhit())
			{
				int z = _getch();
				ProcessKey(z);
			}
			UpdatePosObstacle();
			DrawGame();
			PrintConsole(_color);
		}
		break;
	}
	case 2:
	{
		LoadGame();
		goto menu;
		break;
	}
	}
}

void Game::UpdatePosObstacle()
{
	InitMap(_player.GetLV());
	ProcessTrafficLigths();
	switch (_player.GetLV())
	{
	case 1:
	{
		for (int i = 0; i < sumLanes_1; i++) {
			if (_stTracffic[0][i] == true) {
				if (_obstacle[0][i].GetMove(sumObstacle_1, _player.GetRunPlayer()) == false)
				{
					_runGame = false;
				}
			}
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < sumLanes_2; i++) {
			if (_stTracffic[1][i] == true) {
				if (_obstacle[1][i].GetMove(sumObstacle_2, _player.GetRunPlayer()) == false)
				{
					_runGame = false;
				}
			}
		}
		break;
	}
	case 3:
	{
		for (int i = 0; i < sumLanes_3; i++) {
			if (_stTracffic[2][i] == true) {
				if (_obstacle[2][i].GetMove(sumObstacle_3, _player.GetRunPlayer()) == false)
				{
					_runGame = false;
				}
			}
		}
	}
	case 4:
	{
		for (int i = 0; i < sumLanes_4; i++) {
			if (_stTracffic[3][i] == true) {
				if (_obstacle[3][i].GetMove(sumObstacle_4, _player.GetRunPlayer()) == false)
				{
					_runGame = false;
				}
			}
		}
		break;
	}
	case 5:
	{
		for (int i = 0; i < sumLanes_5; i++) {
			if (_stTracffic[4][i] == true) {
				if (_obstacle[4][i].GetMove(sumObstacle_5, _player.GetRunPlayer()) == false)
				{
					_runGame = false;
				}
			}
		}
		break;
	}
	case 6:
	{
		for (int i = 0; i < sumLanes_6; i++) {
			if (_stTracffic[5][i] == true) {
				if (_obstacle[5][i].GetMove(sumObstacle_6, _player.GetRunPlayer()) == false)
				{
					_runGame = false;
				}
			}
		}
		break;
	}
	case 7:
	{
		for (int i = 0; i < sumLanes_7; i++) {
			if (_stTracffic[6][i] == true) {
				if (_obstacle[6][i].GetMove(sumObstacle_7, _player.GetRunPlayer()) == false)
				{
					_runGame = false;
				}
			}
		}
		break;
	}
	case 8:
	{
		for (int i = 0; i < sumLanes_8; i++) {
			if (_stTracffic[7][i] == true) {
				if (_obstacle[7][i].GetMove(sumObstacle_8, _player.GetRunPlayer()) == false)
				{
					_runGame = false;
				}
			}
		}
		break;
	}
	case 9:
	{
		for (int i = 0; i < sumLanes_9; i++) {
			if (_stTracffic[8][i] == true) {
				if (_obstacle[8][i].GetMove(sumObstacle_9, _player.GetRunPlayer()) == false)
				{
					_runGame = false;
				}
			}
		}
		break;
	}
	case 10:
	{
		for (int i = 0; i < sumLanes_10; i++) {
			if (_stTracffic[9][i] == true) {
				if (_obstacle[9][i].GetMove(sumObstacle_10, _player.GetRunPlayer()) == false)
				{
					_runGame = false;
				}
			}
		}
		break;
	}
	}
	for (int i = 0; i < 5; i++)
	{
		if (_money[_player.GetLV() - 1][i].GetMove(1, _player.GetRunPlayer()) == false)
		{
			_player.SetScore(_player.GetScore() + 5);
			_money[_player.GetLV() - 1][i].deleteOb();
			TextColor(10);
			gotoXY(126, 3);
			cout << _player.GetScore();
		};
	}
	if (_mode == true) _runGame = true;
	if (_runGame == false) { _gameRunMusic = 3; CloseGame(); };
}

void Game::ThreadDraw()
{
	UpdatePosObstacle();
	DrawGame();
	PrintConsole(_color);
}

void Game::ThreadRunGame()
{
	if (_runGame) {
		_gameRunMusic = 2;
		_player.Move2();
		WinGame();
		if (_kbhit())
		{
			int z = _getch();
			ProcessKey(z);
		}
		DrawGame();
		PrintConsole(_color);
		UpdatePosObstacle();
	}
}

void Game::DrawLoadGame()
{
	for (int i = 28; i < 63; i += 2)
	{
		_draw.drawMenu();
		for (int k = 24; k < 66; k++)
		{
			DrawABox(0, 7, k, 25);
			DrawABox(0, 7, k, 26);
		}
		DrawABox('#', 10, 26, 25);
		DrawABox('#', 10, 26, 26);
		DrawABox('#', 10, 64, 25);
		DrawABox('#', 10, 64, 26);
		for (int j = 28; j <= i; j += 2) {
			DrawABox(0, 238, j, 25);
			DrawABox(0, 238, j, 26);
		}

		PrintConsole(_color);
		Sleep(0);
	}
	_gameRunMusic = 1;
}

void Game::ThreadInit()
{
	resizeConsole(1000, 600);
	FixConsoleWindow();
	Nocursortype();
	_draw.DrawInfo();
	InitObstacle();
	PlaySound(PATH_MP3, NULL, SND_ASYNC);
}

void Game::ThreadMenu()
{
	_draw.drawMenu();
	_draw.ProcessMenu();
	PrintConsole(true);
	if (_kbhit())
	{
		int z = _getch();
		if (z == 13) _thread = (_draw.GetTemp() + 1 == 4) ? 0 : _draw.GetTemp() + 1;
		if (_thread == 1) { DrawLoadGame(); }
	}
}

bool Game::GetRunGame()
{
	return _runGame;
}

int Game::GetNumberThread()
{
	return _thread;
}

void Game::DrawLights(bool st, int x, int y)
{
	switch (st) {
	case true:
	{
		DrawABox(178, 170, x, y);
		DrawABox(208, 15, x, y + 1);
		break;
	}
	case false:
	{
		DrawABox(178, 68, x, y);
		DrawABox(208, 15, x, y + 1);
		break;
	}
	}
}

void Game::ProcessTrafficLigths()
{
	switch (_player.GetLV())
	{
	case 1:
	{
		_time++;
		for (int i = 0; i < sumLanes_1; i++)
		{
			if (_stTracffic[_player.GetLV() - 1][i] == true) {
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = false;
			}
			else
			{
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = true;
			}
		}
		DrawLights(_stTracffic[_player.GetLV() - 1][0], 2, 12);
		DrawLights(_stTracffic[_player.GetLV() - 1][1], 2, 18);
		break;
	}
	case 2:
	{
		_time++;
		for (int i = 0; i < sumLanes_2; i++)
		{
			if (_stTracffic[_player.GetLV() - 1][i] == true) {
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = false;
			}
			else
			{
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = true;
			}
		}
		DrawLights(_stTracffic[_player.GetLV() - 1][0], 2, 13);
		DrawLights(_stTracffic[_player.GetLV() - 1][1], 2, 18);
		break;
	}
	case 3:
	{
		_time++;
		for (int i = 0; i < sumLanes_3; i++)
		{
			if (_stTracffic[_player.GetLV() - 1][i] == true) {
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = false;
			}
			else
			{
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = true;
			}
		}
		DrawLights(_stTracffic[_player.GetLV() - 1][0], 2, 6);
		DrawLights(_stTracffic[_player.GetLV() - 1][1], 2, 11);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 17);
		DrawLights(_stTracffic[_player.GetLV() - 1][3], 2, 21);
		break;
	}
	case 4:
	{
		_time++;
		for (int i = 0; i < sumLanes_4; i++)
		{
			if (_stTracffic[_player.GetLV() - 1][i] == true) {
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = false;
			}
			else
			{
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = true;
			}
		}
		DrawLights(_stTracffic[_player.GetLV() - 1][0], 2, 11);
		DrawLights(_stTracffic[_player.GetLV() - 1][1], 2, 16);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 21);

		break;
	}
	case 5:
	{
		_time++;
		for (int i = 0; i < sumLanes_5; i++)
		{
			if (_stTracffic[_player.GetLV() - 1][i] == true) {
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = false;
			}
			else
			{
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = true;
			}
		}
		DrawLights(_stTracffic[_player.GetLV() - 1][0], 2, 8);
		DrawLights(_stTracffic[_player.GetLV() - 1][1], 2, 12);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 17);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 20);
		break;
	}
	case 6:
	{
		_time++;
		for (int i = 0; i < sumLanes_6; i++)
		{
			if (_stTracffic[_player.GetLV() - 1][i] == true) {
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = false;
			}
			else
			{
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = true;
			}
		}
		DrawLights(_stTracffic[_player.GetLV() - 1][0], 2, 8);
		DrawLights(_stTracffic[_player.GetLV() - 1][1], 2, 12);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 16);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 20);
		break;
	}
	case 7:
	{
		_time++;
		for (int i = 0; i < sumLanes_7; i++)
		{
			if (_stTracffic[_player.GetLV() - 1][i] == true) {
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = false;
			}
			else
			{
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = true;
			}
		}
		DrawLights(_stTracffic[_player.GetLV() - 1][0], 2, 8);
		DrawLights(_stTracffic[_player.GetLV() - 1][1], 2, 12);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 16);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 20);
		break;
	}
	case 8:
	{
		_time++;
		for (int i = 0; i < sumLanes_8; i++)
		{
			if (_stTracffic[_player.GetLV() - 1][i] == true) {
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = false;
			}
			else
			{
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = true;
			}
		}
		DrawLights(_stTracffic[_player.GetLV() - 1][0], 2, 7);
		DrawLights(_stTracffic[_player.GetLV() - 1][1], 2, 12);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 15);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 19);
		break;
	}
	case 9:
	{
		_time++;
		for (int i = 0; i < sumLanes_9; i++)
		{
			if (_stTracffic[_player.GetLV() - 1][i] == true) {
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = false;
			}
			else
			{
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = true;
			}
		}
		DrawLights(_stTracffic[_player.GetLV() - 1][0], 2, 12);
		DrawLights(_stTracffic[_player.GetLV() - 1][1], 2, 16);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 21);
		break;
	}
	case 10:
	{
		_time++;
		for (int i = 0; i < sumLanes_10; i++)
		{
			if (_stTracffic[_player.GetLV() - 1][i] == true) {
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = false;
			}
			else
			{
				if (_time % stLights[_player.GetLV() - 1][i] == 0) _stTracffic[_player.GetLV() - 1][i] = true;
			}
		}
		DrawLights(_stTracffic[_player.GetLV() - 1][0], 2, 11);
		DrawLights(_stTracffic[_player.GetLV() - 1][1], 2, 17);
		DrawLights(_stTracffic[_player.GetLV() - 1][2], 2, 21);
		break;
	}
	}
}

void Game::ThreadMusic()
{
	if (_gameMusic != 10) {
		if (_gameRunMusic != _gameMusic)
		{
			_gameMusic = _gameRunMusic;
			switch (_gameMusic)
			{
				// ------------------ Menu Music ------------------
			case 0:
			{
				PlaySound(PATH_MP3, NULL, SND_LOOP | SND_ASYNC);
				break;
			}
			// ----------------- BackGround Music -------------
			case 1:
			{
				PlaySound(PATH_MP3_CLICK, NULL, SND_SYNC);
				_gameRunMusic = 2;
				break;
			}
			case 2:
			{
				PlaySound(PATH_MP3_BACKGROUND, NULL, SND_ASYNC);
				break;
			}
			case 3:
			{
				PlaySound(PATH_MP3_XCT, NULL, SND_SYNC);
				break;
			}
			case 4:
			{
				PlaySound(PATH_MP3_UPLV, NULL, SND_SYNC);
				_gameRunMusic = 2;
				break;
			}
			case 5:
			{
				PlaySound(NULL, NULL, SND_LOOP | SND_SYNC);
				break;
			}
			case 6:
			{
				PlaySound(PATH_MP3, NULL, SND_LOOP | SND_SYNC);
				break;
			}
			}
		}
	}
	else PlaySound(NULL, NULL, SND_LOOP | SND_SYNC);
}