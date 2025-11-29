// Game Controller
//
// The main controller of the game.
// Responsible for using other controllers to direct the game.

#pragma once
#include "player.h"
#include "map_controller.h"

namespace core
{
	namespace controllers
	{
		class Game
		{
		private:
			game::entities::Player player_;
			core::controllers::Map mapController_;
			bool playerFoundTreasure_ = false;

		public:
			//
			// === Constructor ===
			//

			explicit Game();

			//
			// === Public Methods ===
			//

			// Initializes the game.
			void init();

			// Starts the game.
			void start();

			//
			// === Getters ===
			//
		};
	}
}