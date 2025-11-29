#include "game_controller.h"
#include <iostream>
#include "command_type.h"
#include "ui_utils.h"
#include "vector_2.h"
#include "game_context.h"
#include "player_input_service.h"
#include "game_ui_service.h"

namespace core
{
	namespace controllers
	{
		Game::Game() :
			player_(game::entities::Player("Spieler", 10, 12, 2)),
			mapController_(core::controllers::Map(this->player_, core::data::Vector2{ 10, 10 }))
		{ }

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

				core::services::game_ui::printMapSeperator(this->mapController_.getMapSize().x);

				core::services::game_ui::showPlayerStatus(this->player_);
				core::services::game_ui::showPlayerInventory(this->player_);

				core::enums::CommandType playerCommand = core::services::player_input::askPlayerInput();
				core::services::player_input::handlePlayerInput(playerCommand, core::data::GameContext{
					this->player_,
					this->mapController_.getMapSize(),
					this->mapController_.getTreasurePosition(),
					this->playerFoundTreasure_
				});

				if (this->playerFoundTreasure_)
				{
					core::services::game_ui::showVictoryScreen();
					break;
				}

				if (this->player_.isExhausted())
				{
					core::services::game_ui::showDeathScreen();
					break;
				}

				core::utils::ui::clearConsole();
			}

			// TODO: Handle game outcome.
		}
	}
}