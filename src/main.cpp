#include "Book/Book.h"
#include "User/Library.h"
#include "User/Member.h"
#include <iostream>
using namespace std;


int main() {
	Library library1 = Library("MyFirstLibrary", "Ici");
	Library library2 = Library("La bilbliotheque d Alexandrie");
	Member mem1 = Member ("Toi");
	Member mem2 = Member ("Moi");
	Book book1 = Book("Le c++ pour les nuls");
	Book book2 = Book("Hello World");
	Book book3 = Book("Le prince");

	library1.buyBook(&book1);
	library1.buyBook(&book2);
    cout << library1 << endl;

	mem1.signIn(&library1);
	mem1.borrow(1);
    cout << mem1 << endl;
    cout << library1 << endl;
    cout << book1 << endl;

	return 0;
}
