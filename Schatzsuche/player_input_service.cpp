#include "player_input_service.h"
#include <iostream>
#include "game_context.h"
#include "ui_utils.h"
#include "player.h"

//
// === Local Functions ===
//

bool isOutOfMap(const core::data::Vector2& pos, const core::data::Vector2& mapSize)
{
	return pos.x < 0 || pos.x >= mapSize.x || pos.y < 0 || pos.y >= mapSize.y;
}

namespace core
{
	namespace services
	{
		core::enums::CommandType player_input::askPlayerInput()
		{
			std::string input;

			while (true)
			{
				std::cout << "> ";
				std::getline(std::cin, input);

				// For some reason, it's impossible to save input in a char directly. (Programm proceses all of them, no idea why...)
				// Therefore we save input in a string and only process first char with [0].
				if (input.length() == 0)
				{
					continue;
				}

				if (!std::isalpha(input[0]))
				{
					std::cout << "Ungültige Eingabe, benutze 'h' für das Hilfs-Kontext-Menü.\n";
					continue;
				}

				switch (std::tolower(input[0]))
				{
				case 'w':
					return core::enums::CommandType::MoveUp;

				case 's':
					return core::enums::CommandType::MoveDown;

				case 'a':
					return core::enums::CommandType::MoveLeft;

				case 'd':
					return core::enums::CommandType::MoveRight;

				case 'h':
					return core::enums::CommandType::Help;

				case 'r':
					return core::enums::CommandType::ShowMap;

				case 'f':
					return core::enums::CommandType::Dig;

				default:
					std::cout << "Unbekannter Befehl, benutze 'h' für das Hilfs-Kontext-Menü.\n";
				}
			}
		}

		void player_input::handlePlayerInput(core::enums::CommandType command, core::data::GameContext gameContext)
		{
			switch (command)
			{
			case core::enums::CommandType::MoveUp:
				if (isOutOfMap(gameContext.player.getPosition() + core::data::Vector2{ 0, -1 }, gameContext.mapSize))
				{
					std::cout << "Du kannst das Spielfeld nicht verlassen.\n";
					core::utils::ui::wait();
					break;
				}

				gameContext.player.move(core::data::Vector2{ 0, -1 });
				gameContext.player.reduceEnergy();

				break;

			case core::enums::CommandType::MoveDown:
				if (isOutOfMap(gameContext.player.getPosition() + core::data::Vector2{ 0, 1 }, gameContext.mapSize))
				{
					std::cout << "Du kannst das Spielfeld nicht verlassen.\n";
					core::utils::ui::wait();
					break;
				}

				gameContext.player.move(core::data::Vector2{ 0, 1 });
				gameContext.player.reduceEnergy();

				break;

			case core::enums::CommandType::MoveLeft:
				if (isOutOfMap(gameContext.player.getPosition() + core::data::Vector2{ -1, 0 }, gameContext.mapSize))
				{
					std::cout << "Du kannst das Spielfeld nicht verlassen.\n";
					core::utils::ui::wait();
					break;
				}

				gameContext.player.move(core::data::Vector2{ -1, 0 });
				gameContext.player.reduceEnergy();

				break;

			case core::enums::CommandType::MoveRight:
				if (isOutOfMap(gameContext.player.getPosition() + core::data::Vector2{ 1, 0 }, gameContext.mapSize))
				{
					std::cout << "Du kannst das Spielfeld nicht verlassen.\n";
					core::utils::ui::wait();
					break;
				}

				gameContext.player.move(core::data::Vector2{ 1, 0 });
				gameContext.player.reduceEnergy();

				break;

			case core::enums::CommandType::ShowMap:
				if (!gameContext.player.hasItem("Kartenteil-1") || !gameContext.player.hasItem("Kartenteil-2"))
				{
					std::cout << "Du kannst nicht ohne einer vollständigen Karte nach dem Schatz schauen.\n";
					core::utils::ui::wait();
					break;
				}

				std::cout << "Der Schatz befindet sich an dem Punkt (" << gameContext.treasurePosition.x << ", " << gameContext.treasurePosition.y << ").\n";
				core::utils::ui::wait();

				break;

			case core::enums::CommandType::Dig:
				if (!gameContext.player.hasItem("Kartenteil-1") || !gameContext.player.hasItem("Kartenteil-2"))
				{
					std::cout << "Du kannst nicht ohne einer vollständigen Karte nach dem Schatz graben.\n";
					core::utils::ui::wait();
					break;
				}

				if (!gameContext.player.hasItem("Schaufel"))
				{
					std::cout << "Du kannst nicht ohne einer Schaufel nach dem Schatz graben.\n";
					core::utils::ui::wait();
					break;
				}

				if (gameContext.player.getPosition() != gameContext.treasurePosition)
				{
					std::cout << "Du hast nach dem Schatz gegraben aber nichts gefunden...\n";
					core::utils::ui::wait();
					break;
				}

				gameContext.playerFoundTreasure = true;

				break;

			case core::enums::CommandType::Help:
				std::cout << "<w>, <a>, <s>, <d>\n";
				std::cout << "Bewegt den Spieler.\n";
				std::cout << "<r>\n";
				std::cout << "Zeigt den Standort des Schatzes.\n";
				std::cout << "<f>\n";
				std::cout << "Gräbt nach dem Schatz an der zurzeitigen Stelle.\n";
				core::utils::ui::wait();

				break;
			}
		}
	}
}