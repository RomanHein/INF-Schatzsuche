#include "map_controller.h"
#include <iostream>
#include "item_type.h"
#include "math_utils.h"
#include "player.h"

namespace core
{
	namespace controllers
	{
		Map::Map(game::entities::Player& player, const core::data::Vector2& mapSize) :
			player_(player),
			mapSize_(mapSize)
		{ 
			// Fill mapEvents with nullptrs.
			this->mapEvents_.resize(mapSize_.y);
			for (auto& row : this->mapEvents_) { row.resize(mapSize.x); }

			// Overwrite mapEvents with events.
			for (int i = 0; i < 2; i++)
			{
				int x, y;

				while (true) 
				{
					x = core::utils::math::randomInt(0, mapSize.x - 1);
					y = core::utils::math::randomInt(0, mapSize.y - 1);

					if (this->mapEvents_[y][x] == nullptr)
					{
						break;
					}
				}

				this->mapEvents_[y][x] = std::make_unique<core::data::MapEvent>(
					core::data::MapEvent{ 'K', [&player]() {
						player.addItem(core::enums::ItemType::Backpack);
						std::cout << "Item gefunden!";
					} }
				);
			}
		}

		// Draw every character inside map_, if x y is player position, draw player instead of tile.
		void Map::drawMap()
		{
			for (int y = 0; y < this->mapSize_.y; y++)
			{
				for (int x = 0; x < this->mapSize_.x; x++)
				{
					core::data::Vector2 currentPosition = { x, y };

					if (this->player_.getPosition() == currentPosition)
					{
						std::cout << "O ";
					}
					else if (this->mapEvents_[y][x] != nullptr)
					{
						std::cout << this->mapEvents_[y][x]->tile << " ";
					}
					else
					{
						std::cout << ". ";
					}
				}

				std::cout << "\n";
			}
		}

		// Check what tile the player is standing on and determine an event.
		void Map::handleMapEvent() 
		{
			std::unique_ptr<core::data::MapEvent>& mapEvent = mapEvents_[this->player_.getPosition().y][this->player_.getPosition().x];
			
			if (!mapEvent)
			{
				return;
			}
			else
			{
				mapEvent->trigger();
				mapEvent = nullptr;
			}
		}
	}
}