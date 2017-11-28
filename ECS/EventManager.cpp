#include "EventManager.h"



void EventManager::sendEvent(EventId id)
{
	auto result = eventMap.find(id);

	if (result!=eventMap.end())
	{
		result->second->send();
	}
}

void EventManager::sendEventIdToHandler(EventId Id, EventHandler * eventHandler)
{
	auto result = eventMap.find(Id);

	if (result != eventMap.end())
	{
		result->second->sentToHandler(eventHandler);
	}
}

void EventManager::registerEvent(EventId Id)
{
	auto result = eventMap.find(Id);

	if (result == eventMap.end())
	{
		Event* newEvent = new Event(Id);

		eventMap.insert(pair<EventId, Event*>(Id, newEvent));
	}

}

void EventManager::attachEvent(EventId Id, EventHandler * eventHandler)
{
	auto result = eventMap.find(Id);

	if (result != eventMap.end())
	{
		result->second->attachListener(eventHandler);
	}
}

void EventManager::detachEvent(EventId Id, EventHandler * eventHandler)
{
	auto result = eventMap.find(Id);

	if (result != eventMap.end())
	{
		result->second->detachListener(eventHandler);
	}
}

EventManager::EventManager()
{
}


EventManager::~EventManager()
{
	for (auto it = eventMap.begin(); it != eventMap.end(); ++it) 
	{ 
		Event* pEvent = it->second;              
		if (pEvent) 
		{
			delete pEvent;                    
			it->second = NULL; 
		} 
	}
	eventMap.clear();
}

