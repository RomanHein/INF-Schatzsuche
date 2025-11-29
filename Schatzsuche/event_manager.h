// Event Manager
//
// Simple helper component which manages and stores events.
// Every component has its own events, stored by an event id. Was created to keep events modular and central.
// Mainly used in Map Controller to handle item pickup events and more.

#pragma once
#include <unordered_map>
#include <functional>
#include "event.h"

namespace game
{
	namespace entities
	{
		class Player;
	}
}

namespace core
{
	namespace components
	{
		class EventManager
		{
		private:
			game::entities::Player& player_;
			std::unordered_map<int, core::data::Event> events_;
			int nextEventID_ = 0;

		public:
			//
			// === Constructor ===
			//

			explicit EventManager(game::entities::Player& player_);

			//
			// === Public Methods ===
			//

			// Triggers an event by its event id. Returns true if event finished successfully.
			bool trigger(int eventId);

			// Removes a registered event by its event id.
			void erase(int eventId);

			// Creates a simple event and returns its event id.
			int createEvent(std::function<void(game::entities::Player& player)>);

			// Creates an event with a condition and returns its event id.
			int createConditionalEvent(std::function<bool(game::entities::Player& player)>, std::function<void(game::entities::Player& player)>);
		};

	}
}