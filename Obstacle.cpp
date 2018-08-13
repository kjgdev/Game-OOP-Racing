#include "Obstacle.h"

Vehicle::Vehicle()
{
	_run = _start;
	_start._x = 0;
	_start._x = 0;
	_finish._x = 0;
	_finish._y = 0;
	_direction = true;
	_step_x = 1;
	_step_y = 1;
}

void Vehicle::InitVehicle(int run_x, int run_y)
{
	_run._x = run_x;
	_run._y = run_y;
}

void Vehicle::SettingVehicle(int start_x, int start_y, int finish_x, int finish_y, int distance, bool direction, int step_x, int step_y)
{
	_start._x = start_x;
	_start._y = start_y + _run._y;
	_finish._x = finish_x;
	_finish._y = finish_y + _run._y;
	_direction = direction;
	_step_x = step_x;
	_step_y = step_y;
	_run._x += start_x + distance;
	_run._y += start_y;
}

bool Vehicle::Move(Oxy runPlayer)
{
	switch (_direction)
	{
	case true:
	{
		if (_run._x+_step_x >= _finish._x && _run._y+_step_x >= _finish._y)
		{	
			_run._x = _start._x;
			_run._y = _start._y;
		}
		else
		{
			_run._x += _step_x;
			_run._y += _step_y;
		}
		break;
	}
	case false:
	{
		if (_run._x -_step_x <= _start._x && _run._y-_step_y  <= _start._y)
		{
			_run._x = _finish._x-2;
			_run._y = _finish._y;
		}
		else
		{
			_run._x -= _step_x;
			_run._y -= _step_y;
		}
		break;
	}
	}
	if (runPlayer._x == _run._x && runPlayer._y == _run._y) return false;
	return true;
}

bool Vehicle::Move1(Player _player,Oxy &runPlayer)
{
	 runPlayer = _player.GetRunPlayer();
	switch (_direction)
	{
	case true:
	{
		if (_run._x + _step_x >= _finish._x && _run._y + _step_x >= _finish._y)
		{
			_run._x = _start._x;
			_run._y = _start._y;
		}
		else
		{
			
			_run._x += _step_x;
			_run._y += _step_y;
		}
		if (runPlayer._x == _run._x && runPlayer._y == _run._y) {
			runPlayer._x += _step_x; runPlayer._y += _step_y;
			if ((runPlayer._x == MAX_X - 10 && runPlayer._y == _run._y) || (runPlayer._y == MAX_X + 4 && runPlayer._y == _run._y)) return false;
			return true;
		}
		break;
	}
	case false:
	{
		if (_run._x - _step_x <= _start._x && _run._y - _step_y <= _start._y)
		{
			_run._x = _finish._x - 2;
			_run._y = _finish._y;
		}
		else
		{
			if (runPlayer._x == _run._x && runPlayer._y == _run._y) {
				runPlayer._x -= _step_x; runPlayer._y -= _step_y;
			}
			_run._x -= _step_x;
			_run._y -= _step_y;
		}
		if ((runPlayer._x == MAX_X - 10 && runPlayer._y == _run._y) || (runPlayer._y == MIN_X + 4 && runPlayer._y == _run._y)) 	
			return false;
		return true;
		break;
	}
	}
}

void Vehicle::SetFile(fstream & inFile)
{
	inFile >> _run._x >> _run._y;
	inFile >> _start._x >> _start._y;
	inFile >> _finish._x >> _finish._y;
	inFile >> _direction;
	inFile >> _step_x >> _step_y;
}

void Vehicle::GetFile(fstream & outFile)
{
	outFile << _run._x << " ";
	outFile << _run._y << " ";
	outFile << _start._x << " ";
	outFile << _start._y << " ";
	outFile << _finish._x << " ";
	outFile << _finish._y << " ";
	outFile << _direction << " ";
	outFile << _step_x << " ";
	outFile << _step_y << endl;
}

int Vehicle::GetRun_x()
{
	return _run._x;
}

int Vehicle::GetRun_y()
{
	return _run._y;
}

void Vehicle::deleteOb()
{
	_run._x = 1;
	_run._y = 29;
}

Vehicle::~Vehicle()
{
}

Car::Car()
{
	_color = 0;
	_char = '0';
} 

void Car::CopyAttributes(Car b)
{
	_color = b._color;
	_char = b._char;
	Vehicle::InitVehicle(b.GetRun_x(), b.GetRun_y());
}

void Car::InitCar(int run_x, int run_y, char c, int color)
{
	Vehicle::InitVehicle(run_x, run_y);
	_char = c;
	_color = color;
}

void Car::SettingCar(int start_x, int start_y, int finish_x, int finish_y, int distance, bool direction, int step_x, int step_y,int color)
{
	Vehicle::SettingVehicle(start_x, start_y, finish_x, finish_y, distance, direction, step_x, step_y);
	_color = color;
}

