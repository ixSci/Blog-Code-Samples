cmake_minimum_required(VERSION 4.0)
project(BlogCode LANGUAGES CXX)

set(HEADERS)

set(SOURCES
    Sources/Main.cpp
    ${HEADERS})

if(MINGW AND ${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    # stdc++exp is currently required for std::print
    list(APPEND ADDITIONAL_LIBS stdc++exp)
endif()

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${ADDITIONAL_LIBS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 23)
