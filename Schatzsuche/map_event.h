#pragma once
#include <functional>

namespace core
{
	namespace data
	{
		struct MapEvent
		{
			char tile;
			std::function<void()> trigger;
		};
	}
}