bool Car::Move(Oxy runPlayer)
{
	return Vehicle::Move(runPlayer);
}

bool Car::Move1(Player _player, Oxy &runPlayer)
{
	return Vehicle::Move1(_player,runPlayer);
}

Oxy Car::GetPointRun()
{
	Oxy temp;
	temp._x = Vehicle::GetRun_x();
	temp._y = Vehicle::GetRun_y();
	return temp;
}

void Car::Display()
{
	DrawABox(_char, _color, Vehicle::GetRun_x(), Vehicle::GetRun_y());
}

void Car::DisplayOutMap()
{
	drawABoxOutMap(_char, _color, Vehicle::GetRun_x(), Vehicle::GetRun_y());
}

void Car::deleteOb()
{
	Vehicle::deleteOb();
	_color = 0;
	_char = 0;
}

Obstacle::Obstacle()
{
	_obstacle = new Car*[0];
	_obstacle[0] = new Car[0];
}

Obstacle::~Obstacle()
{
	delete[]_obstacle;
}

void Obstacle::GetFile(string Path,int amountObstacle)
{
	fstream inFile;
	inFile.open(Path, ios::in);
	if (inFile.fail() == true)
	{
		cout << "Error PATH: " << Path;
		return;
	}
	int c, color;
	int run_x, run_y;
	inFile >> _countChar;

	_obstacle = new Car*[amountObstacle];
	for (int i = 0; i < amountObstacle; ++i)
	{
		_obstacle[i] = new Car[_countChar];
	}

	for (int i = 0; i < _countChar; ++i) 
	{
		inFile >> c >> color;
		inFile >> run_x >> run_y;
		_obstacle[0][i].InitCar(run_x, run_y, c, color);
	}
	if (amountObstacle > 0)
	{
		for (int i = 1; i < amountObstacle; ++i)
		{
			for (int j = 0; j < _countChar; ++j)
			{
				_obstacle[i][j].CopyAttributes(_obstacle[0][j]);
			}
		}
	}
}

bool Obstacle::GetMove(int amountObstacle,Oxy runPlayer)
{
	bool runGame = true;
	for (int i = 0; i < amountObstacle; ++i)
	{
		for (int j = 0; j < _countChar; ++j)
		{
			if (_obstacle[i][j].Move(runPlayer) == false) runGame = false;
		}
	}
	return runGame;
}

void Obstacle::GetMove1(int amountObstacle, Oxy runPlayer)
{
	for (int i = 0; i < amountObstacle; ++i)
	{
		for (int j = 0; j < _countChar; ++j)
		{
			_obstacle[i][j].Move(runPlayer);
		}
	}
}

bool Obstacle::GetMove2(int amountObstacle, Player _player, Oxy &runPlayer)
{
	bool runGame = true;
	for (int i = 0; i < amountObstacle; ++i)
	{
		for (int j = 0; j < _countChar; ++j)
		{
			if (_obstacle[i][j].Move1(_player,runPlayer) == false) runGame = false;
		}
	}
	return runGame;
}

Car* Obstacle::GetObstacle(int x)
{
	return _obstacle[x];
}

int Obstacle::GetCountChar()
{
	return _countChar;
}

void Obstacle::SettingObstacle(int start_x, int start_y, int finish_x, int finish_y, bool direction, int step_x, int step_y, int sumObstacle,int color)
{
	int distance = 98 / sumObstacle;
	for (int i = 0; i < sumObstacle; ++i)
	{
		for (int j = 0; j < _countChar; ++j)
		{
			_obstacle[i][j].SettingCar(start_x, start_y, finish_x, finish_y, distance*i, direction, step_x, step_y,color);
		}
	}
}

void Obstacle::Display(int amountObstacle)
{
	//--------- Obstacle Display ---------------
	for (int i = 0; i < amountObstacle; ++i)
	{
		for (int j = 0; j < _countChar; ++j)
		{
			_obstacle[i][j].Display();
		}
	}
}

void Obstacle::DisplayOutMap()
{
	for (int i = 0; i < 1; ++i)
	{
		for (int j = 0; j < _countChar; ++j)
		{
			_obstacle[i][j].DisplayOutMap();
		}
	}
}

void Obstacle::SetFileSave(int amountObstacle, fstream & infile)
{
	for (int i = 0; i < amountObstacle; ++i)
	{
		for (int j = 0; j < _countChar; ++j)
		{
			_obstacle[i][j].SetFile(infile);
		}
	}
}

void Obstacle::GetFileSave(int amountObstacle, fstream & outFile)
{
	for (int i = 0; i < amountObstacle; ++i)
	{
		for (int j = 0; j < _countChar; ++j)
		{
			_obstacle[i][j].GetFile(outFile);
		}
	}
}

void Obstacle::deleteOb()
{
	_obstacle[0][0].deleteOb();
}

