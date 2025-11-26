#pragma once
#include <vector>
#include <memory>
#include "vector_2.h"
#include "map_event.h"

namespace game
{
	namespace entities
	{
		class Player;
	}
}

namespace core
{
	namespace controllers
	{
		class Map
		{
		private:
			game::entities::Player& player_;
			std::vector<std::vector<std::unique_ptr<core::data::MapEvent>>> mapEvents_;
			core::data::Vector2 mapSize_;

		public:
			// === Constructor ===

			explicit Map(game::entities::Player& player, const core::data::Vector2& mapSize);

			// === Public Methods ===

			// Draws the current map to the console.
			void drawMap();

			// abc.
			void handleMapEvent();

			// Asks the player to make a move input.
			core::data::Vector2 askPlayerMove();
		};
	}
}