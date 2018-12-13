#include "Library.h"
using namespace std;


Library::Library()
        :User(false) {
    this->name ="";
    this->address = "";

}


Library::Library(string name, string address)
        :User(true) {
    this->name = name;
    this->address = address;
}

string const &Library::getName() const {
    return name;
}

string const &Library::getAddress() const {
    return address;
}

ostream &operator<<(ostream &os,  const Library &library) {
    os << "TYPE : Library" << endl;
    os << "id : " << library.getId() << endl;
    os << "name: " << library.getName() << endl;
    os <<  "address: " << library.getAddress() << endl;
    os << "Book List : ";
    vector<int> bookList = library.getBook();
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
