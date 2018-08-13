#include "Display.h"
void DrawABox(char c, int color, int x, int y)
{
	Maps[y][x]._char = c;
	Maps[y][x]._color = color;
}

void drawABoxOutMap(char c, int color, int x, int y)
{
	gotoXY(x, y);
	TextColor(color);
	putchar(c);
	TextColor(7);
}

Draw::Draw()
{
	ob = new Obstacle[5];
	for (int i = 0; i < 5; i++)
	{
		ob[i].GetFile(PATH_OBSTACLE_MENU[i], 1);
	}
	ob[0].SettingObstacle(13, 15, 0, 0, true, 0, 0, 1,14);
	ob[1].SettingObstacle(28, 21, 0, 0, true, 0, 0, 1,15);
	ob[2].SettingObstacle(10, 10, 80, 10, true, 1, 0, 1,7);
	ob[3].SettingObstacle(70, 20, 0, 0, true, 0, 0, 1,10);
	ob[4].SettingObstacle(55, 15, 0, 0, true, 0, 0, 1,14);
}

Draw::~Draw()
{
	delete[]ob;
}

void Draw::DrawInfo()
{
	// ------- Frames ----------------
	for (int i = 0; i < 50; ++i)
	{
		drawABoxOutMap(186, 12, 102, i);
	}
	drawABoxOutMap(124, 12, 102, 7);
	for (int i = MAX_X + 3; i < 135; ++i)
	{
		drawABoxOutMap(205, 12, i, 7);
	}
	TextColor(10);
	gotoXY(MAX_X + 4, 1);
	cout << "---> !! CROSS OR DEAD !! <---";
	TextColor(11);
	gotoXY(MAX_X + 5, 3);
	cout << "- Level: ";
	gotoXY(MAX_X + 18, 3);
	cout << "Point: ";
	TextColor(10);
	gotoXY(126, 3);
	cout << "0";
	TextColor(11);
	gotoXY(MAX_X + 5, 5);
	cout << "- Music: ";
	TextColor(10);
	gotoXY(114, 5);
	cout << "ON";
	gotoXY(114, 3);
	cout << '1';
	gotoXY(MAX_X + 10, 8);
	cout << "--> !! KEY !! <--";
	TextColor(11);
	gotoXY(MAX_X + 5, 10);
	cout << "- Move: ^,v,<,>";
	gotoXY(MAX_X + 5, 12);
	cout << "- Pause Game: P";
	gotoXY(MAX_X + 5, 14);
	cout << "- Save Game: L";
	gotoXY(MAX_X + 5, 16);
	cout << "- Load Game: T";
	gotoXY(MAX_X + 5, 18);
	cout << "- Music: ON(1) - OFF(2)";
	for (int i = MAX_X + 3; i < 135; ++i)
	{
		drawABoxOutMap(205, 12, i, 20);
	}
	TextColor(10);
	gotoXY(MAX_X + 7, 22);
	cout << "DEVELOPMENT TEAM INFO";
	TextColor(11);
	gotoXY(MAX_X + 5, 24);
	cout << "- Le Minh Khang 062";
	gotoXY(MAX_X + 5, 26);
	cout << "- Dinh Nguyen Hanh Dung 021";
	gotoXY(MAX_X + 5, 28);
	cout << "- Lu Anh Duy 045";
	gotoXY(MAX_X + 5, 30);
	cout << "- Trinh Thai Binh 033";
}

void Draw::deleteFramesSL()
{
	for (int i = MIN_X + 21; i <= MIN_X + 79; ++i) {
		drawABoxOutMap(205, 0, i, 31);
		drawABoxOutMap(205, 0, i, 33);
		drawABoxOutMap(0, 0, i, 32);
	}
	drawABoxOutMap(201, 0, 20, 31);
	drawABoxOutMap(187, 0, 80, 31);
	drawABoxOutMap(200, 0, 20, 33);
	drawABoxOutMap(188, 0, 80, 33);
	drawABoxOutMap(186, 0, 20, 32);
	drawABoxOutMap(186, 0, 80, 32);
	putchar('\n');
}

