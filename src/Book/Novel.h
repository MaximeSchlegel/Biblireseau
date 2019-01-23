//
// Created by mimmo on 11/12/2018.
//

#ifndef BIBLIRESEAU_NOVEL_H
#define BIBLIRESEAU_NOVEL_H


#include <vector>
#include "Book.h"

class Novel : public Book {
    private:
        string genre;

    public:
        Novel();
        Novel(string name, string ISBN, string author="", string editor="", string audiance="", string genre="");
        static const vector<string> &getValidGenre();
        const string &getGenre() const;
        string getType() const;
};


#endif //BIBLIRESEAU_NOVEL_H
