#include "Library.h"
using namespace std;

int Library::created = 0;

Library::Library() {
    this->id = 0;
    this->name ="";
    this->address = "";
}

Library::Library(string name, string address) {
    if (empty(name)) {
        this->id = 0;
    } else {
        Library::created++;
        this->id = Library::created;
    }
    this->name = name;
    this->address = address;
}


int Library::getId() const {
    return id;
}

string const &Library::getName() const {
    return name;
}

string const &Library::getAddress() const {
    return address;
}

vector<Book*> const & Library::getBook() const {
    return bookList;
}


ostream &operator<<(ostream &os,  const Library &library) {
    os << "Type: Library" << endl;
    os << "id: " << library.getId() << endl;
    os << "name: " << library.getName() << endl;
    os <<  "address: " << library.getAddress() << endl;
    os << "Book List: ";
    vector<Book*> bookList = library.getBook();
    if (not empty(bookList)) {
        for (int i=0; i<bookList.size()-1; i++) {
            os << bookList[i]->getTitle() << " ; ";
        }
        os << bookList[bookList.size()-1]->getTitle() << endl;
    }
    return os;
}

void Library::showBook() {
    cout << "All books from " << this->getName() << endl;
    if (not empty(this->bookList)) {
        for (int i = 0; i < this->bookList.size(); i++) {
            cout << "    - " << this->bookList[i]->getTitle() << endl;
        }
    }
}

void Library::showBook(string category) {
    cout << category << " from " << this->getName() << endl;
    if (not empty(this->bookList)) {
        for (int i = 0; i < this->bookList.size(); i++) {
            if (typeid(this->bookList[i]).name() == category) {
                cout << "    - " << this->bookList[i]->getTitle() << endl;
            }
        }
    }
}


void Library::addBook(Book* book) {
    try {
        book->setLocation(this);
        this->bookList.push_back(book);
    } catch (int i) {
        throw i;
    }
}

void Library::removeBook(Book *book) {
    for (int i=0; i<this->bookList.size(); i++) {
        if (this->bookList[i] = book) {
            this->bookList.erase(this->bookList.begin() + i);
            return;
        }
    }
    cout << book->getId() <<  "ins't in this Library" << endl;
    throw int(7);
}


pair<bool, Book*> Library::haveBook(int bookId) {
    for (int i=0; i < this->bookList.size(); i++) {
        if (this->bookList[i]->getId() == bookId) {
            return pair<bool, Book*>(true, this->bookList[i]);
        }
    }
    return pair<bool, Book*>(false, new Book);
}

pair<bool, Book*> Library::haveBook(string ISBN) {
    for (int i=0; i < this->bookList.size(); i++) {
        if (this->bookList[i]->getISBN() == ISBN) {
            return pair<bool, Book*>(true, this->bookList[i]);
        }
    }
    return pair<bool, Book*>(false, new Book);
}

void Library::buyBook(Book* book) {
    try {
        book->setOwner(this);
        this->addBook(book);
    } catch (int i) {
        throw i;
    }
}

void Library::trashBook(int bookId) {
    try {
        pair<bool, Book*> answer = this->haveBook(bookId);
        if (answer.first) {
            this->removeBook(answer.second);
        } else {
            cout << bookId <<  "ins't in this Library" << endl;
            throw int(7);
        }
    }
    catch (int i) {
        throw i;
    }
}

void Library::askBook(string ISBN, Library* library) {
    if (this == library) {
        cout << "Can't ask yourselve for book" << endl;
        throw (8);
    }
    try {
        pair<bool, Book*> answer = library->haveBook(ISBN);
        if (answer.first) {
            library->removeBook(answer.second);
            this->addBook(answer.second);
        } else {
            cout << this->id << " doesn't have the book " << ISBN << endl;
            throw int(9);
        }
    } catch (int i) {
        throw i;
    }
}

void Library::returnBooks() {
    for (int i=0; i<this->bookList.size(); i++) {
        if (this->bookList[i]->getOwner()->getId() != this->id) {
            try {
                this->bookList[i]->getOwner()->addBook(this->bookList[i]);
                this->removeBook(this->bookList[i]);
            } catch (int i) {
                throw i;
            }
        }
    }
}