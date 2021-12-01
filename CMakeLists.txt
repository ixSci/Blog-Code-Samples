cmake_minimum_required(VERSION 3.20)
project(BlogCode)

if(EXISTS "${CMAKE_SOURCE_DIR}/LocalConfig.cmake")
   include(LocalConfig.cmake)
else()
   message(FATAL_ERROR "LocalConfig.cmake file is absent. Please, copy and adjust the LocalConfig.cmake.template"
    " file from the \"assets\" subfolder to the root folder and remove .template suffix from it")
endif()

find_package(benchmark REQUIRED)

set(HEADERS)

set(SOURCES
    src/main.cpp
    ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} benchmark::benchmark)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)