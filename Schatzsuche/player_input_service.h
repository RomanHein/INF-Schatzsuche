// Player Input Service
//
// Manages the validation and processing of the player's input.
// Firstly translates the input into an enum and then handles it based on the current game context.

#pragma once
#include "command_type.h"

namespace core 
{
	namespace data 
	{ 
		struct GameContext; 
	}
}

namespace core
{
	namespace services
	{
		namespace player_input
		{
			// Asks player to make a move.
			core::enums::CommandType askPlayerInput();

			// Processes a player command.
			void handlePlayerInput(core::enums::CommandType command, core::data::GameContext gameContext);
		};
	}
}