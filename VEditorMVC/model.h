#ifndef MODEL_H
#define MODEL_H

#include <vector>

#include "primitives/igraphprimitive.h"
#include "primitives/registryprimitives.h"

#include "imodel.h"

class Model : public IModel
{
public:
    Model()          = default;
    virtual ~Model() = default;

    virtual void newModel() override;

    virtual void openModel(std::string &) override;

    virtual void saveModel(std::string &) override;

    virtual void addPoint(const Point &beginPoint) override;

    virtual void addLine(const Point &beginPoint, const Point &endPoint) override;

    virtual void addCirlce(const Point &beginPoint, const int) override;

    virtual void removeLast() override;

    virtual void draw(IPainter *painter) override;

private:
    std::vector<std::unique_ptr<IGraphPrimitiveObject>> graphObjects;

    RegistryPrimitives factoryObjects;
};

#endif // MODEL_H
