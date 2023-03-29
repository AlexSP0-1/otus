#ifndef KEY_H
#define KEY_H

#include <cstdint>
#include <iostream>
#include <tuple>

#include <extypes.h>

namespace SparseMatrix
{
template<size_t Size>
class Key
{
public:
    Key() = delete;

    template<typename... Ts, typename = std::enable_if_t<Size == sizeof...(Ts)>>
    Key(Ts... args)
        : indexes(std::make_tuple(args...))
    {}

    template<typename... Ts, typename = std::enable_if_t<Size == sizeof...(Ts)>>
    Key(const std::tuple<Ts...> &tupleArgs)
        : indexes(tupleArgs)
    {}

    bool operator==(const Key &other) const { return indexes == other.indexes; }

    auto getIndexes() const { return indexes; }

    TupleAllArgs<Size> indexes;
};
} // namespace SparseMatrix
#endif // KEY_H
