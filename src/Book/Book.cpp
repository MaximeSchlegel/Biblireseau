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