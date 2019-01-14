//
// Created by mimmo on 11/12/2018.
//

#include "Play.h"

Play::Play()
     :Book() {
    this->century = 0;
}

Play::Play(string name, string ISBN, string author, string editor, string audiance, int century)
     :Book(name, ISBN, author, editor, audiance){
    this->century = century;
}

int Play::getCentury() const {
    return this->century;
}
