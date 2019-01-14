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
    string name;
    map<int,Library> libraryList;
    map<int,Member> memberList;
    map<int,Book> bookList;
    int member_menu();
    int library_menu();
    int member_authentificated_menu(Member member);
    int member_borrow_menu(Member member);
    int member_return_menu(Member member);
    int member_confirm_borrow_menu(Member member, Book book);

public:
    Network();
    int main_menu() ;
};


#endif //BIBLIRESEAU_NETWORK_H
