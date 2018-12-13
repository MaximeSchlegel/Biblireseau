#ifndef BIBLIRESEAU_MEMBER_H
#define BIBLIRESEAU_MEMBER_H

#include "User.h"
#include <string>
#include <vector>
#include <ostream>
using namespace std;


class Member : public User {
private:
    string name;
    string surname;
    string address;
    string phone;
    int registered;
    int maxBorrowing;

public:
    Member();
    Member(string name, string surname="", string address="", string phone="", int signIn=0, int maxBorrowing = 3);

    const string &getName() const;
    const string &getSurname() const;
    const string &getAddress() const;
    const string &getPhone() const;
    int getRegistered() const;
    int getMaxBorrowing() const;

    friend ostream &operator<<(ostream &os, const Member &member);
};


#endif //BIBLIRESEAU_USER_H
