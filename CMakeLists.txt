cmake_minimum_required(VERSION 4.0)
project(BlogCode)

set(HEADERS)

set(SOURCES
    src/main.cpp
    ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)