#ifndef _Constants_h_
#define _Constants_h_

#include <Windows.h>
#include <string>

//---------- WALL ------------
const int MAX_X = 100;
const int MAX_Y = 30;
const int MIN_X = 0;
const int MIN_Y = 0;
const int WALL_COLOR = 13;
//---------- PLAYER ----------
const int PLAYER_X = 70;
const int PLAYER_Y = 27;
const int PLAYER_COLOR = 9;
const int PLAYER_ICON = 'Y';
const int PLAYER_MAXLV = 10;
//---------- Obstacle -----------
const int PosNewGame_x = 37;
const int PosLoadGame_x = 42;
const int PosSetting_x = 49;
const int PosNewGame_y = 16;
const int PosLoadGame_y = 19;
const int PosSetting_y = 22;
const int PosGameOver_Game_x = 8;
const int PosGameOver_Game_y = 3;
const int PosGameWin_x = 20;
const int PosGameWin_y = 10;
const int Color_GameOver = 15;

const int sumLanes_1 = 2;
const int sumLanes_2 = 2;
const int sumLanes_3 = 4;
const int sumLanes_4 = 3;
const int sumLanes_5 = 4;
const int sumLanes_6 = 4;
const int sumLanes_7 = 4;
const int sumLanes_8 = 4;
const int sumLanes_9 = 3;
const int sumLanes_10 = 3;

const int sumObstacle_1 = 3;
const int sumObstacle_2 = 4;
const int sumObstacle_3 = 3;
const int sumObstacle_4 = 4;
const int sumObstacle_5 = 3;
const int sumObstacle_6 = 5;
const int sumObstacle_7 = 6;
const int sumObstacle_8 = 3;
const int sumObstacle_9 = 3;
const int sumObstacle_10 = 3;
// --------- Color Obstacle ----------
const int color_obstacle_map_1[sumLanes_1] = { 12,14 };
const int color_obstacle_map_2[sumLanes_2] = { 13,9 };
const int color_obstacle_map_3[sumLanes_3] = { 13,14,12,11};
const int color_obstacle_map_4[sumLanes_4] = { 7,14 ,11 };
const int color_obstacle_map_5[sumLanes_5] = { 14,7 ,11,10 };
const int color_obstacle_map_6[sumLanes_6] = { 12,14,13,9 };
const int color_obstacle_map_7[sumLanes_7] = { 13,9 ,6,10 };
const int color_obstacle_map_8[sumLanes_8] = { 7,12 ,13,14 };
const int color_obstacle_map_9[sumLanes_9] = { 13,7 ,14 };
const int color_obstacle_map_10[sumLanes_10] = { 7,13 ,12};
//---------- Path -----------
const char PATH_OBSTACLE_MAP_1[sumLanes_1][20] = { "mouse1.txt","bird1.txt" };
const char PATH_OBSTACLE_MAP_2[sumLanes_2][20] = { "bunny1.txt","bike.txt", };
const char PATH_OBSTACLE_MAP_3[sumLanes_3][20] = { "pig1.txt","dove1.txt","bird1.txt","bird2.txt" };
const char PATH_OBSTACLE_MAP_4[sumLanes_4][20] = { "mouse1.txt","bird1.txt","monkey1.txt" };
const char PATH_OBSTACLE_MAP_5[sumLanes_5][20] = { "mouse1.txt","snowman.txt","bear2.txt","car3.txt" };
const char PATH_OBSTACLE_MAP_6[sumLanes_6][20] = { "car1.txt","bird1.txt","cat1.txt","car2.txt" };
const char PATH_OBSTACLE_MAP_7[sumLanes_7][20] = { "bunny1.txt","car1.txt","bird2.txt","car2.txt" };
const char PATH_OBSTACLE_MAP_8[sumLanes_8][20] = { "car3.txt","car2.txt","pig1.txt" ,"dove1.txt" };
const char PATH_OBSTACLE_MAP_9[sumLanes_9][20] = { "bike.txt","bunny.txt","bike.txt" };
const char PATH_OBSTACLE_MAP_10[sumLanes_10][20] = { "cat1.txt","mouse1.txt","monkey1.txt" };
const char PATH_OBSTACLE_MENU[5][20] = { "bird1.txt","bunny1.txt","XeLua.txt","mouse1.txt","cat1.txt" };
const char PATH_OBSTACLE_DEAD[1][20] = { "Ambulance.txt" };

const char PATH_MAP[10][15] = { "MapLV1.txt","MapLV2.txt","MapLV3.txt","MapLV4.txt",
								"MapLV5.txt" ,"MapLV6.txt" ,"MapLV7.txt" ,"MapLV8.txt" ,
								"MapLV9.txt" ,"MapLV10.txt" };
const char PATH_NAME_GAME[3][10] = { "cross.txt","or.txt","dead.txt" };
const char PATH_MP3[30] = { "menu.wav" };
const char PATH_MP3_DEATH[30] = { "close.wav" };
const char PATH_MP3_CLICK[30] = { "akm.wav" };
const char PATH_MP3_SELECT[30] = { "select.wav" };
const char PATH_MP3_BACKGROUND[30] = { "Nyan-Cat.wav" };
const char PATH_MP3_UPLV[30] = { "upLv.wav" };
const char PATH_MP3_XCT[30] = { "XCT.wav" };
const char PATH_GAMEOVER[8][20] = { "G.txt","A.txt","M.txt","E.txt","O.txt","V.txt","E.txt","R.txt" };
const char PATH_GAMEWIN[3][20] = { "W.txt","I.txt","N.txt" };
const int stLights[10][4] = { 30,40,50, 60,
							  35,20,40,60,
							  30,40,50,60,
							  20,30,40,60,
							  30,40,50,60,
							  20,30,40,60,
							  30,40,50,60,
							  20,30,40,60,
							  30,40,50,60,
							  20,30,40,60 };
enum Status { ON,OFF,ESC, PRE, NEXTLV, ENTER, PAUSEGAME, SAVEGAME, LOADGAME, YES, NO, EXIT };

struct Point
{
	char _char;
	int _color;
	bool _st = false;
};

struct Oxy
{
	int _x;
	int _y;
};

#endif