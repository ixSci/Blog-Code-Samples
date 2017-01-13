cmake_minimum_required(VERSION 3.0)
project(BlogCode)

find_package(boost REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})

set(HEADERS)

set(SOURCES src/main.cpp
    ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})

