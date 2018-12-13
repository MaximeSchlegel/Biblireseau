#ifndef BIBLIRESEAU_MEMBER_H
#define BIBLIRESEAU_MEMBER_H

#include "User.h"
#include <string>
#include <vector>
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
};


#endif //BIBLIRESEAU_USER_H
