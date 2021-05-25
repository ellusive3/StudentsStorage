#include <stdafx.h>
#include <App.h>
#include <clocale>

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	AppManager application;
	return application.Run(1920, 1080);
};