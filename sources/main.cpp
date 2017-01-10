#include <iostream>
#include <cstddef>

#include "../includes/application.h"

using namespace std;

int main(void)
{
  int menuItem = -1;

  while (true) {
    cout <<
R"(Select menue item:
1. Generate database
2. Add random user
0. Exit)" << endl;

    cin >> menuItem;

    switch(menuItem) {
      case(1): {
        Application::fillDatabase();
        break;
      }
      case(2): {
        Application::addRandomUser();
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
