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