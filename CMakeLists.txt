cmake_minimum_required(VERSION 3.28)
project(BlogCode)

find_package(benchmark REQUIRED)

set(HEADERS)

set(SOURCES
    src/main.cpp
    ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} benchmark::benchmark)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)