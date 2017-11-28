#ifndef EVENT_H_
#define EVENT_H_

#include <vector>
#include "EventId.h"
using namespace std;

class EventHandler;

class Event
{
private:
	vector<EventHandler*> listeners;
	
	EventId Id;

public:

	Event(EventId id);

	void send(std::string a);

	void sentToHandler(EventHandler* eventHandler);

	void attachListener(EventHandler* eventHandler);

	void detachListener(EventHandler* eventHandler);

	EventId getId() { return Id; }

	Event();

	~Event();
};

#endif // !EVENT_H_



