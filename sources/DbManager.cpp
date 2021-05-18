#include <stdafx.h>
#include <DbManager.h>
#include <stdarg.h>
#include <libpq-fe.h>

DbManager::DbManager()
{}

DbManager::~DbManager()
{}

std::vector<Row> DbManager::Select(const std::string& selectFmt, int countOfAttrs, Attribute attr, ...)
{
	/*Test code*/
	PGconn* conn = PQconnectdb("host=localhost port=5432 dbname=StudentsStorage user=postgres password=admin");
	if (PQstatus(conn) != CONNECTION_OK) {
		// Не удалось подключиться к БД
		fprintf(stderr, "Connection to database failed: %s",
			PQerrorMessage(conn));
		PQfinish(conn);
		exit(1);
	}
	PGresult* res;
	int nFields;
	res = PQexec(conn, "BEGIN");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		fprintf(stderr, "BEGIN command failed: %s", PQerrorMessage(conn));
		PQclear(res);
		PQfinish(conn);
		exit(1);
	}
	PQclear(res);
	res = PQexec(conn, "DECLARE selPoint CURSOR FOR select * from user");
	if (PQresultStatus(res) != PGRES_COMMAND_OK)
	{
		fprintf(stderr, "DECLARE CURSOR failed: %s", PQerrorMessage(conn));
		PQclear(res);
		PQfinish(conn);
		exit(1);
	}
	PQclear(res);
	res = PQexec(conn, "FETCH ALL in selPoint");
	if (PQresultStatus(res) != PGRES_TUPLES_OK)
	{
		fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
		PQclear(res);
		PQfinish(conn);
		exit(1);
	}
	nFields = PQnfields(res);
	for (int i = 0; i < nFields; i++)
		printf("%-15s", PQftablecol(res, i));
	printf("\n\n");

	res = PQexec(conn, "CLOSE selPoint");
	PQclear(res);
	res = PQexec(conn, "END");
	PQclear(res);
	PQfinish(conn);
	/*End of test code*/

	va_list factor;
	va_start(factor, &countOfAttrs);
	while (countOfAttrs > 0) {
		Attribute _attr = va_arg(factor, Attribute);
		countOfAttrs--;
	}
	va_end(factor);
	return std::vector<Row>();
}

int DbManager::Delete(const std::string& deleteFmt, int countOfAttrs, Attribute attr, ...)
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

std::vector<Row> DbManager::Update(const std::string& updateFmt, int countOfAttrs, Attribute attr, ...)
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

int DbManager::Insert(const std::string& insertFmt, int countOfAttrs, Attribute attr, ...)
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

