// Command Type
//
// Player's input gets translated into commands.

#pragma once

namespace core
{
	namespace enums
	{
		enum class CommandType
		{
			MoveUp,
			MoveDown,
			MoveRight,
			MoveLeft,
			Dig,
			Help,
			ShowMap
		};
	}
}