#include "player_input_service.h"
#include <iostream>
#include "ui_utils.h"
#include "player.h"

namespace core
{
	namespace services
	{
		core::enums::CommandType player_input::askPlayerMove()
		{
			char input;

			while (true)
			{
				std::cout << "> ";
				std::cin >> input;

				if (!std::isalpha(input))
				{
					std::cout << "Ungültige Eingabe, benutze 'h' für das Hilfs-Kontext-Menü.\n";
					continue;
				}

				switch (std::tolower(input))
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

		void player_input::handlePlayerMove(core::enums::CommandType command, game::entities::Player& player)
		{
			switch (command)
			{
			case core::enums::CommandType::MoveUp:
				player.move(core::data::Vector2{ 0, -1 });
				break;

			case core::enums::CommandType::MoveDown:
				player.move(core::data::Vector2{ 0, 1 });
				break;

			case core::enums::CommandType::MoveLeft:
				player.move(core::data::Vector2{ -1, 0 });
				break;

			case core::enums::CommandType::MoveRight:
				player.move(core::data::Vector2{ 1, 0 });
				break;

			case core::enums::CommandType::Dig:
				if (!player.hasItem(core::enums::ItemType::FirstMapPart) || !player.hasItem(core::enums::ItemType::SecondMapPart))
				{
					std::cout << "Du kannst nicht ohne einer vollständigen Karte nach dem Schatz graben.\n";
					core::utils::ui::wait();

					return;
				}

				break;

			case core::enums::CommandType::Help:
				std::cout << "Benutze 'w', 'a', 's', 'd' um dich zu bewegen.\n";
				core::utils::ui::wait();
				break;
			}
		}
	}
}