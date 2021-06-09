#include <stdafx.h>
#include <DbManager.h>
#include <stdarg.h>
#include <boost/lexical_cast.hpp>

DbManager::DbManager()
{}

DbManager::~DbManager()
{}

bool DbManager::ConnectToDb()
{
	if (conn.isConnected())
		return true;
	try {
		conn.Connect(_TSA("localhost@postgres"), _TSA("postgres"), _TSA("postgres"), SA_PostgreSQL_Client);
		printf("We are connected!\n");
	}
	catch (SAException& ex) {
		//conn.Rollback();
		printf("%s\n", ex.ErrText().GetMultiByteChars());
		return false;
	}
	return true;
}

bool DbManager::DisconnectFromDb()
{
	if (!conn.isConnected())
		return true;
	try {
		conn.Disconnect();
		printf("We are disconnected!\n");
	}
	catch (SAException&) {
		return false;
	}
	return true;
}

std::string DbManager::PrepareRequest(const std::string& fmtReq, int countOfAttrs, ...)
{
	std::string result = fmtReq;
	va_list factor;
	va_start(factor, &countOfAttrs);
	int counter = 1;
	while (countOfAttrs > 0) {
		Attribute _attr = va_arg(factor, Attribute);
		std::string key = _attr.GetKey();
		AttrValue val = _attr.GetValue();
		std::string searchPattern = "%" + std::to_string(counter);
		auto found = result.find(searchPattern);
		if (found != std::string::npos)
			result.replace(found, searchPattern.size(), key);
		searchPattern = "#" + std::to_string(counter);
		found = result.find(searchPattern);
		if (found != std::string::npos) {
			if (val.type() == typeid(int)) {
				//int
				result.replace(found, searchPattern.size(), std::to_string(boost::get<int>(val)));
			}
			else if (val.type() == typeid(double)) {
				// double
				result.replace(found, searchPattern.size(), std::to_string(boost::get<double>(val)));
			}
			else if (val.type() == typeid(std::string)) {
				// string
				result.replace(found, searchPattern.size(), "'" + boost::get<std::string>(val) + "'");
			}
		}
		countOfAttrs--;
		counter++;
	}
	va_end(factor);
	return result;
}

int DbManager::Delete(const std::string& deleteFmt, int countOfAttrs, Attribute args...)
{
	va_list factor;
	va_start(factor, &countOfAttrs);
	while (countOfAttrs > 0) {
		Attribute _attr = va_arg(factor, Attribute);
		countOfAttrs--;
	}
	va_end(factor);
	return 0;
}

std::vector<Row> DbManager::Update(const std::string& updateFmt, int countOfAttrs, Attribute args...)
{
	va_list factor;
	va_start(factor, &countOfAttrs);
	while (countOfAttrs > 0) {
		Attribute _attr = va_arg(factor, Attribute);
		countOfAttrs--;
	}
	va_end(factor);
	return std::vector<Row>();
}

User DbManager::FindUser(const std::string& firstName, const std::string& lastName)
{
	// User result;
	User usr;
	std::vector<Row> rawResults;
	rawResults = Select("SELECT id, sfirstName, slastname, sthirdname, idgroup, dblaveragedisciplinescore FROM \"user\" where %1 = #1 and %2 = #2", 
		2,
		new Attribute("sfirstname", firstName),
		new Attribute("slastname", lastName));

	if (rawResults.size() == 1)
	{
		usr = User
		(
			boost::get<int>(rawResults[0].FindAttrByKey("id")->GetValue()),
			boost::get<std::string>(rawResults[0].FindAttrByKey("sfirstname")->GetValue()),
			boost::get<std::string>(rawResults[0].FindAttrByKey("slastname")->GetValue()),
			boost::get<std::string>(rawResults[0].FindAttrByKey("sthirdname")->GetValue()),
			const_cast<int&>(boost::get<int>(rawResults[0].FindAttrByKey("idgroup")->GetValue())),
			boost::get<double>(rawResults[0].FindAttrByKey("dblaveragedisciplinescore")->GetValue())
		);
	}
	return usr;
}

std::vector<IntStringStruct> DbManager::GetAllGroups()
{
	std::vector<IntStringStruct> results;
	std::vector<Row> rawResults;
	rawResults = Select("SELECT * FROM  \"group\"", 0);
	for (auto rawResult : rawResults) {
		IntStringStruct result;
		result.id = boost::get<int>(rawResult.FindAttrByKey("id")->GetValue());
		result.groupName = boost::get<std::string>(rawResult.FindAttrByKey("sname")->GetValue());
		results.push_back(result);
	}
	return results;
}

MarkList DbManager::FindUserMarks(int userId)
{
	std::vector<Row> rawResults;
	MarkList results;
	rawResults = Select("SELECT ob.id, ob.sname, uob.nmarkvalue, uob.dmarkdate FROM \"userobject\" uob JOIN \"object\" ob ON uob.idobject = ob.id WHERE %1 = #1",
		1, 
		new Attribute("uob.iduser", userId));

	for (auto rawResult : rawResults)
	{
		std::pair<int, std::pair<std::string, Mark>> result(boost::get<int>(rawResult.FindAttrByKey("id")->GetValue()),
			std::make_pair(
				boost::get<std::string>(rawResult.FindAttrByKey("sname")->GetValue()),
				Mark(boost::get<boost::posix_time::ptime>(rawResult.FindAttrByKey("dmarkdate")->GetValue()),
			boost::get<int>(rawResult.FindAttrByKey("nmarkvalue")->GetValue()))));
		results.push_back(result);
		printf("id = %d, sname = %s, nmarkvalue = %d, dmarkdate = %s\n\n",
			boost::get<int>(rawResult.FindAttrByKey("id")->GetValue()),
			boost::get<std::string>(rawResult.FindAttrByKey("sname")->GetValue()).c_str(),
			boost::get<int>(rawResult.FindAttrByKey("nmarkvalue")->GetValue()),
			boost::posix_time::to_iso_extended_string(boost::get<boost::posix_time::ptime>(rawResult.FindAttrByKey("dmarkdate")->GetValue())).c_str()
		);
	}
	return results;
}

std::vector<IntStringStruct> DbManager::GetAllObjects()
{
	std::vector<Row> rawResults;
	std::vector<IntStringStruct> results;
	rawResults = Select("SELECT * FROM \"object\"", 0);
	for (auto rawResult : rawResults) {
		IntStringStruct result;
		result.id = boost::get<int>(rawResult.FindAttrByKey("id")->GetValue());
		result.groupName = boost::get<std::string>(rawResult.FindAttrByKey("sname")->GetValue());
		results.push_back(result);
	}
	return results;
}

std::vector<UserInfo> DbManager::FindUsers(const std::string& regQuery)
{
	std::vector<UserInfo> result;
	std::vector<Row> rawResults;
	rawResults = Select("SELECT * FROM \"user\" WHERE %1 ~* #1 OR %2 ~* #2", 2, 
		new Attribute("sfirstname", regQuery),
		new Attribute("slastname", regQuery));
	for (auto rawResult : rawResults) {
		UserInfo addingUser;
		addingUser.first = boost::get<int>(rawResult.FindAttrByKey("id")->GetValue());
		addingUser.second.first = boost::get<std::string>(rawResult.FindAttrByKey("sfirstname")->GetValue());
		addingUser.second.second = boost::get<std::string>(rawResult.FindAttrByKey("slastname")->GetValue());
		result.push_back(addingUser);
	}
	return result;
}

