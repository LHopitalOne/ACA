#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <map>
#include <vector>
#include <list>
#include <utility>

using namespace std;

template<typename T1, typename T2, typename Hash>
class hash_table
{
private:
    std::size_t mSize = 0;
    Hash hash;
    vector<list<pair<T1, T2>>> data;

public:
    hash_table(std::size_t initial_capacity = 0, Hash hash = Hash());

    void insert(const T1& key, const T2& value);
    bool remove(const T1& key);
    bool find(const T1& key, T2& value) const;

    std::size_t size() const;
    bool is_empty() const;
};

template <typename T1, typename T2, typename Hash>
hash_table<T1, T2, Hash>::hash_table(std::size_t initial_capacity, Hash hash)
    : hash(hash),
      data(vector<list<pair<T1, T2>>>(initial_capacity)) {}

template <typename T1, typename T2, typename Hash>
void hash_table<T1, T2, Hash>::insert(const T1 &key, const T2 &value)
{
    std::size_t index = hash(key) % data.size();
    for (auto& pair : data[index])
    {
        if (pair.first == key)
        {
            pair.second = value;
            return;
        }
    }
    data[index].emplace_back(key, value);
    mSize++;
}

template <typename T1, typename T2, typename Hash>
bool hash_table<T1, T2, Hash>::remove(const T1 &key)
{
    std::size_t index = hash(key) % data.size();
    auto& bucket = data[index];
    for (auto it = bucket.begin(); it != bucket.end(); it++)
    {
        if (it->first == key)
        {
            bucket.erase(it);
            --mSize;
            return true;
        }
    }
    return false;
}

template <typename T1, typename T2, typename Hash>
bool hash_table<T1, T2, Hash>::find(const T1 &key, T2 &value) const
{
    std::size_t index = hash(key) % data.size();
    const auto& bucket = data[index];
    for (auto& pair : bucket)
    {
        if (pair.first == key)
        {
            value = pair.second;
            return true;
        }
    }
    return false;
}

template <typename T1, typename T2, typename Hash>
std::size_t hash_table<T1, T2, Hash>::size() const
{
    return mSize;
}

template <typename T1, typename T2, typename Hash>
bool hash_table<T1, T2, Hash>::is_empty() const
{
    return mSize == 0;
}

#endif // HASH_TABLE_HPP
