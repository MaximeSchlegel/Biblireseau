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
    void member_menu();
    void member_authentificated_menu(Member member);
    void member_borrow_menu(Member member);
    void member_return_menu(Member member);
    void member_confirm_borrow_menu(Member member, Book book);
    void member_confirm_return_menu(Member member, Book book);
    void admin_menu();
    void admin_create_book();
    void admin_create_album();;
    void admin_create_comic();
    void admin_create_novel();
    void admin_create_play();
    void admin_create_poetry();
    void admin_create_library();
    void admin_create_member();
    void admin_confirm_create_book();
    void admin_confirm_create_library();
    void admin_confirm_create_member();
    void library_menu();
    void library_authentificated_menu(Library library);
    void buy_book_menu();
    void buy_Album_menu();
    void buy_Comic_menu ();
    void buy_Novel_menu ();
    void buy_Play_menu ();
    void buy_Poetry_memnu();

public:
    Network(string name);
    void main_menu() ;

    const string &getName() const;
    const map<int, Library> &getLibraryList() const;
    const map<int, Member> &getMemberList() const;
    const map<int, Book> &getBookList() const;
    void addLibrary(Library library);
    void addBook(Book book);
    void addMember(Member member)
};


#endif //BIBLIRESEAU_NETWORK_H
