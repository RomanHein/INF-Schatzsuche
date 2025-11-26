#pragma once

#include "player.h"
#include "map_controller.h"

namespace core
{
	namespace controllers
	{
		class Game
		{
		private:
			game::entities::Player player_;
			core::controllers::Map mapController_;

		public:
			explicit Game();

			void init();
			void start();
		};
	}
}