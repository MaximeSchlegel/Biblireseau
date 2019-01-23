#ifndef BIBLIRESEAU_MEMBER_H
#define BIBLIRESEAU_MEMBER_H

#include "User.h"
#include "Library.h"
#include "../Book/Book.h"
#include <string>
#include <vector>
#include <ostream>
using namespace std;

class Member : public User {
private:
    static int created;
    int id;
    string name;
    string surname;
    string address;
    string phone;
    Library* registered;
    int maxBorrowing;
    vector<Book*> bookList;
public:
    Member();
    Member(string name, string surname="", string address="", string phone="", int maxBorrowing = 3);

    int getId() const;
    const string &getName() const;
    const string &getSurname() const;
    const string &getAddress() const;
    const string &getPhone() const;
    Library* getRegistered() const;
    int getMaxBorrowing() const;
    vector<Book*> const &getBook () const;
    int getCreated() const;
    string const getType() const;


    void setRegister (Library* library);

    friend ostream &operator<<(ostream &os, const Member &member);

    void addBook (Book* book);

    void borrowBook (int bookId);
    void returnBook (int bookId);
};


#endif //BIBLIRESEAU_USER_H
