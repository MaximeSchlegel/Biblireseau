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

string Library::getName() {
    return name;
}

string Library::getAddress() {
    return address;
}
