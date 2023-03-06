#ifndef PRIMITIVESFACTORY_H
#define PRIMITIVESFACTORY_H

#include <ipfactory.h>
#include <igraphprimitive.h>

class BasePrimitiveFactory : public IPFactory {
public:
    BasePrimitiveFactory() = default;
    virtual ~BasePrimitiveFactory() = default;

public:
    virtual std::unique_ptr<IGraphPrimitiveObject> create(const Point &beginPoint) override;

    virtual std::unique_ptr<IGraphPrimitiveObject> create(const Point &beginPoint, const Point &endPoint) override;

    virtual std::unique_ptr<IGraphPrimitiveObject> create(const Point &beginPoint, const int radius) override;
};

class PointPrimitiveFactory : public BasePrimitiveFactory {
public:
    PointPrimitiveFactory() = default;
    virtual ~PointPrimitiveFactory() = default;

    virtual std::unique_ptr<IGraphPrimitiveObject> create(const Point &beginPoint) override;
};

class LinePrimitiveFactory : public BasePrimitiveFactory {
public:
    LinePrimitiveFactory() = default;
    virtual ~LinePrimitiveFactory() = default;

    virtual std::unique_ptr<IGraphPrimitiveObject> create(const Point &beginPoint, const Point &endPoint) override;
};

class CirclePrimitiveFactory : public BasePrimitiveFactory {
public:
    CirclePrimitiveFactory() = default;
    virtual ~CirclePrimitiveFactory() = default;

    virtual std::unique_ptr<IGraphPrimitiveObject> create(const Point &beginPoint, const int radius) override;
};

#endif
