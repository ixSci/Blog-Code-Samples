project(Model LANGUAGES CXX)

set(MODEL_HEADERS
        INode.h
        Vertex.h
        INodeProcessor.h
)
set(MODEL_SOURCES
        Vertex.cpp
        ${MODEL_HEADERS})

add_library(${PROJECT_NAME} ${MODEL_SOURCES})

add_subdirectory(UnitTests)
