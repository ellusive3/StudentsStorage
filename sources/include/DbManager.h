#pragma once
#include <IDb.h>
#include <sqlapi/SQLAPI.h>

class DbManager : public IDb {
	public:
		DbManager();
		~DbManager();
		virtual std::vector<Row> Select(const std::string& selectFmt, int countOfAttrs, Attribute args...) override;
		virtual int Delete(const std::string& deleteFmt, int countOfAttrs, Attribute args...) override;
		virtual std::vector<Row> Update(const std::string& updateFmt, int countOfAttrs, Attribute args...) override;
		virtual int Insert(const std::string& insertFmt, int countOfAttrs, Attribute args...) override;
	private:
		SAConnection conn;
		bool ConnectToDb();
		bool DisconnectFromDb();
		std::string PrepareRequest(const std::string& fmtReq, int countOfAttrs, Attribute args...);
	protected:
};


