#ifndef BIBLIRESEAU_LIBRARY_H
#define BIBLIRESEAU_LIBRARY_H


#include "User.h"
#include <string>
#include <vector>
using namespace std;


class Library : public User {
private:
    string name;
    string address;

public:
    Library();
    Library(string name, string address="");
    string getName();
    string getAddress();
};


#endif //BIBLIRESEAU_LIBRARY_H
