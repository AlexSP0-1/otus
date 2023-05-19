#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "../model/observer.h"

#include <iostream>

class ConsoleLogger : public IObserver
{
public:
    virtual ~ConsoleLogger() = default;

    void process(const IModelIterator &model) override;
};

#endif
