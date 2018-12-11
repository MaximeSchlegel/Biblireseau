cmake_minimum_required(VERSION 3.13)
project(Biblireseau)

set(CMAKE_CXX_STANDARD 17)

add_executable(Biblireseau src/main.cpp src/Entity.cpp src/Entity.h src/Library.cpp src/Library.h)