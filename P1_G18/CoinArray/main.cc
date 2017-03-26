#include <ctime>
#include <cstdlib>
#include "CoinManager.hh"
#include "Map.hh"
#include "Player.hh"

int main(void) {
	srand(static_cast <unsigned>(time(nullptr))); //Per tal de que els valors aleatoris no siguinels mateixos cada vegada que s'inicia el programa
	int difficulty; //1 - EASY, 2 - MEDIUM, 3 - HARD
	int minDifficulty = 1;
	int maxDifficulty = 3; //Per evitar numerals mágics
	char nothing = '.'; //Símbol del mapa per a les caselles buides
	char coin = '$'; //Símbol del mapa per a les monedes
	char playerIcon = '@'; //Símbol del mapa per al jugador

	//Pantalla inicial

	std::cout << "//////////////////////////////////////////////////////////" << std::endl <<
				 "                        COIN RACE                         " << std::endl <<
				 "//////////////////////////////////////////////////////////" << std::endl << std::endl <<
				 "Controls: Use WASD to move the player" << std::endl << std::endl <<
				 "Choose a difficulty entering one of the following numbers:" << std::endl <<
				 "1 - EASY" << std::endl <<
				 "2 - MEDIUM" << std::endl <<
				 "3 - HARD" << std::endl;
	do
	{
		std::cin >> difficulty;
	} while (difficulty > maxDifficulty || difficulty < minDifficulty); //Comprova que la dificultat sigui entre 1 i 3

	//Inizialització de les classes

	Map map(difficulty, nothing);
	CoinManager coinManager(map, coin);
	Player player(map, coinManager, playerIcon);



	int goal = 30 * difficulty + rand() % (30 * difficulty); //Puntuació objectiu
	int startTime = clock();

	//Primera impresió del mapa

	system("cls");
	map.PrintMap();
	std::cout << "Score: " << player.GetPoints() << "/" << goal << std::endl;

	//Variable per emmagatzemar la tecla presa

	Input::Key key;

	//Bucle del joc

	do
	{
		key = Input::getKey(); //Detecta la tecla presa
		if (key != Input::Key::NONE) { //Si s'ha pres una tecla rellevant la utilitza

			player.MovePlayer(key); //Crida a la funció que mou al jugador y actualitza totes les variables pertinents

			system("cls");
			map.PrintMap(); //Imprimeix el mapa actualitzat
			std::cout << "Score: " << player.GetPoints() << "/" << goal << std::endl;
		}
	} while (player.GetPoints() < goal && key != Input::Key::ESC);

	//El bucle continua mentre no s'hagin aconseguit tots els punts o no es premi ESC

	//Impresió del resultat de la partida

	system("cls");
	std::cout << "Game ended" << std::endl <<
	"Final score: " << player.GetPoints() << "/" << goal << std:: endl <<
	"Time: " << static_cast<int>((clock() - startTime) / 1000);
	return 0;
}