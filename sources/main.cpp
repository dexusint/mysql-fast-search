#include <iostream>
#include <cstddef>


#include "mysql-accessor/mysqldb.h"
#include "users-controller/userscontroller.h"

using namespace std;
using namespace MySQLAccessor;
using namespace DataControl;

int main(void)
{
  shared_ptr<IDatabase> db(new MySQLDB());
  db->connect("root", "123456");
  db->setSchema("users");
  UsersController<IDatabase> usersController(db);
  usersController.getAllUsers();

  int menuItem = -1;

  while (true) {
    cout <<
        R"(Select menue item:
          1. Generate database
          0. Exit)" << endl;

    cin >> menuItem;

    switch(menuItem) {
      case(1): {

        break;
      }
      case(2): {

        break;
      }
      case(0): {
        cout << "Good bye!";
        return 0;
      }
    }
  }

  return EXIT_SUCCESS;
}
