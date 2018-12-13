#include "Network.h"


Network::Network() {
    this->userList.push_back(User(false));
    this->bookList.push_back(Book());
}

User* Network::getPUser(int id) {
    return &userList[id];
}

Book* Network::getPBook(int id) {
    return &bookList[id];
}