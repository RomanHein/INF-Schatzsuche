// Event
//
// POD used by Event Manager.

#pragma once
#include <functional>

namespace game
{
	namespace entities
	{
		class Player;
	}
}

namespace core
{
	namespace data
	{
		struct Event
		{
			std::function<bool(game::entities::Player& player)> condition;
			std::function<void(game::entities::Player& player)> action;
		};
	}
}