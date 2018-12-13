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
    int owner;
    int location;

public:
    Book();
    Book(string name, string author="", string editor="", string ISBN="", string audiance="",int creator=0);
};


#endif //BIBLIRESEAU_BOOK_H
