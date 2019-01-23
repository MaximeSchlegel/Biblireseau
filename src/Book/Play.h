#ifndef BIBLIRESEAU_PLAY_H
#define BIBLIRESEAU_PLAY_H


#include "Book.h"

class Play : public Book {
    private:
        int century ;

    public:
        Play();
        Play(string name, string ISBN, string author="", string editor="", string audiance="", int century=0);
        int getCentury() const;
        string getType() const;

};


#endif //BIBLIRESEAU_PLAY_H
