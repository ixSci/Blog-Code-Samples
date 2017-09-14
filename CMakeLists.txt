cmake_minimum_required(VERSION 3.8)
project(BlogCode)

set(HEADERS src/Sort.h
        src/MixStaticWithDynamic.h
        src/ReturnHeadache.h
        src/StaticIf.h)

set(SOURCES src/main.cpp
        ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)
