#pragma once
#include <IGui.h>

class AppManager {
	public:
		AppManager();
		void Run(int width = 800, int height =  600);
	private:
		IGui * window;
	protected:
};