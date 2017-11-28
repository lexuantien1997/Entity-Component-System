#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

class Event;
#include <functional>
class EventHandler
{
public:

	virtual ~EventHandler() {}

	virtual void HandleEvent(Event* pEvent,string a) = 0;
};

#endif // EVENTHANDLER_H_