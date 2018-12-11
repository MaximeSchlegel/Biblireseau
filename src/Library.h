//
// Created by Altar on 11/12/2018.
//

#ifndef BIBLIRESEAU_LIBRARY_H
#define BIBLIRESEAU_LIBRARY_H

#include "Entity.h"
using namespace std;

class Library : public Entity {
private:
    int id;
    static int created;
};


#endif //BIBLIRESEAU_LIBRARY_H
