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
        boost::signal<void(int, int, Mark)> AddMarkSignal;
        /*Interface functions*/
        virtual void PrintUserInfo(const User& printedUser) = 0;
        virtual void PrintEvents(const std::vector<Event>& events) = 0;
        virtual void PrintCity(const City& _city) = 0;
        virtual void CompleteUsers() = 0;
};