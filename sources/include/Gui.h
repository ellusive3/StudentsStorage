#pragma once

#include <IGui.h>

class GUI : public IGui {
	public:
		GUI(int width, int height);
		virtual void PrintUserInfo(const User& printedUser) override;
		virtual void PrintCity(const City& _city) override;
		virtual void PrintEvents(const std::vector<Event>& events) override;
	private:

	protected:
};