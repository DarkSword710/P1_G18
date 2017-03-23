#include <ctime>
#include "CoinManager.hh"
#include "Map.hh"
#include "Player.hh"

int main(void) {
	srand(static_cast <unsigned>(time(nullptr)));
	Map map(2, '.');
	map.PrintMap();
}