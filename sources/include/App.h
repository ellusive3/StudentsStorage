#pragma once
#include <IGui.h>
#include <IDb.h>

class AppManager {
	public:
		AppManager();
		~AppManager();
		void Run(int width = 800, int height =  600);
        void Stop();
	private:
		IGui * window;
        IDb* dbManager;
        std::vector<UserInfo> FindUsers(const std::string& searchInput);
        bool FindUser(const std::string& firstName, const std::string& lastName);
        std::vector<IntStringStruct> GetGroups();
        bool AddUser(const std::string& firstName, const std::string& lastName, const std::string& thirdName, int groupId);
        std::vector<IntStringStruct> GetStates();
        std::vector<IntStringStruct> GetCities();
        bool GetCity(int cityId);
        void RateCity(int cityId, int userId, Rate score);
        bool AddCity(int stateId, const std::string& cityName, double latitude, double longtitude);
        std::vector<IntStringStruct> GetObjects();
        std::vector<IntStringStruct> GetThemes();
        std::vector<std::string> GetLinks();
        bool AddObject(const std::string& objectName, const std::string& objectDescription);
        bool AddTheme(int objectId, const std::string& themeName);
        bool AddLink(int themeId, const std::string& link);
        std::vector<Event> GetEvents(int cityId, int firstDate, int lastDate);
        bool AddEvent(int eventDate, int cityId, int eventTime);
	protected:
        void ConnectCallBacks();
};