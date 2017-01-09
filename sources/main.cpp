//#include <cstddef>
//
//#include <boost/scoped_ptr.hpp>
//#include <boost/thread.hpp>
//
//#include <calculator/calculator.h>
//#include <generator/generator.h>
//
//#include <includes/counter.h>
//
//const unsigned MAX_COUNTERS = 10;
//const size_t COUNTER_LIMIT = 1000;
//
//int main(int /*argc*/, char* /*argv*/[])
//{
//	Utils::Calculator calculator(10.0);
//
//	boost::scoped_ptr<Utils::Generator> generator(new Utils::Generator());
//	boost::thread_group threads;
//	for (unsigned i = 0; i != MAX_COUNTERS; ++i)
//	{
//		threads.create_thread(Counter(generator.get(), COUNTER_LIMIT));
//	}
// 	threads.join_all();
//
//	return 0;
//}

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

  return EXIT_SUCCESS;
}
