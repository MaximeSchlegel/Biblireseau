#include "Member.h"
#include "Library.h"
#include "../Book/Book.h"
using namespace std;


Member::Member()
       :User(false) {
    this->name = "";
    this->surname = "";
    this->address = "";
    this->phone = "";
    this->maxBorrowing = 0;
    this->registered = 0;
}

Member::Member(string name, string surname, string address, string phone, int signIn, int maxBorrowing)
       : User(true) {
    this->name = name;
    this->surname = surname;
    this->address = address;
    this->phone = phone;
    this->maxBorrowing = maxBorrowing;
    this->registered = signIn;
}
