#include <stdlib.h>
#include <stdafx.h>
#include <signal.h>
#include <vector>
#include <datetimeapi.h>

class Row;
class Attribute;

class IDbManager {
    public:
        std::vector<Row> Select(const std::string & formatQuery, size_t countOfArgs, Attribute ...);
}

// TODO forward declarations
class User;
class City;
class Event;

enum Rate {
    A_RATE = 5,
    B_RATE = 4,
    C_RATE = 3, 
    D_RATE = 2,
    E_RATE = 1
}

struct IntStringStruct {
    int id;
    std::string groupName;
}

using std::pair<int, <std::pair<std::string, std::string>> = UserInfo;

class IGui { 
    public:
        virtual UserInfo FindUsers(const std::string &searchInput) = 0;
        virtual bool FindUser(const std::string& firstName, const std::string& lastName) = 0;
        virtual void PrintUserInfo(const User & printedUser) = 0;
        virtual const std::vector<IntStringStruct> & GetGroups() = 0;
        virtual bool AddUser(const std::string& firstName, const std::string& lastName, const std::string thirdName, int groupId) = 0;
        virtual void PrintCity(const & City);
        virtual const std::vector<IntStringStruct> & GetStates() = 0;
        virtual const std::vector<IntStringStruct> & GetCities(int stateId) = 0;
        virtual bool GetCity(int cityId);
        virtual void RateThisCity(int cityId, int userId, Rate score) = 0;
        virtual bool AddCity(int stateId, const std::string & cityName, double latitude = 0.0, double longtitude = 0.0) = 0;
        virtual const std::vector<IntStringStruct> & GetObjects() = 0;
        virtual const std::vector<IntStringStruct> & GetThemes(int objectId) = 0;
        virtual const std::vector<std::string> & GetLinks(int themeId) = 0;
        virtual bool AddObject(const std::string& objectName, const std::string& objectDescription) = 0;
        virtual bool AddTheme(int objectId, const std::string& themeName) = 0;
        virtual bool AddLink(int themeId, const std::string& link) = 0;

        virtual bool GetEvents(int cityId = -1, Date firstDate = 0, Date lastDate = 0) = 0;
        virtual void PrintEvents(const std::vector<Event> & events) = 0;
        virtual bool AddEvent(Date eventDate, int cityId, Time eventTime) = 0;
}