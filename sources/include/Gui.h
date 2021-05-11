#pragma once

#include <IGui.h>

class GUI : public IGui {
	public:
		GUI(int width, int height);
		virtual void PrintUserInfo(const User& printedUser);
		virtual void PrintCity(const City& _city);
		virtual void PrintEvents(const std::vector<Event>& events);
	private:

	protected:
};