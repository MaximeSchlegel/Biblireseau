#include "Book.h"
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

Book::Book(string title, string author, string editor, string ISBN, string audiance, int creator) {
    Book::created++;
    this->id = Book::created;
    this->title = title;
    this->author = author;
    this->editor = editor;
    this->ISBN = ISBN;
    this->audience = audiance;
    this->owner = creator;
    this->location = creator;
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

int Book::getOwner() const {
    return owner;
}

int Book::getLocation() const {
    return location;
}

ostream &operator<<(ostream &os, const Book &book) {
    os << "Type: Book" << endl;
    os << "id: " << book.id <<endl;
    os << "title: " << book.title << endl;
    os << "author: " << book.author << endl;
    os << "editor: " << book.editor << endl;
    os << "ISBN: " << book.ISBN << endl;
    os << "audience: " << book.audience << endl;
    os << "owner: " << book.owner << endl;
    os << "location: " << book.location << endl;
    return os;
}