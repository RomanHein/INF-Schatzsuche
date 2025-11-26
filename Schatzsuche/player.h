#pragma once
#include <string>
#include <vector>
#include "item_type.h"
#include "vector_2.h"

namespace game
{
	namespace entities
	{
		class Player
		{
		private:
			std::string name_;
			int energy_, maxEnergy_;
			core::data::Vector2 position_;
			std::vector<core::enums::ItemType> inventory_;

		public:
			//
			// === Constructor ===
			//

			explicit Player(const std::string& name, int energy, int maxEnergy);

			//
			// === Public Methods ===
			//

			// Reduces the player's energy by 1.
			void reduceEnergy();

			// Increases the player's energy by the given amount.
			void increaseEnergy(int amount);

			// Increments the player's position by delta.
			void move(const core::data::Vector2& delta);

			// Adds the given item into the player's inventory.
			void addItem(core::enums::ItemType item);

			//
			// === Predicate Methods ===
			//

			// Returns true if the player's energy is 0.
			bool isExhausted() const;

			// Returns true if player has an item with the given item name in his inventory.
			bool hasItem(core::enums::ItemType item);

			// === Getters ===

			const core::data::Vector2& getPosition() const;
		};
	}
}

