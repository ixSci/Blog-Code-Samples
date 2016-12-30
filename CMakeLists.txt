cmake_minimum_required(VERSION 3.0)
project(BlogCode)

set(HEADERS src/HasFunction.h
    src/EnableIf.h)

set(SOURCES src/main.cpp
    ${HEADERS})
    
add_executable(${PROJECT_NAME} ${SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 98)