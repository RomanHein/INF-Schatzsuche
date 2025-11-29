// INF Schatzsuche
//
// Kleines Spiel in dem das Ziel es ist, einen Schatz zu finden.
// Spieler muss Gegenstände sammeln und dabei auf seine Energie achten. Fällt sie auf 0, ist das Spiel vorbei.
// Auf der Karte findet man Beeren um Energie wiederherstellen zu können.

#include <cstdlib>
#include <ctime>
#include <locale>
#include "game_controller.h"

int main()
{
	std::srand(static_cast<unsigned int>(std::time(0)));
	std::locale::global(std::locale("de_DE"));

	core::controllers::Game gameController;
	gameController.start();
}