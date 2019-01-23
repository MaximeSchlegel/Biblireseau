//
// Created by mimmo on 11/12/2018.
//

#ifndef BIBLIRESEAU_COMIC_H
#define BIBLIRESEAU_COMIC_H


#include "Book.h"

class Comic : public Book {
    private:
        string cartoonist;

    public:
        Comic();
        Comic(string name, string ISBN, string author="", string editor="", string audiance="", string cartoonist="");
        const string &getCartoonist() const;
        string getType() const;
};


#endif //BIBLIRESEAU_COMIC_H
