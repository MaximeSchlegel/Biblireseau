//
// Created by mimmo on 11/12/2018.
//

#ifndef BIBLIRESEAU_NOVEL_H
#define BIBLIRESEAU_NOVEL_H


#include <vector>
#include "Book.h"

class Novel : public Book {
private:
    static std::vector<string> listGenre ;
    string genre ;
};


#endif //BIBLIRESEAU_NOVEL_H
