set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(HEADERS
    filelogger.h
    consolelogger.h
)

set(SOURCES
    filelogger.cpp
    consolelogger.cpp
)

add_library(loggers STATIC ${HEADERS} ${SOURCES})
target_link_libraries(handler model)
