cmake_minimum_required(VERSION 4.0)
project(BlogCode LANGUAGES CXX)

enable_testing()
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS)

set(SOURCES
    Sources/Main.cpp
    ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME})

add_subdirectory(Sources/Model)
