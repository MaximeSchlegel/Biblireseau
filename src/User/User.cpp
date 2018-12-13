#include "User.h"


int User::created = 0;

User::User() {
    id = 0 ;
}

User::User(bool isEmpty) {
    if (isEmpty) {
        User::created++;
        id = User::created;
    }
    else {
        id = 0;
    }
}

int User::getId() const {
    return id;
}

vector<int> const & User::getBook() const {
    return this->bookList;
}

std::ostream &operator<<(std::ostream &os, const User &user) {
    os << "Type: user" << endl;
    os << "id: " << user.getId() << endl;
    os << "bookList: ";
    vector<int> bookList = user.getBook();
    if (not empty(bookList)) {
        for (int i=0; i<bookList.size()-1; i++) {
            os << bookList[i] << " ; ";
        }
        os << bookList[bookList.size()-1] << endl;
    }
    else {
        os << "empty" << endl;
    }
    return os;
}
