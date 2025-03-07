cmake_minimum_required(VERSION 3.10)

# Define the project
project(ListExample)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Define the include directory for headers
include_directories(include)

set(SOURCE_FILES
    tests/test_list.cpp
)

add_executable(ListExample ${SOURCE_FILES})
