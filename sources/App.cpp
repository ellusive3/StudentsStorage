#include <stdafx.h>
#include <App.h>
#include <Gui.h>
#include <DbManager.h>
#include <boost/bind.hpp>
#include <qapplication.h>


AppManager::AppManager() {
	// TODO создать экземпляр GUI
	window = nullptr;
	dbManager = nullptr;
}

AppManager::~AppManager()
{
	Stop();
	delete(window);
}

void AppManager::Run(int width, int height)
{
	int argc = 0;
	char** argv = new char* (new char());
	QApplication app(argc, argv);
	dbManager = new DbManager();
	window = new GUI(width, height);
	ConnectCallBacks();
	window->CompleteUsers();
	app.exec();
}

void AppManager::Stop()
{
	window->FindUsersSignal.disconnect_all_slots();
	window->FindUserSignal.disconnect_all_slots();
	window->GetGroupsSignal.disconnect_all_slots();
	window->AddUserSignal.disconnect_all_slots();
	window->GetStatesSignal.disconnect_all_slots();
	window->GetCitiesSignal.disconnect_all_slots();
	window->GetCitySignal.disconnect_all_slots();
	window->RateSignal.disconnect_all_slots();
	window->AddCitySignal.disconnect_all_slots();
	window->GetObjectsSignal.disconnect_all_slots();
	window->GetThemesSignal.disconnect_all_slots();
	window->GetLinksSignal.disconnect_all_slots();
	window->AddObjectSignal.disconnect_all_slots();
	window->AddThemeSignal.disconnect_all_slots();
	window->AddLinkSignal.disconnect_all_slots();
	window->GetEventsSignal.disconnect_all_slots();
	window->AddEventSignal.disconnect_all_slots();
	window->FindUserMarksSignal.disconnect_all_slots();
}

void AppManager::ConnectCallBacks()
{
	window->FindUsersSignal.connect(boost::bind(&AppManager::FindUsers, this, _1));
	window->FindUserSignal.connect(boost::bind(&AppManager::FindUser, this, _1, _2));
	window->GetGroupsSignal.connect(boost::bind(&AppManager::GetGroups, this));
	window->AddUserSignal.connect(boost::bind(&AppManager::AddUser, this, _1, _2, _3, _4));
	window->GetStatesSignal.connect(boost::bind(&AppManager::GetStates, this));
	window->GetCitiesSignal.connect(boost::bind(&AppManager::GetCities, this));
	window->GetCitySignal.connect(boost::bind(&AppManager::GetCity, this, _1));
	window->RateSignal.connect(boost::bind(&AppManager::RateCity, this, _1, _2, _3));
	window->AddCitySignal.connect(boost::bind(&AppManager::AddCity, this, _1, _2, _3, _4));
	window->GetObjectsSignal.connect(boost::bind(&AppManager::GetObjects, this));
	window->GetThemesSignal.connect(boost::bind(&AppManager::GetThemes, this));
	window->GetLinksSignal.connect(boost::bind(&AppManager::GetLinks, this));
	window->AddObjectSignal.connect(boost::bind(&AppManager::AddObject, this, _1, _2));
	window->AddThemeSignal.connect(boost::bind(&AppManager::AddTheme, this, _1, _2));
	window->AddLinkSignal.connect(boost::bind(&AppManager::AddLink, this, _1, _2));
	window->GetEventsSignal.connect(boost::bind(&AppManager::GetEvents, this, _1, _2, _3));
	window->AddEventSignal.connect(boost::bind(&AppManager::AddEvent, this, _1, _2, _3));
	window->FindUserMarksSignal.connect(boost::bind(&AppManager::FindUserMarks, this, _1));
}

std::vector<UserInfo> AppManager::FindUsers(const std::string& searchInput)
{
	return  dbManager->FindUsers(searchInput);
}

User AppManager::FindUser(const std::string& firstName, const std::string& lastName)
{
	return dbManager->FindUser(firstName, lastName);
}

std::vector<IntStringStruct> AppManager::GetGroups()
{
	return dbManager->GetAllGroups();
}

MarkList AppManager::FindUserMarks(int userId)
{
	return dbManager->FindUserMarks(userId);
}

bool AppManager::AddUser(const std::string& firstName, const std::string& lastName, const std::string& thirdName, int groupId)
{
	return true;
}

std::vector<IntStringStruct> AppManager::GetStates()
{
	return std::vector<IntStringStruct>();
}

std::vector<IntStringStruct> AppManager::GetCities()
{
	return std::vector<IntStringStruct>();
}

bool AppManager::GetCity(int cityId)
{
	return true;
}

void AppManager::RateCity(int cityId, int userId, Rate score)
{}

bool AppManager::AddCity(int stateId, const std::string& cityName, double latitude, double longtitude)
{
	return true;
}

std::vector<IntStringStruct> AppManager::GetObjects()
{
	return dbManager->GetAllObjects();
}

std::vector<IntStringStruct> AppManager::GetThemes()
{
	return std::vector<IntStringStruct>();
}

std::vector<std::string> AppManager::GetLinks()
{
	return std::vector<std::string>();
}

bool AppManager::AddObject(const std::string& objectName, const std::string& objectDescription)
{
	return true;
}

bool AppManager::AddTheme(int objectId, const std::string& themeName)
{
	return true;
}

bool AppManager::AddLink(int themeId, const std::string& link)
{
	return true;
}

std::vector<Event> AppManager::GetEvents(int cityId, int firstDate, int lastDate)
{
	return std::vector<Event>();
}

bool AppManager::AddEvent(int eventDate, int cityId, int eventTime)
{
	return true;
}