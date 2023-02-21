#ifndef IPPRINTERS_H
#define INTEGRALTYPEPRINTER_H

#include "ipfunctions.h"
#include <iostream>
#include <experimental/iterator>
#include <tuple>


/*! \brief Prints integral types
 *
 */
template<typename T, class = TypeTemplates::EnableIfIntegralType<T>>
class IntegralTypePrinter {
public:
    IntegralTypePrinter(const T &param) : value(param) {}

    friend std::ostream& operator<<(std::ostream &outputStream, const IntegralTypePrinter& param) {
        for(size_t i = param.typeSize; i > 0; i--) {
            outputStream << +param.bytes[i] << '.';
        }
        return outputStream << +param.bytes[0];
    }

private:
    union {
        uint8_t bytes[sizeof(T)];
        T value;
    };

    static constexpr size_t typeSize = sizeof(T) - 1;
};

template<typename T, typename ... Args>
void printArgs(std::ostream &stream, const T &firstArg, const Args& ... args) {
    stream << firstArg;
    (void) std::initializer_list<int>{((stream << '.' << args), 0)...};
}

/*! \brief Prints integral types
 *
 * Template function for printing integral types. Uses IntegralTypePrinter
 */
template<typename T>
typename TypeTemplates::EnableIfIntegralType<T>
print_ip(const T &param) {
    std::cout << IntegralTypePrinter(param) << std::endl;
}

/*! \brief Prints std::string
 *
 * Template function for printing std::string.
 */
template <typename T>
typename TypeTemplates::EnableIfStringType<T>
print_ip(const T &param) {
    std::cout << param <<std::endl;
}

/*! \brief Prints containers
 *
 * Template function for printing containters, such as std::vector and std:list.
 */
template<typename T, template<typename> class Container>
typename TypeTemplates::EnableIfContainerType<T, Container>
print_ip(const Container<T> &param) {
    std::copy(std::begin(param), std::end(param),
              std::experimental::make_ostream_joiner(std::cout, "."));

    std::cout << std::endl;
}

template<typename ... Ts>
std::ostream &operator<<(std::ostream &stream, const std::tuple<Ts...> &param) {

    auto printToStream = [&stream] (const auto&... args) {
        printArgs(stream, args ... );
    };

    std::apply(printToStream, param);

    return stream;
}

/** \brief Prints std::tuple
 *
 * Template function for printing std::tuple.
 */
template<typename T, typename... Args>
typename TypeTemplates::EnableIfAllTheSame<T, Args...>
print_ip(const std::tuple<T, Args... >&params) {
    using namespace TypeTemplates;

    std::cout << params;
}

#endif //IPPRINTERS_H
