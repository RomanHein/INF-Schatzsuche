// Game UI Service
//
// Functions for displaying important, game-related information to the console.

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
		namespace game_ui
		{
			// Prints the player's status such as stamina and etc. to the console.
			void showPlayerStatus(const game::entities::Player& player);

			// Prints the player's inventories to the console.
			void showPlayerInventory(const game::entities::Player& player);

			// Prints the player's death screen to the console.
			void showDeathScreen();

			// Prints the game victory screen to the console.
			void showVictoryScreen();

			// Prints a simple line to the console which seperates the map from the rest of the UI.
			void printMapSeperator(int mapWidth);
		};
	}
}