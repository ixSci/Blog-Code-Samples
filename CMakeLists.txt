cmake_minimum_required(VERSION 4.0)
project(TrickyPrint LANGUAGES CXX)

enable_testing()
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(HEADERS)

set(SOURCES
    Sources/Main.cpp
    ${HEADERS})

if (MINGW AND ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    # stdc++exp is currently required for std::print
    list(APPEND ADDITIONAL_LIBS stdc++exp)
endif ()

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${ADDITIONAL_LIBS})

add_subdirectory(Sources/Model)
