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
	Book book1 = Book("D'un monde a l'autre", "01");
	Book book2 = Book("Les frontieres de glaces", "02");
	Book book3 = Book("L'ile du destin", "03");
    Book book4 = Book("La foret des captifs", "04");
    Book book5 = Book("L'oeil d'otolep", "05");
    Book book6 = Book("Les tentacules du mal", "06");
    Book book7 = Book("Ellana", "07");
    Book book8 = Book("L'envol", "08");
    Book book9 = Book("La prophetie", "09");

	library1.buyBook(&book1);
	library1.buyBook(&book2);
	library1.buyBook(&book3);
	library1.buyBook(&book4);
	library1.buyBook(&book5);
    cout << library1 << endl;

    library2.buyBook(&book6);
    cout << library2 << endl;

	mem1.setRegister(&library1);
	mem1.borrowBook(1);
	mem1.borrowBook(2);
	mem1.borrowBook(3);
    cout << mem1 << endl;
    cout << library1 << endl;
    cout << book1 << endl;

    mem1.returnBook(1);
    cout<<book1;

    library1.askBook("06", &library2);
    cout << library1 << endl;
    cout << library2 << endl;

    library2.askBook("09", &library1);

	return 0;
}
