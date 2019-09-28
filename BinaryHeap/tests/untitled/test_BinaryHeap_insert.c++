#define BOOST_TEST_MODULE Suite
#include <boost/test/included/unit_test.hpp>

#include <BinaryHeap.h++>

BOOST_AUTO_TEST_SUITE(BinaryHeap_insert);

BOOST_AUTO_TEST_CASE( Given_EmptyBinaryHeap_When_insert0_Then_PeekEquals0)
{
    //Given
    BinaryHeap<int> binaryHeap;

    //When
    binaryHeap.insert(0);

    //Then
    BOOST_CHECK_EQUAL(binaryHeap.peek(), 0);
}

BOOST_AUTO_TEST_CASE( Given_BinaryHeapWithOneElement_When_InsertSmallerElement_Then_PeekEqualsOriginalParent)
{
    //Given
    BinaryHeap<int> binaryHeap;

    binaryHeap.insert(20);

    //When
    binaryHeap.insert(10);

    //Then
    BOOST_CHECK_EQUAL(binaryHeap.peek(), 20);
}


BOOST_AUTO_TEST_CASE( Given_BinaryHeapWithOneElement_When_InsertLargerElement_Then_PeekEqualsNewElement)
{
    //Given
    BinaryHeap<int> binaryHeap;

    binaryHeap.insert(20);

    //When
    binaryHeap.insert(30);

    //Then
    BOOST_CHECK_EQUAL(binaryHeap.peek(), 30);
}

BOOST_AUTO_TEST_CASE( Given_BinaryHeapWithThreeElements_When_InsertLargerElement_Then_PeekEqualsNewElement)
{
    //Given
    BinaryHeap<int> binaryHeap;

    binaryHeap.insert(10);
    binaryHeap.insert(20);
    binaryHeap.insert(30);

    //When
    int lastElement = 40;
    binaryHeap.insert(lastElement);

    //Then
    BOOST_CHECK_EQUAL(binaryHeap.peek(), lastElement);
}

BOOST_AUTO_TEST_CASE( Given_BinaryHeapWithFourElements_When_InsertLargerElement_Then_PeekEqualsNewElement)
{
    //Given
    BinaryHeap<int> binaryHeap;

    binaryHeap.insert(10);
    binaryHeap.insert(20);
    binaryHeap.insert(30);
    binaryHeap.insert(40);

    //When
    int lastElement = 50;
    binaryHeap.insert(lastElement);

    //Then
    BOOST_CHECK_EQUAL(binaryHeap.peek(), lastElement);
}

BOOST_AUTO_TEST_SUITE_END();
