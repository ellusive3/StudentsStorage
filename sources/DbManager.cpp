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
		conn.Connect(_TSA("localhost@StudentsStorage"), _TSA("root"), _TSA("root"), SA_PostgreSQL_Client);
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

