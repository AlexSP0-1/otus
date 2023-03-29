#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "icontroller.h"

#include "imodel.h"

class Controller : public IController
{
public:
    Controller(IModel *model, IObserver *view);
    virtual ~Controller() = default;

    virtual void commandClear() override;

    virtual void commandNewPoint(const Point &point) override;

    virtual void commandNewLine(const Point &begin, const Point &end) override;

    virtual void commandNewCircle(const Point &center, const int radius) override;

    virtual void commandRemoveShape() override;

    virtual void commandLoad(const std::string &filename) override;

    virtual void commandSave(const std::string &filename) override;

    virtual void loop() override;

    virtual bool readCommand() override;

private:
    IModel *m_model;
    IObserver *m_view;
};

#endif // CONTROLLER_H
