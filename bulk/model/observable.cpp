#include "observable.h"

Observable::Observable()
    : m_observers({})
{}

void Observable::notify(const IModelIterator &model)
{
    for (auto observer : m_observers)
    {
        observer->process(model);
    }
}

void Observable::subscribe(std::shared_ptr<IObserver> observer)
{
    m_observers.push_back(observer);
}
