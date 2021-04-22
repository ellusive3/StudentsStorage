#pragma once

class Event {
	public:
		Event();
		Event(int _eventId, int _cityId, Date _eventDate, Time _eventTime, std::string _description);

		int GetEventId() const;
		int GetCityId() const;
		Date GetDate() const;
		Time GetTime() const;
		std::string GetDescr() cosnt;
	private:
		int eventId;
		int cityId;
		Date eventDate;
		Time eventTime;
		std::string description;
	protected:
}