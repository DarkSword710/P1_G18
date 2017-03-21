#include "CoinManager.hh"

CoinManager::CoinManager(Map &map): map{map}
{
	SetCoins();
}

void CoinManager::SetCoins() {
	int minCoins = map.getHeight() * map.getWidth() * 0.03;
	int maxCoins = map.getHeight() * map.getWidth() * 0.13;
	coins = 
}

CoinManager::~CoinManager()
{
}