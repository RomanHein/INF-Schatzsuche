#pragma once
#include <map>
#include <vector>
#include "vector_2.h"
#include "event_manager.h"

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
			std::map<core::data::Vector2, int> mapEventIds_;
			core::components::EventManager eventManager_;
			std::vector<std::vector<char>> map_;

			// Returns a random, empty, point on the map.
			core::data::Vector2 getRandomPoint();

			// Initializes all map events.
			void initMapEvents();

		public:
			//
			// === Constructor ===
			//

			explicit Map(game::entities::Player& player, const core::data::Vector2& mapSize);

			//
			// === Public Methods ===
			//

			// Draws the current map to the console.
			void drawMap();

			// abc.
			void handleMapEvent();
		};
	}
}