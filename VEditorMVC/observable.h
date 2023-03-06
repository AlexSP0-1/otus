#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "iobserver.h"

#include <vector>

class Observable
{
public:
    Observable() = default;
    virtual ~Observable() = default;

    void subscribe(IObserver *observer);

    void unsibscribe(IObserver *observer);

    void notify();

private:
    std::vector<IObserver*> observers;
};

#endif // OBSERVABLE_H
