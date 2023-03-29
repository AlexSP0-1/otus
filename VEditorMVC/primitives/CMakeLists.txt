set(SOURCES primitives.cpp
    primitivesfactory.cpp
    registryprimitives.cpp
)

set(HEADERS primitives.h
    igraphprimitive.h
    ipainter.h
    ipfactory.h
    primitivesfactory.h
    registryprimitives.h
    primitives.h
    basetypes.h
)

add_library(graph_primitives STATIC ${HEADERS} ${SOURCES})

