#include "Map.hh"

Map::Map(int difficulty, char c) : //Constructor del mapa
	height{ 5 * difficulty + rand() % 5 * difficulty}, //Genera l'alçada del mapa de manera aleatoria compresa entre [5*difficulty, 5*difficulty*2)
	width{ 5 * difficulty + rand() % 5 * difficulty}, //Genera l'amplada del mapa de manera aleatoria compresa entre [5*difficulty, 5*difficulty*2)
	emptySymbol{ c } //Símbol de casella buida
{
	map_array = new char*[height]; //Inicialitza un array de punters al Heap
	for (int i = 0; i < height; i++) {
		map_array[i] = new char[width]; //Recorre l'array de punters creant un nou array 2D al Heap
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map_array[i][j] = c; //Omple aquest array amb caselles buides
		}
	}
}

void Map::UpdateCell(int x, int y, char c) {
	map_array[y][x] = c; //Actualitza la casella x, y de l'array per que contingui el char c
}

void Map::PrintMap() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			std::cout << map_array[i][j]; //Recorre el array en bucle imprimint les diferents caselles per files
		}
		std::cout << std::endl;
	}
}

int Map::getHeight() {
	return height; //Retorna l'alçada del mapa
}

int Map::getWidth() {
	return width; //Retorna l'amplada del mapa
}

int Map::getEmptySymbol() {
	return emptySymbol; //Retorna el símbol de casella buida del mapa
}

char Map::getMapArray(int x, int y) {
	return map_array[y][x]; //Retorna el char que es troba en l'espai x, y de l'array
}

Map::~Map() {
	for (int i = 0; i < height; i++) {
		delete[] map_array[i]; //Destrueix l'array 2D del heap
	}
	delete[] map_array; //Destrueix l'array de punters al heap que apuntaven a l'array anterior
}