void Draw::drawFramesSL()
{
	for (int i = MIN_X + 21; i <= MIN_X + 79; ++i) {
		drawABoxOutMap(205, 10, i, 31);
		drawABoxOutMap(205, 10, i, 33);
		drawABoxOutMap(0, 7, i, 32);
	}
	drawABoxOutMap(201, 10, 20, 31);
	drawABoxOutMap(187, 10, 80, 31);
	drawABoxOutMap(200, 10, 20, 33);
	drawABoxOutMap(188, 10, 80, 33);
	drawABoxOutMap(186, 10, 20, 32);
	drawABoxOutMap(186, 10, 80, 32);
	putchar('\n');
}

void Draw::drawFramesLoadSave()
{
	drawABoxOutMap(201, 10, 7, 31);
	drawABoxOutMap(200, 10, 7, 33);
	drawABoxOutMap(187, 10, 17, 31);
	drawABoxOutMap(188, 10, 17, 33);
	for (int i = 8; i < 17; i++)
	{
		drawABoxOutMap(205, 10, i, 31);
		drawABoxOutMap(205, 10, i, 33);
		drawABoxOutMap(0, 7, i, 32);
	}
	drawABoxOutMap(186, 10, 7, 32);
	drawABoxOutMap(186, 10, 17, 32);
}

void Draw::deleteFramesLoadSave()
{
	drawABoxOutMap(0, 0, 7, 31);
	drawABoxOutMap(0, 0, 7, 33);
	drawABoxOutMap(0, 0, 17, 31);
	drawABoxOutMap(0, 0, 17, 33);
	for (int i = 8; i < 17; i++)
	{
		drawABoxOutMap(0, 0, i, 31);
		drawABoxOutMap(0, 0, i, 33);
		drawABoxOutMap(0, 0, i, 32);
	}
	drawABoxOutMap(0, 0, 7, 32);
	drawABoxOutMap(0, 0, 17, 32);
}

void Draw::drawYesNo()
{
	string yes = { "YES(Y)" };
	string no = { "NO(N)" };
	drawABoxOutMap(201, 13, 83, 31);
	drawABoxOutMap(200, 13, 83, 33);
	drawABoxOutMap(187, 13, 90, 31);
	drawABoxOutMap(188, 13, 90, 33);
	for (int i = 84; i < 90; ++i) {
		drawABoxOutMap(205, 13, i, 31);
		drawABoxOutMap(205, 13, i, 33);
		drawABoxOutMap(0, 7, i, 32);
	}
	drawABoxOutMap(186, 13, 83, 32);
	drawABoxOutMap(186, 13, 90, 32);

	drawABoxOutMap(201, 13, 91, 31);
	drawABoxOutMap(200, 13, 91, 33);
	drawABoxOutMap(187, 13, 98, 31);
	drawABoxOutMap(188, 13, 98, 33);
	for (int i = 92; i < 98; ++i) {
		drawABoxOutMap(205, 13, i, 31);
		drawABoxOutMap(205, 13, i, 33);
		drawABoxOutMap(0, 7, i, 32);
	}
	drawABoxOutMap(186, 13, 91, 32);
	drawABoxOutMap(186, 13, 98, 32);

	gotoXY(84, 32);
	TextColor(10);
	cout << yes;
	gotoXY(92, 32);
	cout << no;
}

void Draw::deleteYesNo()
{
	drawABoxOutMap(0, 0, 83, 31);
	drawABoxOutMap(0, 0, 83, 33);
	drawABoxOutMap(0, 0, 90, 31);
	drawABoxOutMap(0, 0, 90, 33);
	for (int i = 84; i < 90; ++i) {
		drawABoxOutMap(0, 0, i, 31);
		drawABoxOutMap(0, 0, i, 33);
		drawABoxOutMap(0, 0, i, 32);
	}
	drawABoxOutMap(0, 0, 83, 32);
	drawABoxOutMap(0, 0, 90, 32);

	drawABoxOutMap(0, 0, 91, 31);
	drawABoxOutMap(0, 0, 91, 33);
	drawABoxOutMap(0, 0, 98, 31);
	drawABoxOutMap(0, 0, 98, 33);
	for (int i = 92; i < 98; ++i) {
		drawABoxOutMap(0, 0, i, 31);
		drawABoxOutMap(0, 0, i, 33);
		drawABoxOutMap(0, 0, i, 32);
	}
	drawABoxOutMap(0, 0, 91, 32);
	drawABoxOutMap(0, 0, 98, 32);
}

