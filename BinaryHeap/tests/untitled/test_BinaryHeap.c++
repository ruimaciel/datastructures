#define BOOST_TEST_MODULE Suite
#include <boost/test/included/unit_test.hpp>

#include <BinaryHeap.h++>

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


BOOST_AUTO_TEST_SUITE(BinaryDir_bubbleUp);

BOOST_AUTO_TEST_CASE( Given_CurrentVectorIsSmallerThanRoot_When_BubbleUp_Then_RootElementIsUnchanged)
{
    //Given
    std::vector<int> elements = {20,10};

    //When
    BinaryHeap<int>::bubbleUp(elements, 1);

    //Then
    BOOST_CHECK_EQUAL(elements.at(0), 20);
}

BOOST_AUTO_TEST_CASE( Given_ThreeElementVectorWithCurrentElementLargerThanRoot_When_BubbleUp_Then_RootElementChangesToCurrent)
{
    //Given
    std::vector<int> elements = {10,20,30};

    //When
    BinaryHeap<int>::bubbleUp(elements, 2);

    //Then
    BOOST_CHECK_EQUAL(elements.at(0), 30);
}



BOOST_AUTO_TEST_CASE( Given_FourElementVectorWithCurrentElementLargerThanRoot_When_BubbleUp_Then_RootElementChangesToCurrent)
{
    //Given
    std::vector<int> elements = {30,10,20,40};

    //When
    BinaryHeap<int>::bubbleUp(elements, 3);

    //Then
    BOOST_CHECK_EQUAL(elements.at(0), 40);
    BOOST_CHECK_EQUAL(elements.at(1), 30);
    BOOST_CHECK_EQUAL(elements.at(3), 10);
}

BOOST_AUTO_TEST_SUITE_END();
