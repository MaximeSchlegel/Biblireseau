//
// Created by mimmo on 11/12/2018.
//

#ifndef BIBLIRESEAU_ALBUM_H
#define BIBLIRESEAU_ALBUM_H


#include "Book.h"

class Album : public Book {
    private:
        bool picture ;
        bool drawing ;

    public:
        Album();
        Album(string name, string ISBN, string author="", string editor="", string audiance="", bool picture=false, bool drawing=false);


        bool isPicture() const;
        bool isDrawing() const;
        string getType() const;

};


#endif //BIBLIRESEAU_ALBUM_H
