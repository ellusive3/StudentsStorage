  #pragma once

#include <iostream>
#include <Const.h>
#include <windows.h>
#include <string>
#include <boost/variant.hpp>
#include <string_view>
#include <qregexp.h>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <map>


#define BOOST_SIGNALS_NO_DEPRECATION_WARNING

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

using AttrValue = boost::variant<std::string, int, double, boost::posix_time::ptime>;

using Mark = std::pair<boost::posix_time::ptime, int>;

using MarkList = std::vector<std::pair<int, std::pair<std::string, Mark>>>;
