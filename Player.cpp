#include "Player.h"

Player::Player()
{
	_char = 0;
	_color = PLAYER_COLOR;
	_save._x = PLAYER_X;
	_save._y = PLAYER_Y;
	_run = _save;
	_lv = 1;
	_score = 0;
}

Player::Player(char c, int color, int x, int y)
{
	_char = c;
	_color = color;
	_save._x = x;
	_save._y = y;
	_run = _save;
	_lv = 1;
	_score = 0;
}

bool checkStatus(Oxy a)
{
	if (Maps[a._y][a._x]._st == true) return false;
	return true;
}

//void Player::Move(Status st)
//{
//	switch (st)
//	{
//	case UP:
//	{
//		Oxy temp = _run;
//		--temp._y;
//		if (checkStatus(temp) == true)
//		{
//			--_run._y;
//		}
//		break;
//	}
//	case DOWN:
//	{
//		Oxy temp = _run;
//		++temp._y;
//		if (checkStatus(temp) == true)
//		{
//			++_run._y;
//		}
//		break;
//	}
//	case LEFT:
//	{
//		Oxy temp = _run;
//		--temp._x;
//		if (checkStatus(temp) == true)
//		{
//			--_run._x;
//		}
//		break;
//	}
//	case RIGHT:
//	{
//		Oxy temp = _run;
//		++temp._x;
//		if (checkStatus(temp) == true)
//		{
//			++_run._x;
//		}
//		break;
//	}
//	}
//}

void Player::Move2()
{
	if(GetAsyncKeyState(VK_UP))
	{
		Oxy temp = _run;
		--temp._y;
		if (checkStatus(temp) == true&& temp._y >0)
		{
			--_run._y;
		}
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		Oxy temp = _run;
		++temp._y;
		if (checkStatus(temp) == true&&temp._y < 28)
		{
			++_run._y;
		}
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		Oxy temp = _run;
		--temp._x;
		if (checkStatus(temp) == true&& temp._x >1)
		{
			--_run._x;
		}
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		Oxy temp = _run;
		++temp._x;
		if (checkStatus(temp) == true&& temp._x < 98)
		{
			++_run._x;
		}
	}
}

void Player::SetFile(fstream &inFile)
{

	inFile >> _char;
	inFile >> _color;
	inFile >> _run._x >> _run._y;
	inFile >> _save._x >> _save._y;
	inFile >> _lv;
	inFile >> _score;
}

void Player::GetFile(fstream & outFile)
{
	outFile << _char << " ";
	outFile << _color << " ";
	outFile << _run._x << " ";
	outFile << _run._y << " ";
	outFile << _save._x << " ";
	outFile << _save._y << " ";
	outFile << _lv << " ";
	outFile << _score << endl;
}

void Player::Display()
{
	DrawABox('O', _color, _run._x, _run._y);
	DrawABox(162, _color, _run._x, _run._y + 1);
	DrawABox(47, _color, _run._x-1, _run._y);
	DrawABox(92, _color, _run._x+1, _run._y);
}

void Player::ResetPlayer()
{
	_run = _save;
}

int Player::GetScore()
{
	return _score;
}

int Player::GetLV()
{
	return _lv;
}

int Player::GetRun_X()
{
	return _run._x;
}

int Player::GetRun_Y()
{
	return _run._y;
}

Oxy Player::GetRunPlayer()
{
	return _run;
}

void Player::SetLV(int x)
{
	if (x > 0 && x < 12)
		_lv = x;
}

void Player::SetScore(int x)
{
	if (x > 0)
		_score = x;
}

void Player::SetRun(int x,int y)
{
	_run._x = x;
	_run._y = y;
}

Player::~Player()
{
}
