// Game Context
//
// POD which contains general information about the current state of the game.
// Passed around instead of 10 parameters.

#pragma once

namespace core
{
	namespace data
	{
		struct Vector2;
	}
}

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
		struct GameContext
		{
			game::entities::Player& player;
			const core::data::Vector2& mapSize;
			const core::data::Vector2& treasurePosition;
			bool& playerFoundTreasure;
		};
	}
}