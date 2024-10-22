project(PCH)

set(PCH_HEADERS
    Essentials.h)

set(PCH_SOURCES
    PCH.cpp
    ${PCH_HEADERS})

add_library(${PROJECT_NAME}.Essentials ${PCH_SOURCES})
target_precompile_headers(${PROJECT_NAME}.Essentials PRIVATE Essentials.h)
