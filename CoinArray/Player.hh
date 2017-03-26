#pragma once
#include "Map.hh"
#include "CoinManager.hh"
#include "Input.hh"

class Player
{
public:
	Player(Map &map, CoinManager &coinManager, char c);
	void SetPlayer();
	void MovePlayer(Input::Key key);
	int GetPoints();
	~Player();

private:
	char playerSymbol;
	int x;
	int y;
	int points;
	Map &map;
	CoinManager &coinManager;
};