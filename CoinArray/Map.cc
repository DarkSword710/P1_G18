#include <iostream>
#include "Map.hh"

Map::Map(int difficulty, char c) : 
	height{5*difficulty*2},
	width{5*difficulty},
	map_array{new char*[height]}
{
	for (int i = 0; i < height; i++) {
		map_array[i] = new char[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map_array[i][j] = c;
		}
	}
}

void Map::UpdateCell(int x, int y, char c) {
	map_array[x][y] = c;
}

void Map::PrintMap() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << map_array[i][j];
		}
		std::cout << "\n";
	}
}

int Map::getHeight() {
	return height;
}

int Map::getWidth() {
	return width;
}

Map::~Map() {
	for (int i = 0; i < height; i++) {
		delete[] map_array[i];
	}
	delete[] map_array;
}