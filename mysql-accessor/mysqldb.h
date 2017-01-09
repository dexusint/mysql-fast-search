#ifndef MYSQLDB_H
#define MYSQLDB_H

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "database.h"

namespace MySQLAccessor {
  class MySQLDB : public IDatabase{
  public:
    class MySQLResult : public IDatabase::IResult {
    public:
      void setDB(MySQLDB* mysqlDB) {
        db = mysqlDB;
      }
      bool next() {
        return db->res->next();
      }

      std::string getString(std::string column) {
        return db->res->getString(column);
      }

      std::string getString(int column) {
        return db->res->getString(column);
      }

    private:
      MySQLDB* db;
    };

    ~MySQLDB();
    void connect(std::string username, std::string password);
    void setSchema(std::string schema);
    IDatabase::IResult* execQuery(std::string queryStr);

    private:
      sql::Driver *driver = nullptr;
      sql::Connection *con = nullptr;
      sql::Statement *stmt = nullptr;
      sql::ResultSet *res = nullptr;

      friend class MySQLDB::MySQLResult;
      MySQLDB::MySQLResult *mysqlRes;
  };



} // namespace MySQLAccessor

#endif //MYSQLDB_H
