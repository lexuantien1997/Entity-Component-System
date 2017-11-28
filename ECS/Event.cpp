#include "Event.h"
#include "EventHandler.h"


Event::Event(EventId id)
{
	this->Id = id;
}

void Event::send()
{
	for (auto it =listeners.begin(); it !=listeners.end(); ++it)
	{
		EventHandler* eventHandler = *it;

		eventHandler->HandleEvent(this);
	}
}

void Event::sentToHandler(EventHandler* eventHandler)
{
	for (auto it = listeners.begin(); it != listeners.end(); ++it)
	{
		if (eventHandler == *it)
		{
			eventHandler->HandleEvent(this);
		}
	}
}

void Event::attachListener(EventHandler * eventHandler)
{
	listeners.push_back(eventHandler);
}

void Event::detachListener(EventHandler * eventHandler)
{
	for (auto it = listeners.begin(); it != listeners.end(); ++it)
	{
		if (eventHandler == *it)
		{
			listeners.erase(it); break;
		}
	}
}

Event::Event()
{
}


Event::~Event()
{
}
