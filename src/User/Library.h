#ifndef BIBLIRESEAU_LIBRARY_H
#define BIBLIRESEAU_LIBRARY_H


#include "User.h"
#include "../Book/Book.h"
#include <string>
#include <vector>
#include <ostream>
#include <iostream>
#include <typeinfo>
using namespace std;


class Library : public User {
private:
    static int created;
    int id;
    string name;
    string address;
    vector<Book*> bookList;

public:
    Library();
    Library(string name, string address="");

    int getId() const;
    string const &getName() const;
    string const &getAddress() const;
    vector<Book*> const &getBook() const;
    int getCreated() const;
    string const getType() const;

    friend ostream &operator<<(ostream &os, const Library &library);
    void showBook();
    void showBook(string category);

    void addBook (Book* book);
    void removeBook (Book* book);
    pair<bool, Book*> haveBook (int bookId);
    pair<bool, Book*> haveBook (string ISBN);

    void buyBook (Book* book);
    void trashBook (int bookId);
    void askBook (string ISBN, Library* library);
    void returnBook(int bookId);
    void returnBooks ();
};


#endif //BIBLIRESEAU_LIBRARY_H
