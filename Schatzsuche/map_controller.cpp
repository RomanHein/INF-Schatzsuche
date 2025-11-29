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

		Map::Map(game::entities::Player& player, const core::data::Vector2& mapSize, int totalBerries) :
			player_(player),
			map_(mapSize.y, std::vector<char>(mapSize.x, '.')),
			treasurePosition_(core::utils::math::randomPoint(0, mapSize.x - 1, 0, mapSize.y - 1)),
			eventManager_(player)
		{ 
			core::data::Vector2 point;
			int eventId;

			// Berries.
			for (int i = 0; i < totalBerries; i++)
			{
				eventId = this->eventManager_.createEvent(
					[](game::entities::Player& player) -> void {
						player.increaseEnergy(5);
						std::cout << "Du hast eine Beere gefunden (+3 Energie)!\n";
					}
				);

				point = this->getRandomPoint();

				this->mapEventIds_[point] = eventId;
				this->map_[point.y][point.x] = 'B';
			}

			// Shovel.
			eventId = this->eventManager_.createConditionalEvent(
				[](game::entities::Player& player) -> bool {
					if (player.hasFullInventory())
					{
						std::cout << "Dein Inventar ist voll! Such nach einem Rucksack.\n";
						return false;
					}

					return true;
				},
				[](game::entities::Player& player) -> void {
					player.addItem("Schaufel");
					std::cout << "Du hast eine Schaufel gefunden!\n";
				}
			);

			point = this->getRandomPoint();

			this->mapEventIds_[point] = eventId;
			this->map_[point.y][point.x] = 'S';

			// First map part.
			eventId = this->eventManager_.createConditionalEvent(
				[](game::entities::Player& player) -> bool {
					if (player.hasFullInventory())
					{
						std::cout << "Dein Inventar ist voll! Such nach einem Rucksack.\n";
						return false;
					}

					return true;
				},
				[](game::entities::Player& player) -> void {
					player.addItem("Kartenteil-1");
					std::cout << "Du hast ein Kartenteil gefunden!\n";
				}
			);

			point = this->getRandomPoint();

			this->mapEventIds_[point] = eventId;
			this->map_[point.y][point.x] = 'K';

			// Second map part.
			eventId = this->eventManager_.createConditionalEvent(
				[](game::entities::Player& player) -> bool {
					if (player.hasFullInventory())
					{
						std::cout << "Dein Inventar ist voll! Such nach einem Rucksack.\n";
						return false;
					}

					return true;
				},
				[](game::entities::Player& player) -> void {
					player.addItem("Kartenteil-2");
					std::cout << "Du hast ein Kartenteil gefunden!\n";
				}
			);

			point = this->getRandomPoint();

			this->mapEventIds_[point] = eventId;
			this->map_[point.y][point.x] = 'K';

			// Backpack.
			eventId = this->eventManager_.createEvent(
				[](game::entities::Player& player) -> void {
					player.expandInventory(1);
					std::cout << "Du hast einen Rucksack gefunden!\n";
				}
			);

			point = this->getRandomPoint();

			this->mapEventIds_[point] = eventId;
			this->map_[point.y][point.x] = 'R';
		}

		//
		// === Private Methods ===
		//

		core::data::Vector2 Map::getRandomPoint()
		{
			while (true)
			{
				core::data::Vector2 point = core::utils::math::randomPoint(0, static_cast<int>(this->map_[0].size()) - 1, 0, static_cast<int>(this->map_.size() - 1));

				// Check if generated point is already in use.
				if (this->mapEventIds_.find(point) == this->mapEventIds_.end())
				{
					return point;
				}
			}
		}

		//
		// === Public Methods ===
		//

		void Map::drawMap() const
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

			// Check if event triggers successfully and delete it.
			if (this->eventManager_.trigger(eventId))
			{
				this->map_[playerPosition.y][playerPosition.x] = '.';
				this->eventManager_.erase(eventId);
				this->mapEventIds_.erase(it);
			}
		}

		//
		// === Getters ===
		//
		
		core::data::Vector2 Map::getMapSize() const
		{
			return core::data::Vector2{ static_cast<int>(this->map_[0].size()), static_cast<int>(this->map_.size()) };
		}

		const core::data::Vector2& Map::getTreasurePosition() const
		{
			return this->treasurePosition_;
		}
	}
}