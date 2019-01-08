cmake_minimum_required(VERSION 3.13)

set(TARGET_NAME Biblireseau)

project(TARGET_NAME)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/main.cpp
        src/User/User.cpp
        src/User/User.h
        src/User/Library.cpp
        src/User/Library.h
        src/User/Member.cpp
        src/User/Member.h
        src/Book/Book.cpp
        src/Book/Book.h
        src/Book/Album.cpp
        src/Book/Album.h
        src/Book/Comic.cpp
        src/Book/Comic.h
        src/Book/Play.cpp
        src/Book/Play.h
        src/Book/Poetry.cpp
        src/Book/Poetry.h
        src/Book/Novel.cpp
        src/Book/Novel.h
        src/Network/Network.cpp
        src/Network/Network.h)
add_executable(Biblireseau ${SOURCE_FILES})
