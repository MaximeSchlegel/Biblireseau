cmake_minimum_required(VERSION 3.13)
project(Biblireseau)

set(CMAKE_CXX_STANDARD 17)

add_executable(Biblireseau src/main.cpp src/User.cpp src/User.h src/Entity.cpp src/Entity.h src/Library.cpp src/Library.h src/Book.cpp src/Book.h src/Album.cpp src/Album.h src/Comic.cpp src/Comic.h src/Play.cpp src/Play.h src/Poetry.cpp src/Poetry.h src/Novel.cpp src/Novel.h)