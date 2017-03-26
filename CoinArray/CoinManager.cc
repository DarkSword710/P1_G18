#include "CoinManager.hh"

CoinManager::CoinManager(Map &map, char c): map{map}, coinSymbol{ c }
{
	SetCoins();
}

void CoinManager::SetCoins() {
	float minCoins = map.getHeight() * map.getWidth() * 0.03;
	float maxCoins = map.getHeight() * map.getWidth() * 0.13;
	coins = minCoins + rand() % static_cast<int>(maxCoins - minCoins);
	for (int i = 0; i < coins; ) {
		int x = rand() % map.getWidth();
		int y = rand() % map.getHeight();
		if (map.getMapArray(x, y) == map.getEmptySymbol()) {
			map.UpdateCell(x, y, coinSymbol);
			i++;
		}
	}
}

void CoinManager::UpdateCoins() {
	coins--;
	if (coins == 0) {
		SetCoins();
	}
}

char CoinManager::getCoinSymbol() {
	return coinSymbol;
}

CoinManager::~CoinManager()
{
}