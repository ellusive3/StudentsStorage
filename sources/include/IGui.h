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

class IGui {
    public:
        /*Interface signals*/
        boost::signal<std::vector<UserInfo>(const std::string&)> FindUsersSignal;
        // Klepko A.Y
        boost::signal <std::vector<IntStringStruct>(const std::string&)> FindGroupsSignal;
        // end Klepko 
        boost::signal<User(const std::string&, const std::string&)> FindUserSignal;
        boost::signal <std::vector<IntStringStruct>()> GetGroupsSignal;
        boost::signal<int(const std::string&, const std::string&, const std::string &, int)>  AddUserSignal;
        boost::signal<std::vector<IntStringStruct>()> GetStatesSignal;
        boost::signal<std::vector<IntStringStruct>()> GetCitiesSignal;
        boost::signal<bool(int)> GetCitySignal;
        boost::signal<void(int, int, Rate)> RateSignal;
        boost::signal<bool(int, const std::string&, double, double)> AddCitySignal;
        boost::signal<std::vector<IntStringStruct>()> GetObjectsSignal;
        boost::signal<std::vector<IntStringStruct>()> GetThemesSignal;
        boost::signal<std::vector<std::string>()> GetLinksSignal;
        boost::signal<bool(const std::string&, const std::string&)> AddObjectSignal;
        boost::signal<bool(int, const std::string&)> AddThemeSignal;
        boost::signal<bool(int, const std::string&)> AddLinkSignal;
        boost::signal<std::vector<Event>(int, int, int)> GetEventsSignal;
        boost::signal<bool(int, int, int)> AddEventSignal;
        boost::signal<MarkList(int)> FindUserMarksSignal;
        /*Interface functions*/
        virtual void PrintUserInfo(const User& printedUser) = 0;
        virtual void PrintEvents(const std::vector<Event>& events) = 0;
        virtual void PrintCity(const City& _city) = 0;
        virtual void CompleteUsers() = 0;
        virtual void CompleteGroups() = 0;


        //virtual UserInfo FindUsers(const std::string& searchInput) = 0;
        //virtual bool FindUser(const std::string& firstName, const std::string& lastName) = 0;
        //virtual const std::vector<IntStringStruct>& GetGroups() = 0;
        //virtual bool AddUser(const std::string& firstName, const std::string& lastName, const std::string thirdName, int groupId) = 0;
        //virtual const std::vector<IntStringStruct>& GetStates() = 0;
        //virtual const std::vector<IntStringStruct>& GetCities(int stateId) = 0;
        //virtual bool GetCity(int cityId) = 0;
        //virtual void RateThisCity(int cityId, int userId, Rate score) = 0;
        //virtual bool AddCity(int stateId, const std::string& cityName, double latitude = 0.0, double longtitude = 0.0) = 0;
        //virtual const std::vector<IntStringStruct>& GetObjects() = 0;
        //virtual const std::vector<IntStringStruct>& GetThemes(int objectId) = 0;
        //virtual const std::vector<std::string>& GetLinks(int themeId) = 0;
        //virtual bool AddObject(const std::string& objectName, const std::string& objectDescription) = 0;
        //virtual bool AddTheme(int objectId, const std::string& themeName) = 0;
        //virtual bool AddLink(int themeId, const std::string& link) = 0;
        //virtual bool GetEvents(int cityId = -1, int firstDate = 0, int lastDate = 0) = 0;
        //virtual bool AddEvent(int eventDate, int cityId, int eventTime) = 0;
};