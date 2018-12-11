#ifndef BIBLIRESEAU_USER_H
#define BIBLIRESEAU_USER_H

#include "Entity.h"
#include "Library.h"
#include "../Book/Book.h"
#include <string>
#include <vector>
using namespace std;

class User : public Entity {
private:
    static int created ;
    int id ;
    string name ;
    string surname ;
    string address ;
    string phone ;
    Library registered ;
    int maxBorrowing ;
    vector<Book> bookList ;

public:
    User(string name="", string surname="", string address="", string phone="");
};


#endif //BIBLIRESEAU_USER_H
