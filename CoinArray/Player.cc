#include "Player.hh"

Player::Player(Map &map, CoinManager &coinManager, char c) :
	map{ map },
	coinManager{ coinManager },
	playerSymbol{ c },
	points{ 0 }
{
	SetPlayer();
}

void Player::SetPlayer() {
	bool emptyFound = false;
	do {
		x = rand() % map.getWidth();
		y = rand() % map.getHeight();
		if (map.getMapArray(x, y) == map.getEmptySymbol()) {
			emptyFound = true;
		}
	} while (!emptyFound);
	map.UpdateCell(x, y, playerSymbol);
}

void Player::MovePlayer(Input::Key key) {
	int variaX = 0;
	int variaY = 0;
	switch (key)
	{
	case Input::Key::W:
		variaY--;
		break;
	case Input::Key::A:
		variaX--;
		break;
	case Input::Key::S:
		variaY++;
		break;
	case Input::Key::D:
		variaX++;
		break;
	default:
		break;
	}
	if (x + variaX >= 0 && x + variaX < map.getWidth() && y + variaY >= 0 && y + variaY < map.getHeight()) {
		if (map.getMapArray(x + variaX, y + variaY) == coinManager.getCoinSymbol()) {
			points++;
			coinManager.UpdateCoins();
		}
		map.UpdateCell(x, y, map.getEmptySymbol());
		x += variaX;
		y += variaY;
		map.UpdateCell(x, y, playerSymbol);
	}
}

int Player::GetPoints() {
	return points;
};

Player::~Player()
{
}