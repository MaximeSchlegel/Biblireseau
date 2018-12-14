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
	Book book1 = Book("D'un monde a l'autre");
	Book book2 = Book("Les frontieres de glaces");
	Book book3 = Book("L'ile du destin");
    Book book4 = Book("La foret des captifs");
    Book book5 = Book("L'oeil d'otolep");
    Book book6 = Book("Les tentacules du mal");
    Book book7 = Book("Ellana");
    Book book8 = Book("L'envol");
    Book book9 = Book("La prophetie");

	library1.buyBook(&book1);
	library1.buyBook(&book2);
	library1.buyBook(&book3);
	library1.buyBook(&book4);
    cout << library1 << endl;

	mem1.setRegister(&library1);
	mem1.borrow(1);
	mem1.borrow(2);
	mem1.borrow(3);
//	mem1.borrow(4);
    cout << mem1 << endl;
    cout << library1 << endl;
    cout << book1 << endl;

    cout<< book9 << endl;

	return 0;
}
