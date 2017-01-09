#ifndef DATABASE_H
#define DATABASE_H

#include <string>

class IResult {
public:
  virtual bool next() = 0;
  virtual std::string getString(std::string column) = 0;
  virtual std::string getString(int column) = 0;
};

class IDatabase {
public:
  virtual void connect() = 0;
	virtual void setSchema(std::string schema) = 0;
	virtual IResult* execQuery(std::string queryStr) = 0;
};

#endif // DATABASE_H
