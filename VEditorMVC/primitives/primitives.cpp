#include "primitives.h"

GraphPrimitiveObject::GraphPrimitiveObject(const Point &location)
    : m_location{location.xCoord, location.yCoord}
{}

void GraphPrimitiveObject::draw(IPainter *painter) const {}

void GraphPrimitiveObject::setEnd(const Point &endPoint) {}

void GraphPrimitiveObject::setRadius(const int radius) {}

void GraphPrimitiveObject::setLocation(const Point &location) {}

PointPrimitive::PointPrimitive(const Point &location)
    : GraphPrimitiveObject(location)
{}

void PointPrimitive::draw(IPainter *painter) const
{
    painter->drawPoint(m_location);
}

LinePrimitive::LinePrimitive(const Point &beginPoint, const Point &endPoint)
    : GraphPrimitiveObject(beginPoint)
    , m_endPoint(endPoint)
{}

void LinePrimitive::draw(IPainter *painter) const
{
    painter->drawLine(m_location, m_endPoint);
}

void LinePrimitive::setEnd(const Point &endPoint)
{
    m_endPoint = endPoint;
}

CirclePrimitive::CirclePrimitive(const Point &location, const int radius)
    : GraphPrimitiveObject(location)
    , m_radius(radius)
{}

void CirclePrimitive::setRadius(const int radius)
{
    m_radius = radius;
}

void CirclePrimitive::draw(IPainter *painter) const
{
    painter->drawCircle(m_location, m_radius);
}
