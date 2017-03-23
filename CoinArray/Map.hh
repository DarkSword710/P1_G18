#pragma once
#include <iostream>

class Map
{
public:
	Map(int difficulty, char c);
	void UpdateCell(int x, int y, char c);
	void PrintMap();
	int getHeight();
	int getWidth();
	int getEmptySybol();
	char getMapArray(int x, int y);
	~Map();

private:
	char** map_array;
	int width;
	int height;
	char emptySymbol;
};