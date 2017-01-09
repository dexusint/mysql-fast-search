#include <iostream>

#include "../mysqldb.h"

using namespace std;

namespace MySQLAccessor {

void MySQLDB::connect(std::string username, std::string password) {
  try {
    driver = get_driver_instance();
    con = driver->connect("tcp://127.0.0.1:3306", username.c_str(), password.c_str());
  } catch (sql::SQLException &e) {
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << endl;
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  }

  if (mysqlRes == nullptr) {
    mysqlRes = new MySQLDB::MySQLResult();
    mysqlRes->setDB(this);
  }
}

MySQLDB::~MySQLDB() {
  if (mysqlRes != nullptr) {
    delete mysqlRes;
  }
  if (res != nullptr) delete res;
  if (stmt != nullptr) delete stmt;
  if (con != nullptr) delete con;
}

void MySQLDB::setSchema(std::string schema){
  try{
  con->setSchema(schema.c_str());
  } catch (sql::SQLException &e) {
      cout << "# ERR: SQLException in " << __FILE__;
      cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << endl;
      cout << "# ERR: " << e.what();
      cout << " (MySQL error code: " << e.getErrorCode();
      cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  }
}

IDatabase::IResult* MySQLDB::execQuery(std::string queryStr){
  try {
    stmt = con->createStatement();
    res = stmt->executeQuery(queryStr.c_str());
  } catch (sql::SQLException &e) {
    cout << "# ERR: SQLException in " << __FILE__;
    cout << "(" << __FUNCTION__ << ") on line "  << __LINE__ << endl;
    cout << "# ERR: " << e.what();
    cout << " (MySQL error code: " << e.getErrorCode();
    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
  }

  return mysqlRes;
}

} // namespace MySQLAccessor
