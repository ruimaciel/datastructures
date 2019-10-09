#define BOOST_TEST_MODULE Suite
#include <boost/test/included/unit_test.hpp>

#include <BinaryHeap.h++>

BOOST_AUTO_TEST_SUITE(BinaryHeap_bubbleUp);

BOOST_AUTO_TEST_CASE( Given_EmptyBinaryHeap_Then_EmptyReturnsTrue )
{
    //Given
    BinaryHeap<int> binaryHeap;

    //Then
    BOOST_TEST( binaryHeap.empty() );
}


BOOST_AUTO_TEST_CASE( Given_EmptyBinaryHeap_When_CallPeek_Then_ThrowException )
{
    //Given
    BinaryHeap<int> binaryHeap;

    //Then
    BOOST_CHECK_THROW(binaryHeap.peek(), std::out_of_range);
}

BOOST_AUTO_TEST_SUITE_END();
