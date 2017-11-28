#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include "Singleton.h"
#include <map>
#include "Event.h"
#include "EventHandler.h"
using namespace std;

class EventManager:public Singleton<EventManager>
{
private:
	map<EventId, Event*> eventMap;
public:
	
	void sendEvent(EventId id, std::string func);

	void sendEventIdToHandler(EventId Id, EventHandler* eventHandler);

	void registerEvent(EventId eventId);

	void attachEvent(EventId eventId, EventHandler* eventHandler);
	
	void detachEvent(EventId eventId, EventHandler* eventHandler);

	EventManager();
	
	~EventManager();
};

#endif // !EVENTMANAGER_H_



