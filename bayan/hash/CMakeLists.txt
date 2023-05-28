set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(HEADERS
    ihash.h
    crc32hash.h
    md5hash.h
)

set(SOURCES
    crc32hash.cpp
    md5hash.cpp
)

add_library(hash ${HEADERS} ${SOURCES})
