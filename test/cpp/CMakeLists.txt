cmake_minimum_required(VERSION 2.8.0)

set(PROJECT_NAME LeetCode-CXX)
project( ${PROJECT_NAME} )

# In CMakeModules I include code coverage for c++
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMakeModules)


if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    setup_target_for_coverage(${PROJECT_NAME}_coverage tests coverage)
endif()


# C++ compile flags
# -std=c++11 -> for c++ standarts
# -Wall for WARNING
# -pedantic -> for warning between c and c++
# -pthread for portability
# -g -O0 -fprofile-arcs -ftest-coverage for code coverage
if(NOT CMAKE_VERSION VERSION_LESS 3.1)
set(CMAKE_CXX_STANDARD 11)
else()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -pthread -g -O0 -fprofile-arcs -ftest-coverage")

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
${CMAKE_CURRENT_SOURCE_DIR}/../../src/cpp/*cpp 
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