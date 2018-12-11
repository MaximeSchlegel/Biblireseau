cmake_minimum_required(VERSION 3.13)
project(Biblireseau)

set(CMAKE_CXX_STANDARD 17)

add_executable(Biblireseau src/main.cpp src/Entity/Entity.cpp src/Entity/Entity.h src/Entity/Library.cpp src/Entity/Library.h src/Entity/User.cpp src/Entity/User.h src/Book/Book.cpp src/Book/Book.h src/Book/Album.cpp src/Book/Album.h src/Book/Comic.cpp src/Book/Comic.h src/Book/Play.cpp src/Book/Play.h src/Book/Poetry.cpp src/Book/Poetry.h src/Book/Novel.cpp src/Book/Novel.h)