#ifndef EXTYPES_H
#define EXTYPES_H

#include <cstdint>
#include <iostream>
#include <tuple>

namespace SparseMatrix
{
constexpr auto params(std::index_sequence<0>)
{
    return std::tuple<size_t>{};
}

template<std::size_t I, std::size_t... other>
constexpr auto params(std::index_sequence<I, other...>)
{
    auto tuple = std::tuple{size_t{}};

    auto sequence = std::make_index_sequence<sizeof...(other)>{};

    return std::tuple_cat(tuple, params(sequence));
}

template<std::size_t N>
constexpr auto generateTuple(std::integral_constant<std::size_t, N>)
{
    return params(std::make_index_sequence<N>{});
}

template<std::size_t Size>
using TupleAllArgs = decltype(generateTuple(std::integral_constant<std::size_t, Size>{}));

template<typename T, typename... Ts>
void printArgs(std::ostream &curStream, const T &firstArg, const Ts &...tailArgs)
{
    curStream << firstArg;
    (void) std::initializer_list<int>{((curStream << tailArgs), 0)...};
}

template<typename... Ts>
std::ostream &operator<<(std::ostream &curStream, const std::tuple<Ts...> &inParameter)
{
    auto printToStream = [&curStream](const auto &...lyambdaArgs) {
        printArgs(curStream, lyambdaArgs...);
    };

    std::apply(printToStream, inParameter);

    return curStream;
}
} // namespace SparseMatrix
#endif // EXTYPES_H
