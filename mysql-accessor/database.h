#ifndef DATABASE_H
#define DATABASE_H

#include <string>

namespace MySQLAccessor {

class IDatabase {
public:

  class IResult {
  public:
    virtual bool next() = 0;
    virtual std::string getString(std::string column) = 0;
    virtual std::string getString(int column) = 0;
  };

  virtual void connect(std::string username, std::string password) = 0;
	virtual void setSchema(std::string schema) = 0;
	virtual IResult* execQuery(std::string queryStr) = 0;
};

} // namespace MySQLAccessor

#endif // DATABASE_H
