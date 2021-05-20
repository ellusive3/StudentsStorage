#pragma once
#include <Row.h>
#include <Attribute.h>

class IDb {
	public:
		virtual std::vector<Row> Select(const std::string& selectFmt, int countOfAttrs, Attribute args...) = 0;
		virtual int Delete(const std::string& deleteFmt, int countOfAttrs, Attribute args...) = 0;
		virtual std::vector<Row> Update(const std::string& updateFmt, int countOfAttrs, Attribute args...) = 0;
		virtual int Insert(const std::string& insertFmt, int countOfAttrs, Attribute args...) = 0;
};