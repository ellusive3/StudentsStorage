#pragma once
#include <stdafx.h>
#include <IDb.h>
#include <sqlapi/SQLAPI.h>
#include <User.h>

class DbManager {
	public:
		DbManager();
		~DbManager();
		template<typename ...Args>
		std::vector<Row> Select(const std::string& selectFmt, int countOfAttrs, Args&&... args)
		{
			std::vector<Row> result = std::vector<Row>();
			if (ConnectToDb()) {
				std::string preparedSelect = PrepareRequest(selectFmt, countOfAttrs, std::forward<Args>(args)...);
				SACommand select(&conn, _TSA(preparedSelect.c_str()));
				try {
					select.Execute();
					while (select.FetchNext()) {
						Row addingRow;
						long colCount = select.FieldCount();
						for (int i = 1; i < colCount + 1; i++) {
							SAField& sField = select.Field(i);
							std::string fieldName = sField.Name();
							AttrValue fieldValue;
							if (sField.DataType() == SADataType_t::SA_dtDouble)
								fieldValue = sField.asDouble();
							else if (sField.DataType() == SADataType_t::SA_dtInt64 ||
								sField.DataType() == SADataType_t::SA_dtUInt64 ||
								sField.DataType() == SADataType_t::SA_dtLong)
								fieldValue = (int)sField.asInt64();
							else if (sField.DataType() == SADataType_t::SA_dtString)
								fieldValue = std::string(sField.asString().GetMultiByteChars());
							else if (sField.DataType() == SADataType_t::SA_dtDateTime) {
								std::string time = sField.asString().GetMultiByteChars();
								if (sField.asDateTime().hasTime()) {
									fieldValue = boost::posix_time::time_from_string(time);
								}
								else {
									fieldValue = boost::posix_time::time_from_string(time + " 00:00:00");
								}
							}
							Attribute addingAttr(fieldName, fieldValue);
							addingRow.AddAttr(addingAttr);
						}
						result.push_back(addingRow);
					}
					DisconnectFromDb();
				}
				catch (SAException& ex) {
					printf(ex.ErrMessage());
					DisconnectFromDb();
					return result;
				}
			}
			return result;
		}
		int Delete(const std::string& deleteFmt, int countOfAttrs, Attribute args...);
		std::vector<Row> Update(const std::string& updateFmt, int countOfAttrs, Attribute args...);
		template<typename ...Args>
		int Insert(const std::string& insertFmt, int countOfAttrs, Args&&... args)
		{
			int result = 0;
			if (ConnectToDb()) {
				std::string preparedInsert = PrepareRequest(insertFmt, countOfAttrs, std::forward<Args>(args)...);
				SACommand insert(&conn, _TSA(preparedInsert.c_str()));
				insert.Execute();
				result = insert.RowsAffected();
				DisconnectFromDb();
			}
			return result;
		}

		std::vector<UserInfo> FindUsers(const std::string& regQuery);
		User FindUser(const std::string& firstName, const std::string& lastName);
		std::vector<IntStringStruct> GetAllGroups();
		MarkList FindUserMarks(int userId);
	private:
		SAConnection conn;
		bool ConnectToDb();
		bool DisconnectFromDb();
		std::string PrepareRequest(const std::string& fmtReq, int countOfAttrs, ...);
	protected:
};


