#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>
#include <string>
#include <iostream>

namespace DataControl {

template <class T>
class UsersController {
public:
  UsersController(std::shared_ptr<T> accessor);

public:
  void addUser();
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
