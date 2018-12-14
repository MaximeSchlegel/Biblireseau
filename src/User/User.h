#ifndef BIBLIRESEAU_USER_H
#define BIBLIRESEAU_USER_H


#include <vector>
#include <ostream>
using namespace std;

class Book;

class User {
public:
    User();
    virtual int getId() const;
    virtual string const &getName() const;
    virtual string const &getAddress() const;
    virtual vector<Book*> const &getBook() const;
};


#endif //BIBLIRESEAU_USER_H
