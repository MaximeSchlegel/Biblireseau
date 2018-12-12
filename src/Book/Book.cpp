#include "Book.h"
#include "../Entity/Entity.h"
#include "../Entity/Library.h"
using namespace std;

int Book::created = 0;

Book::Book(string title, string author, string editor, string ISBN, string audiance) {
    if (empty(title)) {
        this->id = 0;
    }
    else {
        this->id = Book::created + 1;
        Book::created++;
    };
    this->title = title;
    this->author = author;
    this->editor = editor;
    this->ISBN = ISBN;
    this->audience = audiance;
    Library l = Library();
    this->owner = &l;
    this->owner = &l;
}