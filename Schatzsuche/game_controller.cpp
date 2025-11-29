#include "game_controller.h"
#include <cstdlib>
#include <iostream>
#include <locale>
#include <ctime>
#include "command_type.h"
#include "ui_utils.h"
#include "vector_2.h"
#include "game_context.h"
#include "player_input_service.h"
#include "context_ui_service.h"

namespace core
{
	namespace controllers
	{
		Game::Game() :
			player_(game::entities::Player("Spieler", 9, 12, 3)),
			mapController_(core::controllers::Map(this->player_, core::data::Vector2{ 10, 10 }))
		{ }

		void Game::init()
		{
			std::locale::global(std::locale("de_DE"));
			std::srand(static_cast<unsigned int>(std::time(0)));
		}

		void Game::start()
		{

			// Main event loop of the game. Follows this order:
			// 1. Draw map and handle events e.g. player found shovel or etc.
			// 2. Handle player input.
			// 3. Check whether player found treasure or died of exhaustion.
			while (true)
			{
				this->mapController_.drawMap();
				this->mapController_.handleMapEvent();

				core::services::context_ui::showPlayerStatus(this->player_);

				core::enums::CommandType playerCommand = core::services::player_input::askPlayerInput();
				core::services::player_input::handlePlayerInput(playerCommand, core::data::GameContext{
					this->player_,
					this->mapController_.getMapSize(),
					this->mapController_.getTreasurePosition(),
					this->playerFoundTreasure_
				});

				if (this->playerFoundTreasure_ || this->player_.isExhausted())
				{
					break;
				}

				core::utils::ui::clearConsole();
			}

			// TODO: Handle game outcome.
		}
	}
}