#ifndef BIBLIRESEAU_BOOK_H
#define BIBLIRESEAU_BOOK_H


#include<string>
#include <ostream>
using namespace std;


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

    int getId() const;
    const string &getTitle() const;
    const string &getAuthor() const;
    const string &getEditor() const;
    const string &getISBN() const;
    const string &getAudience() const;
    int getOwner() const;
    int getLocation() const;

    friend ostream &operator<<(ostream &os, const Book &book);
};


#endif //BIBLIRESEAU_BOOK_H
