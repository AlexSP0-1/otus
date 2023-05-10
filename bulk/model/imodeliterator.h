#ifndef IMODELITERATOR_H
#define IMODELITERATOR_H

#include "modeliterator.h"

class IModelIterator
{
public:
    virtual ~IModelIterator() = default;

    virtual iterator cbegin() const = 0;

    virtual iterator cend() const = 0;

    virtual std::string getTime() const = 0;
};

#endif // IMODELITERATOR_H
