#ifndef BIBLIRESEAU_POETRY_H
#define BIBLIRESEAU_POETRY_H


#include "Book.h"
#include <string>
using namespace std;

class Poetry : public Book {
    private:
        bool verse;
        bool prose ;

    public:
        Poetry();
        Poetry(string name, string ISBN, string author="", string editor="", string audiance="", bool verse=false, bool prose=false);

        bool isVerse() const;
        bool isProse() const;
        string getType() const;
};


#endif //BIBLIRESEAU_POETRY_H
