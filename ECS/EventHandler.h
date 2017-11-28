#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

class Event;

class EventHandler
{
public:
	virtual ~EventHandler() {}

	
	virtual void HandleEvent(Event* pEvent) = 0;
};

#endif // EVENTHANDLER_H_