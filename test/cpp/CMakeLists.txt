cmake_minimum_required(VERSION 2.8.0)

set(PROJECT_NAME LeetCode-CXX)
project( ${PROJECT_NAME} )

set(CMAKE_CXX_STANDARD 11)
list(APPEND CMAKE_CXX_FLAGS "-std=c++11")

# INCLUDE_DIRECTORIES( ${PROJECT_DIRECTORY}../gtest/build/include
# ${PROJECT_DIRECTORY}../../src/cpp 
# ) 
INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/gtest/build/include 
${CMAKE_CURRENT_SOURCE_DIR}/../../src/cpp 
)  

LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/gtest/build/lib)

# set( SRC_FILES main.cpp )
# list(APPEND SRC_FILES ../../src/cpp/4.Median of Two Sorted Arrays.cpp)
FILE( GLOB SRC_FILES 
${CMAKE_CURRENT_SOURCE_DIR}/../../src/cpp/4.*cpp 
main.cpp
)
# message("------------")
# message("${SRC_FILES}")
# message("${CMAKE_CURRENT_SOURCE_DIR}../../src/cpp/")
# message("------------")

# FILE( GLOB_RECURSE INC_FILES ${PROJECT_DIRECTORY}../../src/cpp/h* s)

add_executable( ${PROJECT_NAME} ${SRC_FILES} )
target_link_libraries( ${PROJECT_NAME} gtest gtest_main )
# SET_TARGET_PROPERTIES( ${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_DIRECTORY}/bin)