#include "Network.h"


Network::Network() {
    this->libraryList.emplace(0,Library());
    this->memberList.emplace(0,Member());
    this->bookList.emplace(0,Book());
}

/*User Network::getPUser(int id) {
    return userList[id];
}*/

/*
Book Network::getPBook(int id) {
    return bookList[id];
}*/
