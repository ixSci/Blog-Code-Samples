cmake_minimum_required(VERSION 4.0)
project(TrickyPrint LANGUAGES CXX)

enable_testing()
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(force_include TARGET_NAME INCLUDE_PATH)
    if (MSVC)
        set(_options "/FI${INCLUDE_PATH}")
    else ()
        set(_options "SHELL:-include ${INCLUDE_PATH}")
    endif ()
    target_compile_options(${TARGET_NAME} PRIVATE ${_options})
endfunction()

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
