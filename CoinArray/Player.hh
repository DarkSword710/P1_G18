#pragma once
#include "Map.hh"
#include "CoinManager.hh"
#include "Input.hh"

class Player
{
public:
	Player(Map &map, CoinManager &coinManager, char c); //Constructor de player. El col�loca al mapa.
	void MovePlayer(Input::Key key); //Mou el player segons la tecla
	int GetPoints(); //Retorna la puntuaci� deljugador
	~Player(); //Destructor del player

private:
	char playerSymbol; //S�mbol que representa al player
	int x; //Posici� en l'eix x del player al mapa
	int y; //Posici� en l'eix y del player al mapa
	int points; //Puntuaci� del player
	Map &map; //Mapa on es troba el player
	CoinManager &coinManager; //CoinManager que controla les monedes agafades pel player
};