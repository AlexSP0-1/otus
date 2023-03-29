#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObserver {
public:
    IObserver() = default;
    virtual ~IObserver() = default;

    virtual void update() const = 0;
};

#endif
