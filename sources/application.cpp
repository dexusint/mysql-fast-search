#include <cassert>
#include <iostream>

#include "generator/generator.h"
#include "mysql-accessor/mysqldb.h"
#include "users-controller/userscontroller.h"


#include <includes/application.h>

using namespace std;
using namespace MySQLAccessor;
using namespace DataControl;
using namespace Utils;

time_t Application::makeTimePoint(int year, int mon, int day, int hour, int min, int sec){
  struct std::tm t;
  t.tm_sec = sec;
  t.tm_min = min;
  t.tm_hour = hour;
  t.tm_mday = day;
  t.tm_mon = mon -1;
  t.tm_year = year - 1900;
  t.tm_isdst = -1;

  return std::mktime(&t);
}

void Application::addRandomUser(int birthYearBeg, int birthYearEnd, int regYearBeg, int regYearEnd, int cityIdBeg, int cityIdEnd) {
  const time_t begBirthDate = makeTimePoint(birthYearBeg, 1, 1, 0, 0, 0);
  const time_t endBirthDate = makeTimePoint(birthYearEnd, 12, 31, 23, 59, 59);
  Generator<time_t> randomBirthDayGen(begBirthDate, endBirthDate);
  const auto randomBirthDate = randomBirthDayGen();

  const time_t begRegDate = makeTimePoint(regYearBeg, 1, 1, 0, 0, 0);
  const time_t endRegDate = makeTimePoint(regYearEnd, 12, 31, 23, 59, 59);
  Generator<time_t> randomRegDayGen(begRegDate, endRegDate);
  const auto randomRegDate = randomRegDayGen();
  Generator<int> randomGender(0, 1);
  Generator<int> randomCityId(cityIdBeg, cityIdEnd);
//  string begBirthTime = ctime(&begBirthDate);
//  string endBirthTime = ctime(&endBirthDate);
//  string randomBirthTime = ctime(&randomBirthDate);
//
//  begBirthTime.resize(begBirthTime.size() - 1);
//  endBirthTime.resize(endBirthTime.size() - 1);
//  randomBirthTime.resize(randomBirthTime.size() - 1);
//
//  cout << "Beg time " << begBirthTime << endl;
//  cout << "End time " << endBirthTime << endl;
//  cout << "Random time " << randomBirthTime << endl;

  shared_ptr<IDatabase> db(new MySQLDB());
  db->connect("root", "123456");
  db->setSchema("users");
  UsersController<IDatabase> usersController(db);
  usersController.addUser(34, randomBirthDate, randomGender(), randomCityId(), randomRegDate);

}

void Application::fillDatabase(int count, int birthYearBeg, int birthYearEnd, int regYearBeg, int regYearEnd, int cityIdBeg, int cityIdEnd) {
  const time_t begBirthDate = makeTimePoint(birthYearBeg, 1, 1, 0, 0, 0);
  const time_t endBirthDate = makeTimePoint(birthYearEnd, 12, 31, 23, 59, 59);
  Generator<time_t> randomBirthDayGen(begBirthDate, endBirthDate);
  const time_t begRegDate = makeTimePoint(regYearBeg, 1, 1, 0, 0, 0);
  const time_t endRegDate = makeTimePoint(regYearEnd, 12, 31, 23, 59, 59);
  Generator<time_t> randomRegDayGen(begRegDate, endRegDate);
  Generator<int> randomGender(0, 1);
  Generator<int> randomCityId(cityIdBeg, cityIdEnd);


  shared_ptr<IDatabase> db(new MySQLDB());
  db->connect("root", "123456");
  db->setSchema("users");
  UsersController<IDatabase> usersController(db);

  for(int i=0; i <= count; ++i) {
    usersController.addUser(i, randomBirthDayGen(), randomGender(), randomCityId(), randomRegDayGen());
  }

//  shared_ptr<IDatabase> db(new MySQLDB());
//  db->connect("root", "123456");
//  db->setSchema("users");
//  UsersController<IDatabase> usersController(db);
//  usersController.getAllUsers();

//  for (int i = 0; i < count; ++i) {
//
//  }
}
