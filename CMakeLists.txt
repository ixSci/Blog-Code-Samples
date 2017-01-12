cmake_minimum_required(VERSION 3.0)
project(BlogCode)

set(HEADERS src/CheckConcept.h
        src/HasSortFunction.h)

set(SOURCES src/main.cpp
    ${HEADERS})

add_compile_options(-std=c++1z)

add_executable(${PROJECT_NAME} ${SOURCES})

