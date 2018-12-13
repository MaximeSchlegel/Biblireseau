#ifndef BIBLIRESEAU_NETWORK_H
#define BIBLIRESEAU_NETWORK_H


#include "../User/User.h"
#include "../Book/Book.h"
#include <map>
using namespace std;


class Network {
private:
    map<int,User> userList;
    map<int,Book> bookList;

public:
    Network();
    User getPUser(int id);
    Book getPBook (int id);
    void addUser (User newUser);
    void addBook (Book newBook);
};


#endif //BIBLIRESEAU_NETWORK_H
