// Map Controller
//
// Responsible for the map.
// Mainly manages drawing the map to the console and storing the current state of the map.
// Also stores events and handles them appropriately.

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
			std::vector<std::vector<char>> map_;
			core::data::Vector2 treasurePosition_;
			std::map<core::data::Vector2, int> mapEventIds_;
			core::components::EventManager eventManager_;

			//
			// === Private Methods ===
			//

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
			void drawMap() const;

			// Checks for any events and handles them.
			void handleMapEvent();

			//
			// === Getters ===
			//

			core::data::Vector2 getMapSize() const;
			const core::data::Vector2& getTreasurePosition() const;
		};
	}
}