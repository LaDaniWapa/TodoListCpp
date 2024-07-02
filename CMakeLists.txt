cmake_minimum_required(VERSION 3.5)

project(TodoListCpp)

set(CMAKE_CXX_STANDARD 20)

# Indicates include directory
include_directories(include)
# Indicates all cpp files inside the source folder
file(GLOB SOURCES "src/*.cpp")
# Add cpp files to executable
add_executable(TodoListCpp ${SOURCES})