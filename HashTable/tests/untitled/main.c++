#define BOOST_TEST_MODULE HashSuite
#include <boost/test/included/unit_test.hpp>

#include <HashTable.h++>

BOOST_AUTO_TEST_CASE( HashCase )
{
    //Given
    HashTable<int, int> table;

    //When

    //Then
    BOOST_TEST( true /* test assertion */ );
}
