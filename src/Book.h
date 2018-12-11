//
// Created by mimmo on 11/12/2018.
//

#ifndef BIBLIRESEAU_BOOK_H
#define BIBLIRESEAU_BOOK_H
#include<string>
#include "Library.h"

using namespace std;


class Book {
private:
    static int created ;
    int id ;
    string title ;
    string author ;
    string editor ;
    string ISBN ;
    string audience ;
    Library owner ;
    Entity location ;

};


#endif //BIBLIRESEAU_BOOK_H
