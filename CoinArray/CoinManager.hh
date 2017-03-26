#pragma once
#include "Map.hh"

class CoinManager
{
public:
	CoinManager(Map &map, char c);
	void SetCoins();
	void UpdateCoins();
	char getCoinSymbol();
	~CoinManager();

private:
	int coins;
	Map &map;
	char coinSymbol;
};