// Event Manager
//
// Simple helper component which manages and stores events.
// Was created to help creating events more easily with optional conditions and so on.
// Mainly used in Map Controller for making item pickup events.

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
			explicit EventManager(game::entities::Player& player_);

			// Triggers an event by its event id. Returns true if event finished successfully.
			bool trigger(int eventId);

			// Creates a simple event and returns its event id.
			int createEvent(std::function<void(game::entities::Player& player)>);

			// Creates an event with a condition and returns its event id.
			int createConditionalEvent(std::function<bool(game::entities::Player& player)>, std::function<void(game::entities::Player& player)>);
		};

	}
}