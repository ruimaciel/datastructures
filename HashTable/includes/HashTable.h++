#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <utility>
#include <numeric>
#include <algorithm>

template<class TKey, class TValue>
class HashTable
{
    using Bucket = std::vector< std::pair<TKey, TValue> >;

public:
    HashTable()
    {
        _hashTable.resize(8);
    }

    void insert(TKey key, TValue value)
    {
        const size_t index = hashValue(key);

        _hashTable[index].push_back( std::make_pair(key, value));
    }

    TValue get(TKey key)
    {
        const Bucket &bucket = _hashTable[hashValue(key)];

        auto predicate = [&key] (const std::pair<TKey, TValue> &p) -> bool
        {
            return p.first == key;
        };

        auto iter = std::find_if(bucket.begin(), bucket.end(), predicate);
        if(iter == bucket.end())
        {
            return TValue();
        }

        return iter->second;
    }

    void remove(TKey key)
    {
        Bucket &bucket = _hashTable[hashValue(key)];
        if(bucket.empty())
        {
            return;
        }

        auto predicate = [&key] (const std::pair<TKey, TValue> &p) -> bool
        {
            return p.first == key;
        };

        auto iter = std::find_if(bucket.begin(), bucket.end(), predicate);
        if(iter == bucket.end())
        {
            return;
        }

        bucket.erase(iter);

        return;

    }

    size_t size() const
    {
        size_t element_count = 0;

        auto op = [](size_t &x, const Bucket &y) -> size_t
        {
            return x + y.size();
        };

        return std::accumulate(_hashTable.begin(), _hashTable.end(), element_count, op);
    }

private:
    size_t hashValue(TKey key) const
    {
        const size_t hash_value = std::hash<TKey>()(key);
        return hash_value % _hashTable.size();
    }

private:
    std::vector<Bucket> _hashTable;
};

#endif // HASHTABLE_H
