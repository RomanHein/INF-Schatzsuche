#include "map_controller.h"
#include <iostream>
#include "math_utils.h"
#include "player.h"

namespace core
{
	namespace controllers
	{
		//
		// === Constructor ===
		//

		Map::Map(game::entities::Player& player, const core::data::Vector2& mapSize) :
			player_(player),
			map_(mapSize.y, std::vector<char>(mapSize.x, '.')),
			eventManager_(player)
		{ 
			this->initMapEvents();
		}

		//
		// === Private Methods ===
		//

		core::data::Vector2 Map::getRandomPoint()
		{
			while (true)
			{
				core::data::Vector2 point = core::utils::math::randomPoint(0, this->map_[0].size() - 1, 0, this->map_.size() - 1);

				if (this->mapEventIds_.find(point) == this->mapEventIds_.end())
				{
					return point;
				}
			}
		}

		void Map::initMapEvents()
		{
			for (int i = 0; i < 2; i++)
			{
				int eventId = this->eventManager_.createConditionalEvent(
					[](game::entities::Player& player) -> bool {
						if (player.hasFullInventory())
						{
							std::cout << "Dein Inventar ist voll!\n";
							return false;
						}

						return true;
					},
					[](game::entities::Player& player) -> void {
						player.addItem("Schaufel");
						std::cout << "Du hast eine Schaufel gefunden!\n";
					}
				);

				auto point = this->getRandomPoint();

				this->mapEventIds_[point] = eventId;
				this->map_[point.y][point.x] = 'S';
			}
		}

		//
		// === Public Methods ===
		//

		// Draw every character inside map_, if x y is player position, draw player instead of tile.
		void Map::drawMap()
		{
			for (int y = 0; y < map_.size(); y++)
			{
				for (int x = 0; x < map_[y].size(); x++)
				{
					// Player has highest draw priority.
					if (this->player_.getPosition() == core::data::Vector2{ x, y })
					{
						std::cout << "O ";
					}
					else
					{
						std::cout << this->map_[y][x] << " ";
					}
				}

				std::cout << "\n";
			}
		}

		// Check what tile the player is standing on and determine an event.
		void Map::handleMapEvent() 
		{
			auto playerPosition = this->player_.getPosition();
			auto it = this->mapEventIds_.find(playerPosition);

			// Player not standing on an event.
			if (it == this->mapEventIds_.end())
			{
				return;
			}

			int eventId = it->second;

			if (this->eventManager_.trigger(eventId))
			{
				this->map_[playerPosition.y][playerPosition.x] = '.';
			}
		}
	}
}