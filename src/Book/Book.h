#ifndef BIBLIRESEAU_BOOK_H
#define BIBLIRESEAU_BOOK_H

#include<string>
using namespace std;

class Library;
class Entity;

class Book {
private:
    static int created;
    int id;
    string title;
    string author;
    string editor;
    string ISBN;
    string audience;
    Library* owner;
    Entity* location;

public:
    Book(string name="", string author="", string editor="", string ISBN="", string audiance="");
};


#endif //BIBLIRESEAU_BOOK_H
