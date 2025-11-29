#include "event_manager.h"
#include "player.h"

namespace core
{
	namespace components
	{
		EventManager::EventManager(game::entities::Player& player) :
			player_(player)
		{ }

		bool EventManager::trigger(int eventId)
		{
			auto it = this->events_.find(eventId);

			// Invalid event id.
			if (it == this->events_.end())
			{
				return false;
			}

			core::data::Event& evt = it->second;

			// Check whether event requirements are met.
			if (evt.condition(this->player_))
			{
				evt.action(this->player_);
				return true;
			}

			return false;
		}

		void EventManager::erase(int eventId)
		{
			auto it = this->events_.find(eventId);

			if (it != this->events_.end())
			{
				this->events_.erase(it);
			}
		}

		int EventManager::createEvent(std::function<void(game::entities::Player& player)> event)
		{
			this->events_[this->nextEventID_] = core::data::Event{
				[](game::entities::Player&) -> bool { return true; },
				event
			};

			return this->nextEventID_++;
		}

		int EventManager::createConditionalEvent(std::function<bool(game::entities::Player& player)> condition, std::function<void(game::entities::Player& player)> action)
		{
			this->events_[this->nextEventID_] = core::data::Event{
				condition,
				action
			};

			return this->nextEventID_++;
		}
	}
}