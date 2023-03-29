#ifndef VIEW_H
#define VIEW_H

#include "imodel.h"
#include "iobserver.h"

class View : public IObserver
{
public:
    View(IModel *model, IPainter *painter);

    virtual ~View() = default;
    virtual void update() const override;

private:
    IModel *m_model;
    IPainter *m_painter;
};

#endif // VIEW_H
