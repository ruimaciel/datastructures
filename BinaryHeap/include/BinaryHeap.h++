#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>
#include <exception>
#include <stdexcept>


template <class T>
class BinaryHeap
{
public:

    void bubble()
    {
    }

    void insert(T element)
    {
        _elements.push_back(element);

        // perform bubble-up operation
        const size_t current_index = _elements.size()-1;
        bubbleUp(_elements, current_index);
    }

    T peek() const
    {
        if(_elements.empty())
        {
            throw std::out_of_range("Called peek() on an empty heap");
        }
        return _elements.at(0);
    }

    T pop()
    {
        if(_elements.empty())
        {
            throw std::out_of_range("Called pop() on an empty heap");
        }

        T popped = _elements.front();

        T last = _elements.pop_back();

        if(_elements.empty())
        {
            return popped;
        }

        _elements[0] = last;

        size_t current_index = 0;
        size_t left_child_index = getLeftChildIndex(current_index);
        while(left_child_index < _elements.size())
        {
            size_t max_child_index = left_child_index;
            size_t right_child_index = getRightChildIndex(current_index);
            if(right_child_index < _elements.size() &&  _elements[right_child_index] > _elements[left_child_index])
            {
                max_child_index = right_child_index;
            }

            if(_elements[current_index] > _elements[max_child_index])
            {
                break;
            }

            std::swap(_elements[current_index], _elements[max_child_index]);
            current_index = max_child_index;
            left_child_index = getLeftChildIndex(current_index);
        }

        return popped;
    }

    bool empty() const
    {
        return _elements.empty();
    }

    static void bubbleUp(std::vector<T> & elements, size_t current_index)
    {
        while(current_index > 0)
        {
            const size_t parent_index = getParentIndex(current_index);
            if(elements[current_index] <= elements[parent_index])
            {
                break;
            }

            std::swap(elements[parent_index], elements[current_index]);
            current_index = parent_index;
        }
    }


private:
    static size_t getParentIndex(size_t i)
    {
        return (i-1)/2;
    }

    static size_t getLeftChildIndex(size_t i)
    {
        return 2*i+1;
    }

    static size_t getRightChildIndex(size_t i)
    {
        return 2*i+2;
    }


private:
    std::vector<T> _elements;
};

#endif // BINARYHEAP_H
