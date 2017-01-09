#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <memory>

#include "controller.h"

namespace DataControl {

template <class T>
class Controller {
public:
  Controller(std::shared_ptr<T> accessor);
public:
  void addUser();
  void deleteUser();
  void getAllUsers();
  void getUser();
  void updateUser();

private:
  std::weak_ptr<T> dbAccessor = nullptr;
};

template <class T>
Controller<T>::Controller(std::shared_ptr<T> accessor):
dbAccessor(accessor)
{}

template <class T>
void Controller<T>::getAllUsers(){
//  dbAccessor->
//  IResult* res = dbAccessor->execQuery(string("SELECT * FROM user"));
//    while (res->next()) {
//      cout << "\t... MySQL replies: ";
//      /* Access column data by alias or column name */
//      cout << res->getString("id") << " " << res->getString("birthday") << " " << res->getString("gender") << " " <<
//          res->getString("city_id") << " " << res->getString("time_reg") << endl;
//      cout << "\t... MySQL says it again: ";
//      /* Access column data by numeric offset, 1 is the first column */
//      cout << res->getString(1) << endl;
//    }
}

} // namespace DataControl

#endif //CONTROLLER_H
