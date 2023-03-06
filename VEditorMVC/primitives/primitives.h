#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "igraphprimitive.h"

class GraphPrimitiveObject : public IGraphPrimitiveObject
{
public:
    GraphPrimitiveObject(const Point &location);

    virtual ~GraphPrimitiveObject() = default;

public:
    void draw(IPainter *painter) const override;
    void setEnd(const Point &endPoint) override;
    void setRadius(const int radius) override;
    void setLocation(const Point &location);

protected:
    Point m_location;
};

class PointPrimitive : public GraphPrimitiveObject
{
public:
    PointPrimitive(const Point &location);

    void draw(IPainter *painter) const override;
};

class LinePrimitive : public GraphPrimitiveObject
{
public:
    LinePrimitive(const Point &beginPoint, const Point &endPoint);

    void draw(IPainter *painter) const override;

    void setEnd(const Point &endPoint);

private:
    Point m_endPoint;
};

class CirclePrimitive : public GraphPrimitiveObject
{
public:
    CirclePrimitive(const Point &location, const int radius);

    void setRadius(const int radius) override;

    void draw(IPainter *painter) const override;

private:
    int m_radius = 0;
};

#endif
