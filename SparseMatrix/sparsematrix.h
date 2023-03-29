#ifndef SPARSEMARIX_H
#define SPARSEMARIX_H

#include <unordered_map>

#include "extypes.h"
#include "hash.h"
#include "key.h"

namespace SparseMatrix
{
template<typename T, T defaultValue, size_t Rank = 2>
class SparseMatrix
{
private:
    template<std::size_t TI>
    using Tuple = TupleAllArgs<TI>;

    template<std::size_t TP>
    using Key = Key<TP>;

    template<template<std::size_t> class TK>
    using Hash = Hash<TK>;

    using KeeperType = std::unordered_map<Key<Rank>, T, Hash<Key>>;

    template<std::size_t R, std::size_t Sz>
    class Indexer
    {
    public:
        Indexer(KeeperType &inKeeper, const std::size_t &index)
            : refKeeper(inKeeper)
            , currentTuple(std::tuple<size_t>(index))
        {}

        template<typename... Ts>
        Indexer(KeeperType &inKeeper, const std::size_t &index, const std::tuple<Ts...> &inTuple)
            : refKeeper(inKeeper)
            , currentTuple(std::tuple_cat(inTuple, std::tuple<std::size_t>(index)))
        {}

        Indexer<R - 1, Sz> operator[](const std::size_t &index)
        {
            return Indexer<R - 1, Sz>(refKeeper, index, currentTuple);
        }

    private:
        KeeperType &refKeeper;
        Tuple<Sz - R> currentTuple;
    };

    template<std::size_t Sz>
    class Indexer<0, Sz>
    {
    public:
        template<typename... Ts>
        Indexer(KeeperType &inKeeper, const std::size_t &index, const std::tuple<Ts...> &inTuple)
            : refKeeper(inKeeper)
            , resultTuple(std::tuple_cat(inTuple, std::tuple<std::size_t>(index)))
        {}

        auto &operator=(const T &value)
        {
            if (value != defaultValue)
            {
                refKeeper[Key<Rank>(resultTuple)] = value;
            }
            else
            {
                refKeeper.erase(Key<Rank>(resultTuple));
            }

            return *this;
        }

        auto &operator==(const T &value)
        {
            auto search = refKeeper.find(Key<Rank>(resultTuple));

            T foundValue{search == refKeeper.end() ? defaultValue : search->second};

            if (foundValue == value)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        operator T() const
        {
            auto search = refKeeper.find(Key<Rank>(resultTuple));

            if (search == refKeeper.end())
            {
                return defaultValue;
            }
            else
            {
                return search->second;
            }
        }

    private:
        KeeperType &refKeeper;
        Tuple<Rank> resultTuple;
    };

    class Iterator
    {
    public:
        Iterator(typename KeeperType::const_iterator argIter)
            : curIterator(argIter)
        {}

        Iterator operator++()
        {
            ++curIterator;
            return *this;
        }

        bool operator!=(const Iterator &other) const { return curIterator != other.curIterator; }

        const auto operator*() const
        {
            return std::tuple_cat(curIterator->first.indexes, std::make_tuple(curIterator->second));
        }

    private:
        typename KeeperType::const_iterator curIterator;
    };

public:
    SparseMatrix()  = default;
    ~SparseMatrix() = default;

    auto operator[](const std::size_t &index)
    {
        return Indexer<Rank - 1, Rank>(this->keeper, index);
    }

    std::size_t size() { return keeper.size(); }

    Iterator begin() const { return Iterator(keeper.cbegin()); }

    Iterator end() const { return Iterator(keeper.cend()); }

private:
    KeeperType keeper;
};
} // namespace SparseMatrix
#endif // SPARSEMARIX_H