void Draw::drawMenu()
{
	fstream inFile;
	int c, color, x, y;
	int countChar;
	// ----------- cross.txt -------------
	inFile.open(PATH_NAME_GAME[0], ios::in);
	if (inFile.fail() == true) return;
	inFile >> countChar;
	for (int i = 0; i < countChar; i++)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, 14, x+2, y+1);
	}
	inFile.close();
	// ---------- or.txt ------------
	inFile.open(PATH_NAME_GAME[1], ios::in);
	if (inFile.fail() == true) return;
	inFile >> countChar;
	for (int i = 0; i < countChar; i++)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, 7, x+45, y+3);
	}
	inFile.close();
	//----------- dead.txt -----------
	inFile.open(PATH_NAME_GAME[2], ios::in);
	//if (inFile.fail() == true) return;
	inFile >> countChar;
	for (int i = 0; i < countChar; i++)
	{
		inFile >> c >> color >> x >> y;
		DrawABox(c, 4, x+65, y+3);
	}
	inFile.close();
	// --------------------------------
	for (int i = 10; i < 80; i++)
	{
		DrawABox(240, 15, i, 25);
	}

	for (int i = 10; i < 80; i++)
	{
		DrawABox(240, 15, i, 13);
	}
	for (int j = 0; j < 5; j++) {
		for (int i = 60; i < 75; i++)
		{
			DrawABox(0, 119, i, 15 + j * 2);
		}
	}

	for (int i = 0; i < 5; i++)
	{
		ob[i].Display(1);
	}
	drawFrameMenu();

	DrawABox('N', 11, PosNewGame_x, PosNewGame_y);
	DrawABox('E', 11, PosNewGame_x + 1, PosNewGame_y);
	DrawABox('W', 11, PosNewGame_x + 2, PosNewGame_y);
	DrawABox('G', 11, PosNewGame_x + 4, PosNewGame_y);
	DrawABox('A', 11, PosNewGame_x + 5, PosNewGame_y);
	DrawABox('M', 11, PosNewGame_x + 6, PosNewGame_y);
	DrawABox('E', 11, PosNewGame_x + 7, PosNewGame_y);

	DrawABox('L', 11, PosLoadGame_x, PosLoadGame_y);
	DrawABox('O', 11, PosLoadGame_x + 1, PosLoadGame_y);
	DrawABox('A', 11, PosLoadGame_x + 2, PosLoadGame_y);
	DrawABox('D', 11, PosLoadGame_x + 3, PosLoadGame_y);
	DrawABox('G', 11, PosLoadGame_x + 5, PosLoadGame_y);
	DrawABox('A', 11, PosLoadGame_x + 6, PosLoadGame_y);
	DrawABox('M', 11, PosLoadGame_x + 7, PosLoadGame_y);
	DrawABox('E', 11, PosLoadGame_x + 8, PosLoadGame_y);

	DrawABox('S', 11, PosSetting_x, PosSetting_y);
	DrawABox('E', 11, PosSetting_x + 1, PosSetting_y);
	DrawABox('T', 11, PosSetting_x + 2, PosSetting_y);
	DrawABox('T', 11, PosSetting_x + 3, PosSetting_y);
	DrawABox('I', 11, PosSetting_x + 4, PosSetting_y);
	DrawABox('N', 11, PosSetting_x + 5, PosSetting_y);
	DrawABox('G', 11, PosSetting_x + 6, PosSetting_y);

	for (int i = 0; i < MAX_X - MIN_X; i++)
	{
		DrawABox(205, 13, i, 0);
		DrawABox(205, 13, i, MAX_Y - 1);
	}
	for (int i = 0; i < MAX_Y - MIN_Y; i++)
	{
		DrawABox(186, 13, 0, i);
		DrawABox(186, 13, MAX_X - 1, i);
	}
	DrawABox(201, 13, 0, 0);
	DrawABox(200, 13, 0, MAX_Y - 1);
	DrawABox(187, 13, MAX_X - 1, 0);
	DrawABox(188, 13, MAX_X - 1, MAX_Y - 1);

	DrawABox(202, 6, 90, 23);

	for (int i = 18; i < 23; i++)
	{
		DrawABox(186, 6, 90, i);
	}

	DrawABox(203, 6, 90, 17);

	DrawABox('-', 13, 89, 17);
	DrawABox('-', 13, 88, 17);
	DrawABox('-', 13, 87, 17);
	DrawABox('-', 13, 91, 17);
	DrawABox('-', 13, 92, 17);
	DrawABox('-', 13, 93, 17);
	DrawABox('-', 13, 94, 17);
	DrawABox('-', 13, 86, 17);

	DrawABox('-', 13, 89, 11);
	DrawABox('-', 13, 88, 11);
	DrawABox('-', 13, 87, 11);
	DrawABox('-', 13, 91, 11);
	DrawABox('-', 13, 90, 11);
	DrawABox('-', 13, 92, 11);
	DrawABox('-', 13, 93, 11);
	DrawABox('-', 13, 94, 11);
	DrawABox('-', 13, 86, 11);

	for (int i = 17; i > 10; i--)
	{
		DrawABox('!', 12, 87, i);
		DrawABox('!', 12, 93, i);
	}

	DrawABox(0, 170, 90, 16);
	DrawABox(0, 170, 89, 16);
	DrawABox(0, 170, 91, 16);

	DrawABox(0, 238, 90, 14);
	DrawABox(0, 238, 89, 14);
	DrawABox(0, 238, 91, 14);

	DrawABox(0, 204, 90, 12);
	DrawABox(0, 204, 89, 12);
	DrawABox(0, 204, 91, 12);

	for (int i = 10; i < 79; i += 4)
	{
		DrawABox(157, 2, i, 26);
		DrawABox(167, 4, i + 2, 26);
	}
}

