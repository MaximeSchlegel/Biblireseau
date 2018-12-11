//
// Created by Altar on 11/12/2018.
//

#include "Library.h"

int Library::created = 0;

Library::Library(string name, string address, vector<Book> bookList) {
    this->id = Library::created + 1;
    this->name = name;
    this->adddress = address;
    this->bookList = bookList;
    Library::created++;
}
