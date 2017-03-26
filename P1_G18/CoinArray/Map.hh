#pragma once
#include <iostream>

class Map
{
public:
	Map(int difficulty, char c); //Constructor del mapa en  funci� de la dificultat
	void UpdateCell(int x, int y, char c); //Actualizta el contingut d'una casella de l'array del mapa
	void PrintMap(); //Imprimeix el mapa en pantalla
	int getHeight(); //Reotorna l'al�ada del mapa
	int getWidth(); //Retorna l'amplada del mapa
	int getEmptySymbol(); //Retorna el s�mbol de casella buida del mapa
	char getMapArray(int x, int y); //Retorna el que es troba en la posici� x y del array din�mic on s'emmagatzema el mapa
	~Map(); //Destructor del mapa. Destrueix l'array din�mic.

private:
	char** map_array; //Array din�mic de 2 dimensions on s'emmagatzema el mapa
	int width; //Amplada del mapa
	int height; //Al�ada del mapa
	char emptySymbol; //S�mbol que senyalitza al mapa les caselles buides
};