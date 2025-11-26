#pragma once
#include "command_type.h"

namespace game 
{
	namespace entities 
	{ 
		class Player; 
	}
}

namespace core
{
	namespace services
	{
		namespace player_input
		{
			// Asks player to make a move.
			core::enums::CommandType askPlayerMove();

			// Processes a player command.
			void handlePlayerMove(core::enums::CommandType command, game::entities::Player& player);
		};
	}
}