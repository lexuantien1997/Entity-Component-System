#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <functional>
#include <map>
#include <vector>
#include <utility>

template <typename Event>
class Subject
{
private:
	std::map<Event, std::vector<std::function<void()>>> observers_;
public:
	template <typename Observer>
	void registerObserver(const Event& event, Observer&& observer)
	{
		observers_[event].push_back(std::forward<Observer>(observer));
	}

	template <typename Observer>
	void registerObserver(Event&& event, Observer&& observer)
	{
		observers_[std::move(event)].push_back(std::forward<Observer>(observer));
	}

	void notify(const Event& event) const
	{
		for (const auto& obs : observers_.at(event)) obs();
	}


	Subject();

	~Subject();
};

#endif

