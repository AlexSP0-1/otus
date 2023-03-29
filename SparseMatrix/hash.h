#ifndef HASH_H
#define HASH_H

#include <cstdint>
#include <iostream>
#include <tuple>

#include "key.h"

namespace SparseMatrix
{
template<typename T>
T sumArgs(T &arg)
{
    return arg;
}

template<typename T, typename T1, typename... Ts>
std::size_t sumArgs(T &firstArg, T1 &secondArg, Ts &...otherArgs)
{
    T hash_pairing = ((firstArg + secondArg) * (firstArg + secondArg + 1)) / 2 + secondArg;

    if constexpr (sizeof...(Ts) > 0)
    {
        return sumArgs(hash_pairing, otherArgs...);
    }
    else
    {
        return hash_pairing;
    }
}

template<template<std::size_t> class Key>
class Hash
{
public:
    template<std::size_t Size>
    std::size_t operator()(const Key<Size> &key) const
    {
        auto hashSumTuple = [](const auto &...args) { return sumArgs(args...); };

        return std::apply(hashSumTuple, key.getIndexes());
    }
};
} // namespace SparseMatrix
#endif // HASH_H
