//
// Created by mimmo on 11/12/2018.
//

#include "Comic.h"

Comic::Comic()
      :Book(){
    this->cartoonist = "";
}

Comic::Comic(string name, string ISBN, string author, string editor, string audiance, string cartoonist)
      :Book(name,ISBN, author, editor, audiance) {
    this->cartoonist = cartoonist;
}

const string &Comic::getCartoonist() const {
    return cartoonist;
}
