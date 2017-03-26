#pragma once
#include <iostream>

class Map
{
public:
	Map(int difficulty, char c); //Constructor del mapa en  funció de la dificultat
	void UpdateCell(int x, int y, char c); //Actualizta el contingut d'una casella de l'array del mapa
	void PrintMap(); //Imprimeix el mapa en pantalla
	int getHeight(); //Reotorna l'alçada del mapa
	int getWidth(); //Retorna l'amplada del mapa
	int getEmptySymbol(); //Retorna el símbol de casella buida del mapa
	char getMapArray(int x, int y); //Retorna el que es troba en la posició x y del array dinámic on s'emmagatzema el mapa
	~Map(); //Destructor del mapa. Destrueix l'array dinámic.

private:
	char** map_array; //Array dinámic de 2 dimensions on s'emmagatzema el mapa
	int width; //Amplada del mapa
	int height; //Alçada del mapa
	char emptySymbol; //Símbol que senyalitza al mapa les caselles buides
};