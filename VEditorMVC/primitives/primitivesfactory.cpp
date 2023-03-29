#include "primitives.h"
#include "primitivesfactory.h"

std::unique_ptr<IGraphPrimitiveObject> BasePrimitiveFactory::create(const Point &beginPoint)
{
    return nullptr;
}

std::unique_ptr<IGraphPrimitiveObject> BasePrimitiveFactory::create(const Point &beginPoint, const Point &endPoint)
{
    return nullptr;
}

std::unique_ptr<IGraphPrimitiveObject> BasePrimitiveFactory::create(const Point &beginPoint, const int radius)
{
    return nullptr;
}

std::unique_ptr<IGraphPrimitiveObject> PointPrimitiveFactory::create(const Point &beginPoint)
{
    return std::make_unique<PointPrimitive>(beginPoint);
}

std::unique_ptr<IGraphPrimitiveObject> LinePrimitiveFactory::create(const Point &beginPoint, const Point &endPoint)
{
    return std::make_unique<LinePrimitive>(beginPoint, endPoint);
}

std::unique_ptr<IGraphPrimitiveObject> CirclePrimitiveFactory::create(const Point &beginPoint, const int radius)
{
    return std::make_unique<CirclePrimitive>(beginPoint, radius);
}
