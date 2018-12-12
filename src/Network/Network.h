//
// Created by Maxime on 12/12/2018.
//

#ifndef BIBLIRESEAU_NETWORK_H
#define BIBLIRESEAU_NETWORK_H


#include "../Entity/Entity.h"
#include "../Entity/Library.h"
#include "../Entity/User.h"
#include "../Book/Book.h"
#include <vector>
using namespace std;


class Network {
public:
    Network();
    vector<Library> libraryList;
    vector<User> userList;
    vector<Book> bookList;

};
#endif //BIBLIRESEAU_NETWORK_H
