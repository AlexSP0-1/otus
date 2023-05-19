#ifndef OBSERVER_H
#define OBSERVER_H

#include "imodeliterator.h"

class IObserver
{
public:
    IObserver() = default;

    virtual ~IObserver() = default;

    virtual void process(const IModelIterator &) = 0;
};

#endif // OBSERVER_H
