#ifndef BIBLIRESEAU_LIBRARY_H
#define BIBLIRESEAU_LIBRARY_H

#include "Entity.h"
#include "../Book/Book.h"
#include <string>
#include <vector>
using namespace std;

class Library : public Entity {
private:
    static int created;
    int id;
    string name;
    string adddress;
    vector<Book> bookList;

public:
    Library(string name="", string address="");
};

#endif //BIBLIRESEAU_LIBRARY_H
