#include "CoinManager.hh"

CoinManager::CoinManager(Map &map, char c):
	map{ map }, //Mapa on es troben les monedes
	coinSymbol{ c } //Símbol de les monedes
{
	SetCoins(); //Col·loca monedes al mapa
}

void CoinManager::SetCoins() {
	float minCoins = map.getHeight() * map.getWidth() * 0.03; //Com a mínim hi haurá monedes equivalents al 3% de les dimensions del mapa
	float maxCoins = map.getHeight() * map.getWidth() * 0.13; //Com a máxim hi haura monedes equivalents al 13% de les dimensions del mapa
	coins = minCoins + rand() % static_cast<int>(maxCoins - minCoins); //Genera una quantitat de monedes aleatoria en funció del marge
	
	int i = 0;
	while (i < coins) {
		int x = rand() % map.getWidth();
		int y = rand() % map.getHeight();
		if (map.getMapArray(x, y) == map.getEmptySymbol()) {
			map.UpdateCell(x, y, coinSymbol); //Genera posicions aleatories per les monedes i les col·loca en espais buits del mapa
			i++;
		}
	}
}

void CoinManager::UpdateCoins() {
	coins--; //Resta 1 a la quantitat de monedes
	if (coins == 0) { 
		SetCoins(); //Si no en queden en genera més
	}
}

char CoinManager::getCoinSymbol() {
	return coinSymbol; //Retorna el símbol representatiu de les monedes
}

CoinManager::~CoinManager() //Destructor de la classe
{
}