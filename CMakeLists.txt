cmake_minimum_required(VERSION 3.10)
project(BlogCode)

set(HEADERS
    src/Accounter.h
    src/CopyMover.h
    src/Indirectors.h
    )

set(SOURCES
    src/main.cpp
    src/Accounter.cpp
    src/CopyMover.cpp
    src/Indirectors.cpp
    ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)