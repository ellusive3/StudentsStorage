#pragma once

class Event {
	public:
		Event();
		Event(int _eventId, int _cityId, /*Date*/int _eventDate, /*Time*/int _eventTime, std::string _description);

		int GetEventId() const;
		int GetCityId() const;
		int GetDate() const;
		int GetTime() const;
		std::string GetDescr() const;
	private:
		int eventId;
		int cityId;
		int eventDate;
		int eventTime;
		std::string description;
	protected:
};