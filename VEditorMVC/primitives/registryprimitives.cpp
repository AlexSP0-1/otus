#include "primitivesfactory.h"
#include "registryprimitives.h"

RegistryPrimitives::RegistryPrimitives()
{
    primitiveObjects[PrimitiveType::POINT] = std::make_unique<PointPrimitiveFactory>();
    primitiveObjects[PrimitiveType::LINE] = std::make_unique<LinePrimitiveFactory>();
    primitiveObjects[PrimitiveType::CIRCLE] = std::make_unique<CirclePrimitiveFactory>();
}

void RegistryPrimitives::addPrimitiveType()
{}

void RegistryPrimitives::removePrimitiveType()
{}
