#include "CoinManager.hh"

CoinManager::CoinManager(Map &map, char c): map{map}, coinSymbol{ c }
{
	SetCoins();
}

void CoinManager::SetCoins() {
	int minCoins = map.getHeight() * map.getWidth() * 0.03;
	int maxCoins = map.getHeight() * map.getWidth() * 0.13;
	coins = minCoins + rand() % (maxCoins - minCoins);
	for (int i = 0; i > coins; ) {
		int x = rand() % map.getWidth();
		int y = rand() % map.getHeight();
		if (map.getMapArray(x, y) == map.getEmptySybol()) {
			map.UpdateCell(x, y, coinSymbol);
			i++;
		}
	}
}

CoinManager::~CoinManager()
{
}