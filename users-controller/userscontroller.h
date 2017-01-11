#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <string>
#include <iostream>
#include <ctime>

namespace DataControl {

template <class T>
class UsersController {
public:
  UsersController(std::shared_ptr<T> accessor);

public:
  void addUser(int id, time_t birthday, int gender, int city_id, time_t time_reg);
  void deleteUser();
  void getAllUsers();
  void getUser();
  void updateUser();

private:
  std::shared_ptr<T> dbAccessor = nullptr;
};

template <class T>
UsersController<T>::UsersController(std::shared_ptr<T> accessor):
dbAccessor(accessor)
{}

template <class T>
void UsersController<T>::addUser(int id, time_t birthday, int gender, int city_id, time_t time_reg){
  char buff[10];
  struct std::tm bd = *localtime(&birthday);
  snprintf(buff, sizeof(buff), "%02d", bd.tm_mon + 1);
  std::string bd_month = buff;
  snprintf(buff, sizeof(buff), "%02d", bd.tm_mday);
  std::string bd_day = buff;
  struct std::tm tr = *localtime(&time_reg);
  snprintf(buff, sizeof(buff), "%02d", tr.tm_mon + 1);
  std::string tr_month = buff;
  snprintf(buff, sizeof(buff), "%02d", tr.tm_mday);
  std::string tr_day = buff;
  snprintf(buff, sizeof(buff), "%02d", tr.tm_hour);
  std::string tr_hour = buff;
  snprintf(buff, sizeof(buff), "%02d", tr.tm_min);
  std::string tr_min = buff;
  snprintf(buff, sizeof(buff), "%02d", tr.tm_sec);
  std::string tr_sec = buff;

  std::string queryString;
  queryString = "INSERT INTO user(id, birthday, gender, city_id, time_reg) VALUES (" + std::to_string(id) + ", " + "\'" +
      std::to_string(bd.tm_year + 1900) + "-" + bd_month + "-" + bd_day + " 00:00:00\', " +
      std::to_string(gender) + ", " + std::to_string(city_id) + ", \'" +
      std::to_string(tr.tm_year + 1900) + "-" + tr_month + "-" + tr_day + " " +
      tr_hour + ":" + tr_min + ":" + tr_sec + "\')";

  std::cout << queryString << std::endl;
  dbAccessor->execQuery(queryString);
}

template <class T>
void UsersController<T>::getAllUsers(){
  typename T::IResult* res = dbAccessor->execQuery(std::string("SELECT * FROM user"));
  while (res->next()) {
    std::cout << "\t... MySQL replies: ";
    /* Access column data by alias or column name */
    std::cout << res->getString("id") << " " << res->getString("birthday") << " " << res->getString("gender") << " " <<
        res->getString("city_id") << " " << res->getString("time_reg") << std::endl;
    std::cout << "\t... MySQL says it again: ";
    /* Access column data by numeric offset, 1 is the first column */
    std::cout << res->getString(1) << std::endl;
  }
}

} // namespace DataControl

#endif //CONTROLLER_H
