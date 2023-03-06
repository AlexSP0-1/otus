#ifndef REGISTRYPRIMITIVES_H
#define REGISTRYPRIMITIVES_H

#include "basetypes.h"
#include "ipfactory.h"

#include <map>

class RegistryPrimitives
{
public:
    RegistryPrimitives();

    void addPrimitiveType();
    void removePrimitiveType();

public:
    std::map<PrimitiveType, std::unique_ptr<IPFactory>> primitiveObjects;
};

#endif // REGISTRYPRIMITIVES_H
