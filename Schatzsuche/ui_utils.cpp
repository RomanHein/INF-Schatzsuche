#include "ui_utils.h"
#include <iostream>

namespace core
{
	namespace utils
	{
		namespace ui
		{
			void ui::clearConsole()
			{
				std::cout << "\033[2J\033[1;1H";
			}

			void ui::wait()
			{
				std::cout << "Drücke um fortzufahren...";
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
		}
	}
}