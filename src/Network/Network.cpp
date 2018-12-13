#include "Network.h"


Network::Network() {
    this->userList.emplace(0,User(false));
    this->bookList.emplace(0,Book());
}

User Network::getPUser(int id) {
    return userList[id];
}

Book Network::getPBook(int id) {
    return bookList[id];
}