#include <stdafx.h>
#include <App.h>
#include <clocale>

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	AppManager application;
	try {
		application.Run(1920, 1080);
	}
	catch (...) {
		return RETURN_RUNTIME_ERROR;
	}
	return RETURN_SUCCESS;
};