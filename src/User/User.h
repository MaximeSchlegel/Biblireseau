#ifndef BIBLIRESEAU_USER_H
#define BIBLIRESEAU_USER_H


#include <vector>
#include <ostream>
using namespace std;

class Book;

class User {
public:
    virtual int getId() const = 0;
    virtual string const &getName() const = 0;
    virtual string const &getAddress() const = 0;
    virtual vector<Book*> const &getBook() const = 0;
};


#endif //BIBLIRESEAU_USER_H
