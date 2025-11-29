// Player
// 
// The entity which represents the player.

#pragma once
#include <string>
#include <vector>
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
			std::vector<std::string> inventory_;
			int inventoryCapacity_;

		public:
			//
			// === Constructor ===
			//

			explicit Player(const std::string& name, int energy, int maxEnergy, int inventoryCapacity);

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
			void addItem(std::string item);

			// Increases the player's inventory capacity.
			void expandInventory(int slots);

			//
			// === Predicate Methods ===
			//

			// Returns true if the player's energy is 0.
			bool isExhausted() const;

			// Returns true if player has an item with the given item name in his inventory.
			bool hasItem(std::string item) const;

			// Returns true if the player's inventory size is equal to his inventory capacity.
			bool hasFullInventory() const;

			//
			// === Getters ===
			//

			const core::data::Vector2& getPosition() const;
			int getEnergy() const;
			int getMaxEnergy() const;
			const std::vector<std::string>& getInventory() const;
		};
	}
}

