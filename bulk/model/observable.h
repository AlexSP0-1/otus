#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "imodeliterator.h"
#include "observer.h"

#include <list>
#include <memory>

class Observable
{
public:
    Observable();

    virtual ~Observable() = default;

    void notify(const IModelIterator &model);

    void subscribe(std::shared_ptr<IObserver> observer);

private:
    std::list<std::shared_ptr<IObserver>> m_observers;
};

#endif // OBSERVABLE_H
