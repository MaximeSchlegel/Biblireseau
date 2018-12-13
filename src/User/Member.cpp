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

const string &Member::getName() const {
    return name;
}

const string &Member::getSurname() const {
    return surname;
}

const string &Member::getAddress() const {
    return address;
}

const string &Member::getPhone() const {
    return phone;
}

int Member::getRegistered() const {
    return registered;
}

int Member::getMaxBorrowing() const {
    return maxBorrowing;
}

ostream &operator<<(ostream &os, const Member &member) {
    os << "TYPE : Member" << endl;
    os << "id : " << member.getId() << endl;
    os << "Name : " << member.getName() << endl;
    os << "Surname : " << member.getSurname() << endl;
    os << "Address : " << member.getAddress() << endl;
    os << "Phone Number : " << member.getPhone() << endl;
    os << "Registered at : " << member.getRegistered() << endl;
    os << "Maximum Borrowing Capacity : " << member.getMaxBorrowing() << endl;
    os << "Book List : ";
    vector<int> bookList = member.getBook();
    if (not empty(bookList)) {
        for (int i = 0; i < bookList.size() - 1; i++) {
            os << bookList[i] << " ; ";
        }
        os << bookList[bookList.size() - 1] << endl;
    }
    else {
      os << "empty" << endl;
    }
    return os;
}