void Draw::ProcessMenu()
{
	if (GetAsyncKeyState(VK_UP))
	{
		_temp--;
		if (_temp < 0) { _temp = 2; }
		Sleep(100);
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		_temp++;
		if (_temp > 2) { _temp = 0; }
		Sleep(100);
	}
	Oxy run;
	run._x = 0; run._y = 0;
	ob[2].GetMove1(1, run);
}

void Draw::drawFrameMenu()
{
	for (int i = PosNewGame_x - 2; i < PosNewGame_x + 12; i++)
	{
		DrawABox(205, 13, i + _temp * 5, PosNewGame_y - 1 + _temp * 3);
		DrawABox(205, 13, i + _temp * 5, PosNewGame_y + 1 + _temp * 3);
	}
	DrawABox(186, 13, PosNewGame_x - 3 + _temp * 5, PosNewGame_y + _temp * 3);
	DrawABox(186, 13, PosNewGame_x + 12 + _temp * 5, PosNewGame_y + _temp * 3);
	DrawABox(201, 13, PosNewGame_x - 3 + _temp * 5, PosNewGame_y - 1 + _temp * 3);
	DrawABox(200, 13, PosNewGame_x - 3 + _temp * 5, PosNewGame_y + 1 + _temp * 3);
	DrawABox(187, 13, PosNewGame_x + 12 + _temp * 5, PosNewGame_y - 1 + _temp * 3);
	DrawABox(188, 13, PosNewGame_x + 12 + _temp * 5, PosNewGame_y + 1 + _temp * 3);
}

int Draw::GetTemp()
{
	return _temp;
}

void Draw::SetTemp(int temp)
{
	if (temp > 0 && temp < 3) _temp = temp;
}

void Draw::DrawSettings()
{

	TextColor(7);
	gotoXY(35, 32);
	cout << "MUSIC: ON(1) - OFF(2)";
	TextColor(10);
	gotoXY(42, 32);
	cout << "ON(1)";
	TextColor(4);
	gotoXY(50, 32);
	cout << "OFF(2)";
}

