#include <stdafx.h>
#include <App.h>
#include <clocale>

int main(void)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	try {
		AppManager application;
		application.Run(1024, 768);
	}
	catch (...) {
		return RETURN_RUNTIME_ERROR;
	}
	return RETURN_SUCCESS;
}