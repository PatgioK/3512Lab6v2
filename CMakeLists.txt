cmake_minimum_required(VERSION 3.12)
project(3512Lab6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
add_executable(3512Lab6 main.cpp dictionary.cpp dictionary.hpp dictionary.cpp dictionary.hpp)