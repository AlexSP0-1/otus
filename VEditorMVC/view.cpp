#include "view.h"

View::View(IModel *model, IPainter *painter)
    : m_model(model)
    , m_painter(painter)
{}

void View::update() const
{
    m_model->draw(m_painter);
}
