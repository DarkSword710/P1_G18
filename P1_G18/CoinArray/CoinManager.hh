#pragma once
#include "Map.hh"

class CoinManager
{
public:
	CoinManager(Map &map, char c); //Constructor del CoinManager. Inicialitza les monedes al mapa
	void SetCoins(); //Col·loca monedes al mapa en fucnió de les seves dimensions
	void UpdateCoins(); //Actualitza el nombre de monedes al mapa i, si no en queden, en col·loca més
	char getCoinSymbol(); //Retorna el símbol amb el que es mostren les monedes al mapa
	~CoinManager(); //Destructor de la clase CoinManager

private:
	int coins; //Quantitat de monedes al mapa
	Map &map; //Mapa on es troben les monedes
	char coinSymbol; //Símbol amb el que es mostren les monedes al mapa
};