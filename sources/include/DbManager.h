#pragma once
#include <IDb.h>

class DbManager : public IDb {
	public:
		DbManager();
		~DbManager();
		virtual std::vector<Row> Select(const std::string& selectFmt, int countOfAttrs, Attribute attr, ...) override;
		virtual int Delete(const std::string& deleteFmt, int countOfAttrs, Attribute attr, ...) override;
		virtual std::vector<Row> Update(const std::string& updateFmt, int countOfAttrs, Attribute attr, ...) override;
		virtual int Insert(const std::string& insertFmt, int countOfAttrs, Attribute attr, ...) override;
	private:
	protected:
};


