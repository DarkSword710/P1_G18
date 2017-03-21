#include "Map.hh"

class CoinManager
{
public:
	CoinManager(Map &map);
	void SetCoins();
	~CoinManager();

private:
	int coins;
	Map &map;
};