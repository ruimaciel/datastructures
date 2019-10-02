#define BOOST_TEST_MODULE HashSuite
#include <boost/test/included/unit_test.hpp>

#include <HashTable.h++>

BOOST_AUTO_TEST_CASE( HashCase )
{
    //Given
    HashTable<int, int> table;

    //When

    //Then
    BOOST_CHECK_EQUAL( table.size(), 0);
}


BOOST_AUTO_TEST_CASE( Given_EmptyHashTable_When_Insert_Then_SizeIsOne )
{
    //Given
    HashTable<int, int> table;

    //When
    table.insert(10,1);

    //Then
    BOOST_CHECK_EQUAL( table.size(), 1);
}


BOOST_AUTO_TEST_CASE( Given_HashTableWithOneElement_When_Get_Then_ResultIsEqualToElement )
{
    //Given
    HashTable<int, int> table;

    table.insert(10, 42);
    //When

    int value = table.get(10);

    //Then
    BOOST_CHECK_EQUAL( value, 42);
}


BOOST_AUTO_TEST_CASE( Given_HashTableWithTwoElementsWithSameHash_When_Get_Then_ResultIsEqualToElement )
{
    //Given
    HashTable<int, int> table;

    table.insert(10, 42);
    table.insert(20, 24);
    //When

    int value1 = table.get(10);
    int value2 = table.get(20);

    //Then
    BOOST_CHECK_EQUAL( value1, 42);
    BOOST_CHECK_EQUAL( value2, 24);
}

BOOST_AUTO_TEST_CASE( Given_EmptyHashTable_When_Remove_Then_SizeIsOne )
{
    //Given
    HashTable<int, int> table;

    table.insert(10,1);

    //When
    table.remove(10);

    //Then
    BOOST_CHECK_EQUAL( table.size(), 0);
}

