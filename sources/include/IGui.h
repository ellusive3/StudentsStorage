#pragma once
#include <stdafx.h>
#include <vector>
#include <User.h>
#include <City.h>
#include <Event.h>
#include <Row.h>
#include <Attribute.h>
#include <boost/signal.hpp>
#include <Event.h>

enum Rate {
    A_RATE = 5,
    B_RATE = 4,
    C_RATE = 3,
    D_RATE = 2,
    E_RATE = 1
};

struct IntStringStruct {
    int id;
    std::string groupName;
};

using UserInfo = std::pair<int, std::pair<std::string, std::string>>;

class IGui {
    public:
        //virtual UserInfo FindUsers(const std::string& searchInput) = 0;
        boost::signal<UserInfo(const std::string&)> FindUsersSignal;
        //virtual bool FindUser(const std::string& firstName, const std::string& lastName) = 0;
        boost::signal<bool(const std::string&, const std::string&)> FindUserSignal;
        virtual void PrintUserInfo(const User& printedUser) = 0;
        //virtual const std::vector<IntStringStruct>& GetGroups() = 0;
        boost::signal < std::vector<IntStringStruct>()> GetGroupsSignal;
        //virtual bool AddUser(const std::string& firstName, const std::string& lastName, const std::string thirdName, int groupId) = 0;
        boost::signal<bool(const std::string&, const std::string&, const std::string &, int)>  AddUserSignal;
        virtual void PrintCity(const City & _city) = 0;
        //virtual const std::vector<IntStringStruct>& GetStates() = 0;
        boost::signal<std::vector<IntStringStruct>()> GetStatesSignal;
        boost::signal<std::vector<IntStringStruct>()> GetCitiesSignal;
        //virtual const std::vector<IntStringStruct>& GetCities(int stateId) = 0;
        //virtual bool GetCity(int cityId) = 0;
        boost::signal<bool(int)> GetCitySignal;
        //virtual void RateThisCity(int cityId, int userId, Rate score) = 0;
        boost::signal<void(int, int, Rate)> RateSignal;
        //virtual bool AddCity(int stateId, const std::string& cityName, double latitude = 0.0, double longtitude = 0.0) = 0;
        boost::signal<bool(int, const std::string&, double, double)> AddCitySignal;
        //virtual const std::vector<IntStringStruct>& GetObjects() = 0;
        boost::signal<std::vector<IntStringStruct>()> GetObjectsSignal;
        //virtual const std::vector<IntStringStruct>& GetThemes(int objectId) = 0;
        boost::signal<std::vector<IntStringStruct>()> GetThemesSignal;
        //virtual const std::vector<std::string>& GetLinks(int themeId) = 0;
        boost::signal<std::vector<std::string&>()> GetLinksSignal;
        //virtual bool AddObject(const std::string& objectName, const std::string& objectDescription) = 0;
        boost::signal<bool(const std::string&, const std::string&)> AddObjectSignal;
        //virtual bool AddTheme(int objectId, const std::string& themeName) = 0;
        boost::signal<bool(int, const std::string&)> AddThemeSignal;
        //virtual bool AddLink(int themeId, const std::string& link) = 0;
        boost::signal<bool(int, const std::string&)> AddLinkSignal;
        //virtual bool GetEvents(int cityId = -1, int firstDate = 0, int lastDate = 0) = 0;
        boost::signal<std::vector<Event>(int, int, int)> GetEventsSignal;
        virtual void PrintEvents(const std::vector<Event>& events) = 0;
        //virtual bool AddEvent(int eventDate, int cityId, int eventTime) = 0;
        boost::signal<bool(int, int, int)> AddEventSignal;
};