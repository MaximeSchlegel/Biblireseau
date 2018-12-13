#ifndef BIBLIRESEAU_LIBRARY_H
#define BIBLIRESEAU_LIBRARY_H


#include "User.h"
#include <string>
#include <vector>
#include <ostream>

using namespace std;


class Library : public User {
private:
    string name;
    string address;

public:
    Library();
    Library(string name, string address="");

    string const &getName() const;
    string const &getAddress() const;

    friend ostream &operator<<(ostream &os, const Library &library);

    void showBook();
    void showBook(string category);
};


#endif //BIBLIRESEAU_LIBRARY_H
