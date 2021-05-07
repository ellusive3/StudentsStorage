#include <stdafx.h>
#include <Event.h>


	Event::Event()
	{
		eventId = 0;
		cityId = 0;
		eventDate = 0;
		eventTime = 0;
		description = "none";
	}

	Event::Event(int _eventId, int _cityId, int _eventDate, int _eventTime, std::string _description)
	{
		eventId = _eventId;
		cityId = _cityId;
		eventId = _eventId;
		eventTime = _eventTime;
		description = _description;
	}

	int Event::GetEventId() const
	{
		return eventId;
	}

	int Event::GetCityId() const
	{
		return cityId;
	}

	int Event::GetDate() const
	{
		return eventDate;
	}

	int Event::GetTime() const
	{
		return eventTime;
	}

	std::string Event::GetDescr() const
	{
		return description;
	}
