#ifndef BIBLIRESEAU_NETWORK_H
#define BIBLIRESEAU_NETWORK_H


#include "../User/User.h"
#include "../User/Library.h"
#include "../User/Member.h"
#include "../Book/Book.h"
#include <map>
using namespace std;


class Network {
private:
    map<int,Library> libraryList;
    map<int,Member> memberList;
    map<int,Book> bookList;
    void main_menu() ;
    void member_menu();
    void library_menu();
    void member_authentificated_menu(Member member);
    void member_borrow_menu(Member member);
    void member_return_menu(Member member);
    void clear();

public:
    Network();
};


#endif //BIBLIRESEAU_NETWORK_H
