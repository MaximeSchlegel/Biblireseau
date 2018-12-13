#ifndef BIBLIRESEAU_NETWORK_H
#define BIBLIRESEAU_NETWORK_H


#include "../User/User.h"
#include "../Book/Book.h"
#include <vector>
using namespace std;


class Network {
private:
    vector<User> userList;
    vector<Book> bookList;

public:
    Network();
    User* getPUser(int id);
    Book* getPBook (int id);
    void addUser (User newUser);
    void addBook (Book book);
};


#endif //BIBLIRESEAU_NETWORK_H
