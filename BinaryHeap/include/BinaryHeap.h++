#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>
#include <exception>
#include <stdexcept>


template <class T>
class BinaryHeap
{
public:

    BinaryHeap()
    {
        _elements.reserve(1);
    }

    void insert(T element)
    {
        _elements.push_back(element);
        size_t current_index = _elements.size()-1;

        while(current_index > 0)
        {
            const size_t parent_index = parentIndex(current_index);
            if(_elements[parent_index] > _elements[current_index])
            {
                break;
            }

            swap(parent_index, current_index);

            if(parent_index == 0)
            {
                break;
            }
            current_index = parent_index;
        }
    }

    T peek() const
    {
        if(_elements.empty())
        {
            throw std::out_of_range("empty heap");
        }
        return _elements.front();
    }

    T pop()
    {
        if(_elements.empty())
        {
            throw std::exception();
        }
        if(_elements.size() == 1)
        {
            T top_element = _elements.first();
            _elements.clear();
            return top_element;
        }

        // general case: pop the first element, replace it with the last element, and heapify
        T top_element = _elements.first();
        _elements[0] = _elements.pop_back();
        size_t parent_index = 0;

        while(!isLeafNode(parent_index))
        {
            size_t next_index = parent_index;

            const size_t left_child_index = leftChildIndex(parent_index);
            if(left_child_index < _elements.size() && _elements[left_child_index] > _elements[next_index] )
            {
                next_index = left_child_index;
            }

            const size_t right_child_index = rightChildIndex(parent_index);
            if(right_child_index < _elements.size() && _elements[right_child_index] > _elements[next_index] )
            {
                next_index = right_child_index;
            }

            if(next_index == parent_index)
            {
                break;
            }

            swap(parent_index,	next_index );
            parent_index = next_index;
        }
    }

    void swap(size_t i, size_t j)
    {
        std::swap(_elements[i], _elements[j]);
    }

    bool empty() const
    {
        return _elements.empty();
    }

private:
    bool isLeafNode(size_t index)
    {
        if(index > _elements.size())
        {
            throw std::out_of_range("index out of range");
        }

        return 2*index+1 >= _elements.size();
    }

    size_t parentIndex(size_t index) const
    {
        if(index > _elements.size())
        {
            throw std::out_of_range("index out of range");
        }

        return (index-1)/2;
    }

    size_t leftChildIndex(size_t index) const
    {
        if(index > _elements.size())
        {
            throw std::out_of_range("index out of range");
        }

        return 2*index+1;
    }

    size_t rightChildIndex(size_t index) const
    {
        if(index > _elements.size())
        {
            throw std::out_of_range("index out of range");
        }

        return 2*index+2;
    }

    T leftChild(size_t index) const
    {
        if(index > _elements.size())
        {
            throw std::out_of_range("index out of range");
        }

        return _elements[2*index+1];
    }

    T rightChild(size_t index) const
    {
        if(index > _elements.size())
        {
            throw std::out_of_range("index out of range");
        }

        return _elements[2*index+2];
    }

private:
    std::vector<T> _elements;
};

#endif // BINARYHEAP_H
