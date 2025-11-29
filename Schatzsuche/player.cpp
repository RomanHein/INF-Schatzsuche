#include "player.h"
#include <algorithm>

namespace game
{
	namespace entities
	{
		//
		// === Constructor ===
		//

		Player::Player(const std::string& name, int energy, int maxEnergy, int inventoryCapacity) :
			name_(name),
			energy_(energy),
			maxEnergy_(maxEnergy),
			position_(core::data::Vector2{ 0, 0 }),
			inventoryCapacity_(inventoryCapacity)
		{ }

		//
		// === Public Methods ===
		//

		void Player::reduceEnergy()
		{
			this->energy_ = std::max(0, this->energy_ - 1);
		}

		void Player::increaseEnergy(int amount)
		{
			this->energy_ = std::min(this->maxEnergy_, this->energy_ + amount);
		}

		void Player::move(const core::data::Vector2& delta)
		{
			this->position_ += delta;
		}

		void Player::addItem(std::string item)
		{
			if (this->inventory_.size() < this->inventoryCapacity_)
			{
				this->inventory_.push_back(item);
			}
		}

		void Player::expandInventory(int slots)
		{
			this->inventoryCapacity_ += slots;
		}

		//
		// === Predicate Methods ===
		//

		bool Player::isExhausted() const
		{
			return this->energy_ == 0;
		}

		bool Player::hasItem(std::string item) const
		{
			return std::find_if(this->inventory_.begin(), this->inventory_.end(), 
				[&item](const std::string item_) { return item_ == item; }
			) != this->inventory_.end();
		}

		bool Player::hasFullInventory() const
		{
			return this->inventory_.size() == this->inventoryCapacity_;
		}

		//
		// === Getters ===
		//

		const core::data::Vector2& Player::getPosition() const
		{
			return this->position_;
		}

		int Player::getEnergy() const
		{
			return this->energy_;
		}

		int Player::getMaxEnergy() const
		{
			return this->maxEnergy_;
		}

		const std::vector<std::string>& Player::getInventory() const
		{
			return this->inventory_;
		}
	}
}