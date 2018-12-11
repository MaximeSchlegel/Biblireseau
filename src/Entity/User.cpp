#include "User.h"
using namespace std;

int User::created = 0;

User::User(string name, string surname, string address, string phone) {
    if (name == "") {
        this->id = 0;
    }
    else {
        this->id = User::created +1;
        User::created++;
    };
    this->name = name;
    this->surname = surname;
    this->address = address;
    this->phone = phone;
    this->maxBorrowing = 3;
    this->registered = Library();
}
