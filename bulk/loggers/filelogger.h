#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "../model/observer.h"

class FileLogger : public IObserver
{
public:
    FileLogger() = default;

    ~FileLogger();
    virtual void process(const IModelIterator &model) override;
};

#endif
