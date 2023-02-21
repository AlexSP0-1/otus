#ifndef INTEGRALTYPEPRINTER_H
#define INTEGRALTYPEPRINTER_H

#include <ipfunctions.h>
#include <iostream>

template<typename T, class = TypeTemplates::EnableIfIntegralType<T>>
class IntegralTypePrinter {
public:
    IntegralTypePrinter(const T &param) : value(param) {}

    friend std::ostream& operator<<(std::ostream &outputStream, const T& param) {
        for(size_t i = param.typeSize; i > 0; i--) {
            outputStream << +param.bytes[i] << '.';
        }
        return outputStream << param.bytes[0];
    }

private:
    union {
        uint8_t bytes[sizeof(T)];
        T value;
    };

    static constexpr size_t typeSize = sizeof(T) - 1;
};

#endif //INTEGRALTYPEPRINTER
