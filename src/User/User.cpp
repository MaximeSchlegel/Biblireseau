#include "User.h"


int User::created = 0;

User::User(bool isEmpty) {
    if (isEmpty) {
        User::created++;
        this->id = User::created;
    }
    else {
        this->id = 0;
    }
}

int User::getId() {
    return id;
}