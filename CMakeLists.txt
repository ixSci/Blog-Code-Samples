cmake_minimum_required(VERSION 3.28)
project(BlogCode)

include(Instruments/Utils.cmake)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if(MSVC)
    set(FASTER_LINK /Zi /Zf)
    set(EMPLOY_PARALLEL /MP "$<$<CONFIG:Debug>:${FASTER_LINK}>")
    add_compile_options("${EMPLOY_PARALLEL}" /utf-8)
endif()

set(HEADERS)

set(SOURCES
    src/main.cpp
    ${HEADERS})

add_subdirectory(Instruments/PCH)
add_subdirectory(src/ComplexLibrary)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ComplexLibrary)
set_precompiled_headers(Essentials)