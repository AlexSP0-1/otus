set(SOURCES primitives.cpp)

set(HEADERS primitives.h
    igraphprimitive.h
    ipainter.h
    primitives.h
    basetypes.h
)

add_library(graph_primitives STATIC ${HEADERS} ${SOURCES})

