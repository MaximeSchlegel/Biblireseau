//
// Created by mimmo on 11/12/2018.
//

#ifndef BIBLIRESEAU_USER_H
#define BIBLIRESEAU_USER_H
#include<string>
#include "Entity.h"
#include "Library.h"
#include "Book.h"
#include <vector>

using namespace std;

class User : public Entity {
private:
    static int created ;
    int id ;
    string name ;
    string surname ;
    string address ;
    string telephone ;
    Library registered ;
    int maxBorrowing ;
    std::vector<Book> bookList ;
};


#endif //BIBLIRESEAU_USER_H
