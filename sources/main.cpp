#include <stdafx.h>
#include <App.h>

int main(void)
{
	try {
		AppManager application;
		application.Run(1024, 768);
	}
	catch (...) {
		return RETURN_RUNTIME_ERROR;
	}
	return RETURN_SUCCESS;
}