#include "Map.h"

Map::Map()
{
	for (int i = 0; i < MAX_Y - MIN_Y + 1; ++i)
	{
		Maps[i][MAX_X - MIN_X]._char = '\0';
	}

}

void Map::SetFile(string Path)
{
	fstream inFile;
	inFile.open(Path, ios::in);
	if (inFile.fail() == true)
	{
		cout << "Error Path: " << Path;
		return;
	}
	while (!inFile.eof()) {
		int c, color, x, y, st;
		inFile >> c >> color >> x >> y >> st;
		Maps[y][x]._st = st;
		DrawABox(c, color, x, y);
	}
}
