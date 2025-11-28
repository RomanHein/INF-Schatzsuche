#include "game_controller.h"
#include <iostream>

int main()
{
	core::controllers::Game gameController;
	gameController.init();
	gameController.start();
}