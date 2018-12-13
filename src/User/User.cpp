#include "User.h"


int User::created = 0;

User::User(bool isEmpty) {
    if (isEmpty) {
        this->id = 0;
    }
    else {
        User::created++;
        this->id = User::created;
    }
}