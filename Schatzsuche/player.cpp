#include "player.h"
#include <algorithm>

namespace game
{
	namespace entities
	{
		// === Constructor ===

		Player::Player(const std::string& name, int energy, int maxEnergy) :
			name_(name),
			energy_(energy),
			maxEnergy_(maxEnergy),
			position_(core::data::Vector2{ 0, 0 })
		{ }

		// === Public Methods ===

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

		void Player::addItem(core::enums::ItemType item)
		{
			this->inventory_.push_back(item);
		}

		// === Predicate Methods ===

		bool Player::isExhausted() const
		{
			return this->energy_ == 0;
		}

		bool Player::hasItem(core::enums::ItemType item)
		{
			return std::find_if(this->inventory_.begin(), this->inventory_.end(), 
				[&item](const core::enums::ItemType item_) { return item_ == item; }
			) != this->inventory_.end();
		}

		// === Getters ===

		const core::data::Vector2& Player::getPosition() const
		{
			return this->position_;
		}
	}
}