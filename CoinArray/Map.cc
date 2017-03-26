#include "Map.hh"

Map::Map(int difficulty, char c) : 
	height{ 5 * difficulty + rand() % 5 * difficulty},
	width{ 5 * difficulty + rand() % 5 * difficulty},
	map_array{new char*[height]}, emptySymbol{ c }
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
	map_array[y][x] = c;
}

void Map::PrintMap() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << map_array[i][j];
		}
		std::cout << std::endl;
	}
}

int Map::getHeight() {
	return height;
}

int Map::getWidth() {
	return width;
}

int Map::getEmptySymbol() {
	return emptySymbol;
}

char Map::getMapArray(int x, int y) {
	return map_array[y][x];
}

Map::~Map() {
	for (int i = 0; i < height; i++) {
		delete[] map_array[i];
	}
	delete[] map_array;
}