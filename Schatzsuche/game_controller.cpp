#include "game_controller.h"
#include <cstdlib>
#include <locale>
#include <ctime>
#include "command_type.h"
#include "ui_utils.h"
#include "vector_2.h"
#include "player_input_service.h"

namespace core
{
	namespace controllers
	{
		Game::Game() :
			player_(game::entities::Player("Spieler", 9, 12)),
			mapController_(core::controllers::Map(this->player_, core::data::Vector2{ 10, 10 }))
		{ }

		void Game::init()
		{
			std::locale::global(std::locale("de_DE"));
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
		}

		void Game::start()
		{
			while (true)
			{
				this->mapController_.drawMap();
				this->mapController_.handleMapEvent();

				core::enums::CommandType playerCommand = core::services::player_input::askPlayerMove();
				core::services::player_input::handlePlayerMove(playerCommand, this->player_);

				core::utils::ui::clearConsole();
			}
		}
	}
}