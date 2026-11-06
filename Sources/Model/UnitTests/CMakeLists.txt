set(PARENT_PROJECT ${PROJECT_NAME})
project(${PARENT_PROJECT}.UnitTests LANGUAGES CXX)

find_package(GTest 1.8)
include(GoogleTest)

set(MODEL_UT_SOURCES VertexTest.cpp)

add_executable(${PROJECT_NAME} ${MODEL_UT_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE GTest::gmock_main ${PARENT_PROJECT})
target_include_directories(${PROJECT_NAME} PRIVATE ..)

gtest_discover_tests(${PROJECT_NAME})
