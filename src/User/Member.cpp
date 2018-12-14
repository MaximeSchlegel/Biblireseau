#include "Member.h"
using namespace std;

int Member::created = 0;

Member::Member() {
    this->id = 0;
    this->name = "";
    this->surname = "";
    this->address = "";
    this->phone = "";
    this->maxBorrowing = 0;
//    this->registered = NULL;
}

Member::Member(string name, string surname, string address, string phone, int maxBorrowing) {
    if (empty(name)) {
        this->id = 0;
    }
    else {
        Member::created++;
        this->id = Member::created;
    }
    this->name = name;
    this->surname = surname;
    this->address = address;
    this->phone = phone;
    this->maxBorrowing = maxBorrowing;
    this->registered = new Library;
}


int Member::getId() const {
    return id;
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

Library *Member::getRegistered() const {
    return registered;
}

int Member::getMaxBorrowing() const {
    return maxBorrowing;
}

vector<Book *> const &Member::getBook() const {
    return bookList;
}


void Member::setRegister(Library *library) {
    if (this->registered->getId() != 0) {
        cout << this->id << " has already sign in" << endl;
        throw int (4);
    }
    else {
        this->registered = library;
    }
}


ostream &operator<<(ostream &os, const Member &member) {
    os << "Type: Member" << endl;
    os << "id: " << member.getId() << endl;
    os << "Name: " << member.getName() << endl;
    os << "Surname: " << member.getSurname() << endl;
    os << "Address: " << member.getAddress() << endl;
    os << "Phone Number: " << member.getPhone() << endl;
    os << "Registered at: ";
    os << member.getRegistered()->getName();
    os << endl << "Maximum Borrowing Capacity: " << member.getMaxBorrowing() << endl;
    os << "Book List: ";
    vector<Book*> bookList = member.getBook();
    if (not empty(bookList)) {
        for (int i = 0; i < bookList.size() - 1; i++) {
            os << bookList[i]->getTitle() << " ; ";
        }
        os << bookList[bookList.size() - 1]->getTitle() << endl;
    }
    return os;
}


void Member::addBook(Book *book) {
    try {
        book->setLocation(this);
        this->bookList.push_back(book);
    }
    catch (int i) {
        throw i;
    }
}

void Member::borrow(int bookId) {
    if (this->registered->getId() == 0) {
        cout << this->id << " needs to register" << endl;
        throw int(5);
    }
    if (this->bookList.size() < this->maxBorrowing) {
        try {
            pair<bool, Book *> answer = this->registered->haveBook(bookId);
            if (answer.first) {
                this->registered->removeBook(answer.second);
                this->addBook(answer.second);
            }
        }
        catch (int i) {
            throw i;
        }
    }
    else {
        cout << this->id << " has reach his borrowing capacity limit" << endl;
        throw int(6);
    }
}
