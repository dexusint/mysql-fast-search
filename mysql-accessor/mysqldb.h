#ifndef MYSQLDB_H
#define MYSQLDB_H

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#include "database.h"

class MySQLResult;

class MySQLDB : public IDatabase{
private:
  sql::Driver *driver = nullptr;
  sql::Connection *con = nullptr;
  sql::Statement *stmt = nullptr;
  sql::ResultSet *res = nullptr;

  friend class MySQLResult;
  MySQLResult *mysqlRes;

public:
  ~MySQLDB();
  void connect();
  void setSchema(std::string schema);
  IResult* execQuery(std::string queryStr);
};

class MySQLResult : public IResult {
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

#endif //MYSQLDB_H
