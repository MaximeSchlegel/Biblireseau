#ifndef BIBLIRESEAU_BOOK_H
#define BIBLIRESEAU_BOOK_H


#include "../User/User.h"
#include "../User/Library.h"
#include <typeinfo>
#include<string>
#include <ostream>
using namespace std;


class User;
class Library;

class Book {
private:
    static int created;
    int id;
    string title;
    string author;
    string editor;
    string ISBN;
    string audience;
    Library * owner;
    User * location;

public:
    Book();
    Book(string name, string ISBN, string author="", string editor="", string audiance="");

    int getId() const;
    const string &getTitle() const;
    const string &getAuthor() const;
    const string &getEditor() const;
    const string &getISBN() const;
    const string &getAudience() const;
    Library* getOwner() const;
    User* getLocation() const;
    virtual string getType() const;

    void setOwner(Library* owner);
    void setLocation(User* newLocation);

    friend ostream &operator<<(ostream &os, const Book &book);

    bool isBorrowed ();
};


#endif //BIBLIRESEAU_BOOK_H
