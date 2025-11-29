#pragma once

namespace game
{
	namespace entities
	{
		class Player;
	}
}

namespace core
{
	namespace services
	{
		namespace context_ui
		{
			// Prints the player's status such as stamina and etc. to the console.
			void showPlayerStatus(const game::entities::Player& player);

			// Prints the player's inventories to the console.
			void showPlayerInventory(const game::entities::Player& player);

			void showDeathScreen();

			void showVictoryScreen();
		};
	}
}