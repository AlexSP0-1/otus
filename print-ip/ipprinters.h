#ifndef IPPRINTERS_H
#define INTEGRALTYPEPRINTER_H

#include "ipfunctions.h"
#include <iostream>
#include <experimental/iterator>

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

//Prints integral type
template<typename T>
typename TypeTemplates::EnableIfIntegralType<T>
print_ip(const T &param) {
    std::cout << IntegralTypePrinter(param) << std::endl;
}

//prints string
template <typename T>
typename TypeTemplates::EnableIfStringType<T>
print_ip(const T &param) {
    std::cout << param <<std::endl;
}

//prints container
template<typename T, template<typename> class Container>
typename TypeTemplates::EnableIfContainerType<T, Container>
print_ip(const Container<T> &param) {
    std::copy(std::begin(param), std::end(param),
              std::experimental::make_ostream_joiner(std::cout, "."));

    std::cout << std::endl;
}

#endif //IPPRINTERS_H
