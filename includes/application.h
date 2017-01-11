#ifndef APPLICATION_H
#define APPLICATION_H

#include <cstddef>
#include <memory>
#include <ctime>

class Application {
public:
  static void fillDatabase(int count = MAX_COUNT, int birthYearBeg = 1975, int birthYearEnd = 1990, int regYearBeg = 2006, int regYearEnd = 2016, int cityIdBeg = 0, int cityIdEnd = 100);
  static void addRandomUser(int birthYearBeg = 1975, int birthYearEnd = 1990, int regYearBeg = 2006, int regYearEnd = 2016, int cityIdBeg = 0, int cityIdEnd = 100);
  static const int MAX_COUNT = 10000000;

private:
  static time_t makeTimePoint(int year, int mon, int day, int hour, int min, int sec=0);
};

#endif//APPLICATION_H
