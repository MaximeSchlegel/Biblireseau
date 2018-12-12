#include "User.h"
#include "Library.h"
#include "../Book/Book.h"
using namespace std;

int User::created = 0;

User::User(string name, string surname, string address, string phone, int maxBorrowing) {
    if (empty(name)) {
        this->id = 0;
    }
    else {
        this->id = User::created + 1;
        User::created++;
    };
    this->name = name;
    this->surname = surname;
    this->address = address;
    this->phone = phone;
    this->maxBorrowing = maxBorrowing;
    Library L = Library();
    this->registered = &L;
}
