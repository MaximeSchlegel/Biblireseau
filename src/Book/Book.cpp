#include "Book.h"
#include "../User/Member.h"

using namespace std;

int Book::created = 0;

Book::Book(){
    this->id = 0;
    this->title = "";
    this->author = "";
    this->editor = "";
    this->ISBN = "";
    this->audience = "";
    this->owner = 0;
    this->location = 0;
}

Book::Book(string title, string author, string editor, string ISBN, string audiance) {
    Book::created++;
    this->id = Book::created;
    this->title = title;
    this->author = author;
    this->editor = editor;
    this->ISBN = ISBN;
    this->audience = audiance;
    this->owner = 0;
    this->location = 0;
}


int Book::getId() const {
    return id;
}

const string &Book::getTitle() const {
    return title;
}

const string &Book::getAuthor() const {
    return author;
}

const string &Book::getEditor() const {
    return editor;
}

const string &Book::getISBN() const {
    return ISBN;
}

const string &Book::getAudience() const {
    return audience;
}

Library *Book::getOwner() const {
    return owner;
}

User *Book::getLocation() const {
    return location;
}


void Book::setOwner(Library *owner) {
    if (this->owner) {
        cout << this->id << " already own" << endl;
        throw int(1) ;
    }
    else {
        this->owner = owner;
        this->location = owner;
    }
}

void Book::setLocation(User *newLocation) {
    if (this->owner->getId() == 0) {
        cout << this->id << " need an owner" << endl;
        throw int(2);
    }
    else {
        this->location = newLocation;
    }
}


ostream &operator<<(ostream &os, const Book &book) {
    os << "Type: Book" << endl;
    os << "id: " << book.id <<endl;
    os << "title: " << book.title << endl;
    os << "author: " << book.author << endl;
    os << "editor: " << book.editor << endl;
    os << "ISBN: " << book.ISBN << endl;
    os << "audience: " << book.audience << endl;
    os << "owner: " << book.owner->getName() << endl;
    if (book.location) {
        os << "location: " << book.location->getName() << endl;
    }
    else {
        os << "location: " << endl;
    }

    return os;
}


bool Book::borrowed() {
    if (dynamic_cast<Member *>(this->location)) {
        return true;
    }
    return false;
}