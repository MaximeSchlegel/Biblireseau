#ifndef BIBLIRESEAU_BOOK_H
#define BIBLIRESEAU_BOOK_H

#include "../Entity/Entity.h"
#include<string>
using namespace std;


class Book {
private:
    static int created;
    int id;
    string title;
    string author;
    string editor;
    string ISBN;
    string audience;
    Entity owner;
    Entity location;

};


#endif //BIBLIRESEAU_BOOK_H
