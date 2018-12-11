#include "Library.h"
using namespace std;

int Library::created = 0;

Library::Library(string name, string address) {
    if (name == "") {
        this->id = 0;
    }
    else {
        this->id = Library::created + 1;
        Library::created++;
    };
    this->name = name;
    this->adddress = address;
}
