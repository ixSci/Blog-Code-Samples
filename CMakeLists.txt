cmake_minimum_required(VERSION 3.0)
project(BlogCode)

set(HEADERS)

set(SOURCES src/main.cpp
    ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})