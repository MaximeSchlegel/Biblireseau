//
// Created by Altar on 11/12/2018.
//

#ifndef BIBLIRESEAU_LIBRARY_H
#define BIBLIRESEAU_LIBRARY_H

#include "Entity.h"
#include "User.h"
#include <string>
#include <vector>
using namespace std;

class Library : public Entity {
private:
    static int created;
    int id;
    string nom;
    string adddress;
    vector<Book> bookList;

};


#endif //BIBLIRESEAU_LIBRARY_H
