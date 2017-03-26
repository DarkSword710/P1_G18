#include "Player.hh"

Player::Player(Map &map, CoinManager &coinManager, char c) : //Constructor del Player
	map{ map },
	coinManager{ coinManager },
	playerSymbol{ c },
	points{ 0 } //El jugador comença amb puntuació 0
{
	bool emptyFound = false; //Variable booleana que controla si s'ha trobat un espai pel player al mapa
	do {
		x = rand() % map.getWidth(); //genera una posició x random on col·locar al player
		y = rand() % map.getHeight(); //genera una posició y random on col·locar al player
		if (map.getMapArray(x, y) == map.getEmptySymbol()) { //Si la posició esta buida
			emptyFound = true; //Considera que l'ha trobat
		}
	} while (!emptyFound); //Mentre no s'hagi trobat un espai buit al mapa
	map.UpdateCell(x, y, playerSymbol); //Quan es troba s'actualitza el mapa per mostrar al player.
}

void Player::MovePlayer(Input::Key key) {
	int variaX = 0; //Variació de la posició del jugador en l'eix x
	int variaY = 0; //Variació de la posició del jugador en l'eix y
	switch (key) //Segons la tecla presa
	{
	case Input::Key::W: //Si es W puja una casella
		variaY--;
		break;
	case Input::Key::A: //Si es A es mou una casella a l'esquerra
		variaX--;
		break;
	case Input::Key::S: //Si es S baixa una casella
		variaY++;
		break;
	case Input::Key::D: //Si es D es mou una casella a la dreta
		variaX++;
		break;
	default: //Si es qualsevol altre no es mou
		break;
	}
	//Si la casella es troba en els límits del mapa
	if (x + variaX >= 0 && x + variaX < map.getWidth() && y + variaY >= 0 && y + variaY < map.getHeight()) {
		if (map.getMapArray(x + variaX, y + variaY) == coinManager.getCoinSymbol()) { //Si en aquesta casella hi ha una moneda
			points++; //Suma 1 a la puntuació
			coinManager.UpdateCoins(); //Actualitza les monedes del mapa
		}
		map.UpdateCell(x, y, map.getEmptySymbol()); //Buida la casella on es trobaba el jugador
		x += variaX; //Actualitza la posició del jugador en x
		y += variaY; //Actualitza la posició del jugador en y
		map.UpdateCell(x, y, playerSymbol); //Col·loca al jugador en la seva nova posició
	}
}

int Player::GetPoints() {
	return points; //Retorna la puntuació del jugador
};

Player::~Player() //Destructor del Player
{
}