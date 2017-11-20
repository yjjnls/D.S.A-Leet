cmake_minimum_required(VERSION 2.8.0)

set(PROJECT_NAME LeetCode-CXX)
project( ${PROJECT_NAME} )

set(CMAKE_CXX_STANDARD 11)
list(APPEND CMAKE_CXX_FLAGS "-std=c++11")

LINK_DIRECTORIES(/usr/lib)
# find_package (gtest REQUIRED)

INCLUDE_DIRECTORIES( ${PROJECT_DIRECTORY}../../src/cpp/ )  

FILE( GLOB_RECURSE SRC_FILES ${PROJECT_DIRECTORY}../../src/cpp/4. Median of Two Sorted Arrays.cpp
${PROJECT_DIRECTORY}/main.cpp
)

FILE( GLOB_RECURSE INC_FILES ${PROJECT_DIRECTORY}../../src/cpp/h* s)

add_executable( ${PROJECT_NAME} ${SRC_FILES} )
target_link_libraries( ${PROJECT_NAME} gtest gtest_main )
SET_TARGET_PROPERTIES( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_DIRECTORY}/bin)