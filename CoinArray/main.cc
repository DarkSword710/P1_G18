#include <ctime>
#include <cstdlib>
#include "CoinManager.hh"
#include "Map.hh"
#include "Player.hh"

int main(void) {
	srand(static_cast <unsigned>(time(nullptr)));
	int difficulty;
	char nothing = '.';
	char coin = '$';
	char playerIcon = '@';

	std::cout << "//////////////////////////////////////////////////////////" << std::endl <<
				 "                        COIN RACE                         " << std::endl <<
				 "//////////////////////////////////////////////////////////" << std::endl << std::endl <<
				 "Controls: Use WASD to move the player" << std::endl << std::endl <<
				 "Choose a difficulty entering one of the following numbers:" << std::endl <<
				 "1 - EASY" << std::endl <<
				 "2 - MEDIUM" << std::endl <<
				 "3 - HARD" << std::endl;

	std::cin >> difficulty;
	Map map(difficulty, nothing);
	CoinManager coinManager(map, coin);
	Player player(map, coinManager, playerIcon);
	int goal = 30 * difficulty + rand() % (30 * difficulty);
	system("cls");
	map.PrintMap();
	std::cout << "Score: " << player.GetPoints() << "/" << goal << std::endl;
	Input::Key key;

	do
	{
		key = Input::getKey();
		if (key != Input::Key::NONE) {
			system("cls");
			player.MovePlayer(key);
			map.PrintMap();
			std::cout << "Score: " << player.GetPoints() << "/" << goal << std::endl;
		}
	} while (player.GetPoints() < goal);

	system("cls");
	std::cout << "Game ended" << std::endl <<
	"Final score: " << player.GetPoints() << std:: endl <<
	"Time: " << static_cast<int>(clock() / 1000);
}