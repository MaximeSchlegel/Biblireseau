#ifndef BIBLIRESEAU_LIBRARY_H
#define BIBLIRESEAU_LIBRARY_H

#include "Entity.h"
#include <string>
#include <vector>
using namespace std;

class Book;

class Library : public Entity {
private:
    static int created;
    int id;
    string name;
    string adddress;
    vector<Book *> bookList;


public:
    Library(string name="", string address="");
    int getId();
    string &getName();
    string &getAdddress();
    vector<Book *> &getBookList();
    void ajouter(Book * book);
    void supprimer(Book * book);
    void demander(string ISBN);
    void rendre(string ISBN);


};

#endif //BIBLIRESEAU_LIBRARY_H
