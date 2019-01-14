//
// Created by mimmo on 11/12/2018.
//

#include "Album.h"

Album::Album()
      :Book() {
    this->picture = false;
    this->drawing = false;
}

Album::Album(string name, string ISBN, string author, string editor, string audiance, bool picture, bool drawing)
      :Book(name, ISBN, author, editor, audiance) {
    this->picture = picture;
    this->drawing = drawing;
}

bool Album::isPicture() const {
    return picture;
}

bool Album::isDrawing() const {
    return drawing;
}
