#include "game_ui_service.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "player.h"

namespace core
{
	namespace services
	{
		void game_ui::showPlayerStatus(const game::entities::Player& player)
		{
			std::cout << "Energie: " << player.getEnergy() << "\n";
		}

		void game_ui::showPlayerInventory(const game::entities::Player& player)
		{
			auto inventory = player.getInventory();

			std::cout << "Gegenstände: ";

			for (int i = 0, size = inventory.size(); i < size; i++)
			{
				std::cout << inventory[i] << (i < size - 1 ? ", " : "");
			}

			std::cout << "\n";
		}

		void game_ui::showDeathScreen()
		{
			std::cout << "Du hast deine gesamte Ausdauer verbraucht und bist durch\n";
			std::cout << "Erschöpfung gestorben!\n";
		}

		void game_ui::showVictoryScreen()
		{
			std::cout << "Du hast den Schatz gefunden!\n";
		}

		void game_ui::printMapSeperator(int mapWidth)
		{
			std::cout << std::setfill('-') << std::setw(mapWidth * 2 - 1) << "" << "\n";
		}
	}
}