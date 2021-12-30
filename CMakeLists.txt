cmake_minimum_required(VERSION 3.20)
project(BlogCode)

set(HEADERS
    src/Variant.h)

set(SOURCES
    src/Variant.cpp
    src/main.cpp
    ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD_REQUIRED ON
    CXX_STANDARD 17
    CXX_EXTENSIONS NO)