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
#include "controller/controller.h"

using namespace std;
using namespace MySQLAccessor;
using namespace DataControl;

int main(void)
{
  shared_ptr<IDatabase> db(new MySQLDB());
  db->connect();
  db->setSchema(string("users"));
  Controller<IDatabase> controller(db);

  IDatabase::IResult* res = db->execQuery(string("SELECT * FROM user"));
  while (res->next()) {
    cout << "\t... MySQL replies: ";
    /* Access column data by alias or column name */
    cout << res->getString("id") << " " << res->getString("birthday") << " " << res->getString("gender") << " " <<
        res->getString("city_id") << " " << res->getString("time_reg") << endl;
    cout << "\t... MySQL says it again: ";
    /* Access column data by numeric offset, 1 is the first column */
    cout << res->getString(1) << endl;
  }
  return EXIT_SUCCESS;
}
