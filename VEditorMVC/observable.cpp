#include "observable.h"
#include <algorithm>

void Observable::subscribe(IObserver *observer)
{
    if(observer != nullptr) {
        observers.push_back(observer);
    }
}

void Observable::unsibscribe(IObserver *observer)
{
    observers.erase(std::remove_if(observers.begin(), observers.end(),
                                   [observer] (IObserver *obs){return observer==obs;}));

}

void Observable::notify()
{
    for(auto currentObserver : observers) {
        currentObserver->update();
    }
}
