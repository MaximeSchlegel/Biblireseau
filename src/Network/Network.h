#ifndef BIBLIRESEAU_NETWORK_H
#define BIBLIRESEAU_NETWORK_H


#include "../User/User.h"
#include "../User/Library.h"
#include "../User/Member.h"
#include "../Book/Book.h"
#include <map>
using namespace std;


class Network {
private:
    map<int,Library> libraryList;
    map<int,Member> memberList;
    map<int,Book> bookList;

public:
    Network();
//    User getPUser(int id);
//    Book getPBook (int id);
//    void addUser (User newUser);
//    void addBook (Book newBook);
};


#endif //BIBLIRESEAU_NETWORK_H
