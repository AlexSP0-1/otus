set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(HEADERS
    bulkmodel.h
    observable.h
    observer.h
    imodeliterator.h
    modeliterator.h
    icommandmodel.h
)

set(SOURCES
    bulkmodel.cpp
    observable.cpp
)

add_library(model STATIC ${HEADERS} ${SOURCES})
