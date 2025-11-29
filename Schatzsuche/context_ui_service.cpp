#include "context_ui_service.h"
#include <iostream>
#include <string>
#include "player.h"

namespace core
{
	namespace services
	{
		// Prints the player's status such as stamina and etc. to the console.
		void context_ui::showPlayerStatus(const game::entities::Player& player)
		{
			std::cout << "Energie: " << player.getEnergy() << "\n";
		}

		// Prints the player's inventories to the console.
		void context_ui::showPlayerInventory(const game::entities::Player& player)
		{
			for (const std::string& item : player.getInventory())
			{
				std::cout << "- " << item << "\n";
			}
		}
	}
}