#include <stdafx.h>
#include <Event.h>


	Event::Event()
	{
		eventId = 0;
		cityId = 0;
		eventDate = Date();
		eventTime = Time();
		description = "none";
	}

	Event::Event(int _eventId, int _cityId, Date _eventDate, Time _eventTime, std::string _description)
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

	Date Event::GetDate() const
	{
		return eventDate;
	}

	Time Event::GetTime() const
	{
		return eventTime;
	}

	std::string Event::GetDescr() cosnt
	{
		return description;
	}
